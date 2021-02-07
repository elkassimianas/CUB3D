/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 12:19:31 by ael-kass          #+#    #+#             */
/*   Updated: 2020/12/06 16:51:44 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		raycasthorzhelp(double next_hz_x, double next_hz_y)
{
	while (next_hz_x >= 0 && next_hz_x <= g_dt.img_w && next_hz_y >= 0
		&& next_hz_y <= g_dt.img_h)
	{
		if (haswallat(next_hz_x, next_hz_y - (g_r.israyfacingup ? 1 : 0)))
		{
			g_r.fnd_hz_hit = true;
			g_r.hz_hit_x = next_hz_x;
			g_r.hz_hit_y = next_hz_y;
			break ;
		}
		else
		{
			next_hz_x += g_r.xstep;
			next_hz_y += g_r.ystep;
		}
	}
	return ;
}

void		raycasthorz(void)
{
	double		next_hz_x;
	double		next_hz_y;

	g_r.fnd_hz_hit = false;
	g_r.hz_hit_x = 0;
	g_r.hz_hit_y = 0;
	////////////////////////////////////////////
	//// HORIZONTAL g_r-GRID INTERSECTION CODE //
	//////////////////////////////////////////// 
	/*find the y-coordinate of the closest horizontal map intersenction*/
	g_r.yintercept = floor(g_pl.y_p / TL_SZ) * TL_SZ;
	g_r.yintercept += g_r.israyfacingdown ? TL_SZ : 0;
	/*find the x-coordinate of the closest horizontal map intersenction*/
	g_r.xintercept = g_pl.x_p + ((g_r.yintercept - g_pl.y_p) / tan(g_r.angle));
	/*Calculate the increment xstep and ystep*/
	g_r.ystep = TL_SZ;
	g_r.ystep *= g_r.israyfacingup ? -1 : 1;
	g_r.xstep = TL_SZ / tan(g_r.angle);
	g_r.xstep *= (g_r.israyfacingleft && g_r.xstep > 0) ? -1 : 1;
	g_r.xstep *= (g_r.israyfacingright && g_r.xstep < 0) ? -1 : 1;
	next_hz_x = g_r.xintercept;
	next_hz_y = g_r.yintercept;
	/*increment xstep and ystep untill we find a wall*/
	raycasthorzhelp(next_hz_x, next_hz_y);
	return ;
}

void		raycastverthelp(double next_vert_x, double next_vert_y)
{
	while (next_vert_x >= 0 && next_vert_x <= g_dt.img_w && next_vert_y >= 0
		&& next_vert_y <= g_dt.img_h)
	{
		if (haswallat(next_vert_x - (g_r.israyfacingleft ? 1 : 0), next_vert_y))
		{
			g_r.fnd_vrt_hit = true;
			g_r.vr_hi_x = next_vert_x;
			g_r.vrt_hit_y = next_vert_y;
			break ;
		}
		else
		{
			next_vert_x += g_r.xstep;
			next_vert_y += g_r.ystep;
		}
	}

	return ;
}

void		raycastvert()
{
	double		next_vert_x;
	double		next_vert_y;

	////////////////////////////////////////////
	//// VERTICAL g_r-GRID INTERSECTION CODE //
	////////////////////////////////////////////
	g_r.vr_hi_x = 0;
	g_r.vrt_hit_y = 0;
	g_r.fnd_vrt_hit = false;
	/*find the x-coordinate of the closest vartical map intersenction*/
	g_r.xintercept = floor(g_pl.x_p / TL_SZ) * TL_SZ;
	g_r.xintercept += g_r.israyfacingright ? TL_SZ : 0;
	/*find the y-coordinate of the closest vertical map intersenction*/
	g_r.yintercept = g_pl.y_p + ((g_r.xintercept - g_pl.x_p) * tan(g_r.angle));
	/*Calculate the increment xstep and ystep*/
	g_r.xstep = TL_SZ;
	g_r.xstep *= g_r.israyfacingleft ? -1 : 1;
	g_r.ystep = TL_SZ * tan(g_r.angle);
	g_r.ystep *= (g_r.israyfacingup && g_r.ystep > 0) ? -1 : 1;
	g_r.ystep *= (g_r.israyfacingdown && g_r.ystep < 0) ? -1 : 1;
	next_vert_x = g_r.xintercept;
	next_vert_y = g_r.yintercept;
	/*increment xstep and ystep untill we find a wall*/
	raycastverthelp(next_vert_x, next_vert_y);
	return ;
}

void		castallg_rs()
{
	int		i;

	/*start first g_r subtracting half of the fov*/
	g_r.angle = g_dt.ro_angle - (g_dt.fov_angle / 2);
	i = -1;
	while (++i < g_r.num_rays)
	{
		g_r.angle = normalizeangle(g_r.angle);
		g_r.israyfacingdown = g_r.angle > 0 && g_r.angle < M_PI;
		g_r.israyfacingup = !g_r.israyfacingdown;
		g_r.israyfacingright = g_r.angle < 0.5 * M_PI || g_r.angle > 1.5 * M_PI;
		g_r.israyfacingleft = !g_r.israyfacingright;
		g_r1[i].rayfup = g_r.israyfacingup;
		g_r1[i].rayfright = g_r.israyfacingright;
		raycasthorz();
		raycastvert();
		g_r.hz_hit_dis = (g_r.fnd_hz_hit) ?
		dis_bet_points(g_pl.x_p, g_pl.y_p, g_r.hz_hit_x, g_r.hz_hit_y) : INT_MAX;
        g_r.vrt_hit_dis = (g_r.fnd_vrt_hit) ?
		dis_bet_points(g_pl.x_p, g_pl.y_p, g_r.vr_hi_x, g_r.vrt_hit_y) : INT_MAX;
		/*only store the smallest of the distances*/
		g_r1[i].w_hitx = (g_r.hz_hit_dis < g_r.vrt_hit_dis) ?
		g_r.hz_hit_x : g_r.vr_hi_x;
		g_r1[i].w_hity = (g_r.hz_hit_dis < g_r.vrt_hit_dis) ?
		g_r.hz_hit_y : g_r.vrt_hit_y;
		g_r1[i].dis_t = (g_r.hz_hit_dis < g_r.vrt_hit_dis) ?
		g_r.hz_hit_dis : g_r.vrt_hit_dis;
		g_r1[i].fndvertwtx = (g_r.hz_hit_dis < g_r.vrt_hit_dis) ? 0 : 1;
		g_r1[i].anglet = g_r.angle;
		g_r.angle += g_dt.fov_angle / g_r.num_rays;
	}
	return ;
}


int		create_trgb(int r, int g, int b)
{
	return(r << 16 | g << 8 | b);
}