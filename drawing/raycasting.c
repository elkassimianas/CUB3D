/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 12:19:31 by ael-kass          #+#    #+#             */
/*   Updated: 2021/02/13 18:26:45 by ael-kass         ###   ########.fr       */
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
			g_r.hzhitx = next_hz_x;
			g_r.hzhity = next_hz_y;
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
	g_r.hzhitx = 0;
	g_r.hzhity = 0;
	g_r.yintercept = floor(g_pl.y_p / TL_SZ) * TL_SZ;
	g_r.yintercept += g_r.israyfacingdown ? TL_SZ : 0;
	g_r.xintercept = g_pl.x_p + ((g_r.yintercept - g_pl.y_p) / tan(g_r.angle));
	g_r.ystep = TL_SZ;
	g_r.ystep *= g_r.israyfacingup ? -1 : 1;
	g_r.xstep = TL_SZ / tan(g_r.angle);
	g_r.xstep *= (g_r.israyfacingleft && g_r.xstep > 0) ? -1 : 1;
	g_r.xstep *= (g_r.israyfacingright && g_r.xstep < 0) ? -1 : 1;
	next_hz_x = g_r.xintercept;
	next_hz_y = g_r.yintercept;
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
			g_r.vrhity = next_vert_y;
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

void		raycastvert(void)
{
	double		next_vert_x;
	double		next_vert_y;

	g_r.vr_hi_x = 0;
	g_r.vrhity = 0;
	g_r.fnd_vrt_hit = false;
	g_r.xintercept = floor(g_pl.x_p / TL_SZ) * TL_SZ;
	g_r.xintercept += g_r.israyfacingright ? TL_SZ : 0;
	g_r.yintercept = g_pl.y_p + ((g_r.xintercept - g_pl.x_p) * tan(g_r.angle));
	g_r.xstep = TL_SZ;
	g_r.xstep *= g_r.israyfacingleft ? -1 : 1;
	g_r.ystep = TL_SZ * tan(g_r.angle);
	g_r.ystep *= (g_r.israyfacingup && g_r.ystep > 0) ? -1 : 1;
	g_r.ystep *= (g_r.israyfacingdown && g_r.ystep < 0) ? -1 : 1;
	next_vert_x = g_r.xintercept;
	next_vert_y = g_r.yintercept;
	raycastverthelp(next_vert_x, next_vert_y);
	return ;
}

void		castallg_rs(int i)
{
	g_r.angle = g_dt.ro_angle - (g_dt.fov_angle / 2);
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
		g_r.hzhitdis = (g_r.fnd_hz_hit) ?
		disbet_p(g_pl.x_p, g_pl.y_p, g_r.hzhitx, g_r.hzhity) : INT_MAX;
        g_r.vrhitdis = (g_r.fnd_vrt_hit) ?
		disbet_p(g_pl.x_p, g_pl.y_p, g_r.vr_hi_x, g_r.vrhity) : INT_MAX;
		g_r1[i].w_hitx = (g_r.hzhitdis < g_r.vrhitdis) ? g_r.hzhitx : g_r.vr_hi_x;
		g_r1[i].w_hity = (g_r.hzhitdis < g_r.vrhitdis) ? g_r.hzhity : g_r.vrhity;
		g_r1[i].dis_t = (g_r.hzhitdis < g_r.vrhitdis) ? g_r.hzhitdis : g_r.vrhitdis;
		g_r1[i].fndvertwtx = (g_r.hzhitdis < g_r.vrhitdis) ? 0 : 1;
		g_r1[i].anglet = g_r.angle;
		g_r.angle += g_dt.fov_angle / g_r.num_rays;
	}
}

