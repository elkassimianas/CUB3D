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

void		raycasthorzhelp(double nexthorztouchx, double nexthorztouchy)
{
	while (nexthorztouchx >= 0 && nexthorztouchx <= g_ray.win_w && nexthorztouchy>= 0 && nexthorztouchy <= g_ray.win_h)
	{
		if (haswallat(nexthorztouchx, nexthorztouchy - (g_ray.israyfacingup ? 1 : 0)))
		{
			g_ray.foundhorzwallhit = true;
			g_ray.horzwalhitx = nexthorztouchx;
			g_ray.horzwalhity = nexthorztouchy;
			break ;
		}
		else
		{
			nexthorztouchx += g_ray.xstep;
			nexthorztouchy += g_ray.ystep;
		}
	}
	return ;
}

void		raycasthorz(void)
{
	double		nexthorztouchx;
	double		nexthorztouchy;

	g_ray.foundhorzwallhit = false;
	g_ray.horzwalhitx = 0;
	g_ray.horzwalhity = 0;
	////////////////////////////////////////////
	//// HORIZONTAL g_ray-GRID INTERSECTION CODE //
	////////////////////////////////////////////
	/*find the y-coordinate of the closest horizontal map intersenction*/
	g_ray.yintercept = floor(g_player.yplayer / TILE_SIZE) * TILE_SIZE;
	g_ray.yintercept += g_ray.israyfacingdown ? TILE_SIZE : 0;
	/*find the x-coordinate of the closest horizontal map intersenction*/
	g_ray.xintercept = g_player.xplayer + ((g_ray.yintercept - g_player.yplayer) / tan(g_ray.angle));
	/*Calculate the increment xstep and ystep*/
	g_ray.ystep = TILE_SIZE;
	g_ray.ystep *= g_ray.israyfacingup ? -1 : 1;
	g_ray.xstep = TILE_SIZE / tan(g_ray.angle);
	g_ray.xstep *= (g_ray.israyfacingleft && g_ray.xstep > 0) ? -1 : 1;
	g_ray.xstep *= (g_ray.israyfacingright && g_ray.xstep < 0) ? -1 : 1;
	nexthorztouchx = g_ray.xintercept;
	nexthorztouchy = g_ray.yintercept;
	/*increment xstep and ystep untill we find a wall*/
	raycasthorzhelp(nexthorztouchx, nexthorztouchy);
	return ;
}

void		raycastverthelp(double nextverttouchx, double nextverttouchy)
{
	while (nextverttouchx >= 0 && nextverttouchx <= g_ray.win_w && nextverttouchy >= 0 && nextverttouchy <= g_ray.win_h)
	{
		if (haswallat(nextverttouchx - (g_ray.israyfacingleft ? 1 : 0), nextverttouchy))
		{
			g_ray.foundvertwallhit = true;
			g_ray.vertwalhitx = nextverttouchx;
			g_ray.vertwalhity = nextverttouchy;
			break ;
		}
		else
		{
			nextverttouchx += g_ray.xstep;
			nextverttouchy += g_ray.ystep;
		}
	}

	return ;
}

void		raycastvert()
{
	double		nextverttouchx;
	double		nextverttouchy;

	////////////////////////////////////////////
	//// VERTICAL g_ray-GRID INTERSECTION CODE //
	////////////////////////////////////////////
	g_ray.vertwalhitx = 0;
	g_ray.vertwalhity = 0;
	g_ray.foundvertwallhit = false;
	/*find the x-coordinate of the closest vartical map intersenction*/
	g_ray.xintercept = floor(g_player.xplayer / TILE_SIZE) * TILE_SIZE;
	g_ray.xintercept += g_ray.israyfacingright ? TILE_SIZE : 0;
	/*find the y-coordinate of the closest vertical map intersenction*/
	g_ray.yintercept = g_player.yplayer + ((g_ray.xintercept - g_player.xplayer) * tan(g_ray.angle));
	/*Calculate the increment xstep and ystep*/
	g_ray.xstep = TILE_SIZE;
	g_ray.xstep *= g_ray.israyfacingleft ? -1 : 1;
	g_ray.ystep = TILE_SIZE * tan(g_ray.angle);
	g_ray.ystep *= (g_ray.israyfacingup && g_ray.ystep > 0) ? -1 : 1;
	g_ray.ystep *= (g_ray.israyfacingdown && g_ray.ystep < 0) ? -1 : 1;
	nextverttouchx = g_ray.xintercept;
	nextverttouchy = g_ray.yintercept;
	/*increment xstep and ystep untill we find a wall*/
	raycastverthelp(nextverttouchx, nextverttouchy);
	return ;
}

void		castallg_rays(t_data *data)
{
	int		i;

	/*start first g_ray subtracting half of the fov*/
	g_ray.angle = data->rotationangle - (data->fov_angle / 2);
	i = -1;
	while (++i < g_ray.num_rays)
	{
		g_ray.angle = normalizeangle(g_ray.angle);
		g_ray.israyfacingdown = g_ray.angle > 0 && g_ray.angle < M_PI;
		g_ray.israyfacingup = !g_ray.israyfacingdown;
		g_ray.israyfacingright = g_ray.angle < 0.5 * M_PI || g_ray.angle > 1.5 * M_PI;
		g_ray.israyfacingleft = !g_ray.israyfacingright;
		g_ray1[i].rayfup = g_ray.israyfacingup;
		g_ray1[i].rayfright = g_ray.israyfacingright;
		raycasthorz();
		raycastvert();
		g_ray.horzhitdistance = (g_ray.foundhorzwallhit) ? distancebetweenpoints(g_player.xplayer, g_player.yplayer, g_ray.horzwalhitx, g_ray.horzwalhity) : INT_MAX;
        g_ray.verthitdistance = (g_ray.foundvertwallhit) ? distancebetweenpoints(g_player.xplayer, g_player.yplayer, g_ray.vertwalhitx, g_ray.vertwalhity) : INT_MAX;
		/*only store the smallest of the distances*/
		g_ray1[i].walhitx = (g_ray.horzhitdistance < g_ray.verthitdistance) ? g_ray.horzwalhitx : g_ray.vertwalhitx;
		g_ray1[i].walhity = (g_ray.horzhitdistance < g_ray.verthitdistance) ? g_ray.horzwalhity : g_ray.vertwalhity;
		g_ray1[i].distancestab = (g_ray.horzhitdistance < g_ray.verthitdistance) ? g_ray.horzhitdistance : g_ray.verthitdistance;
		// g_ray.distancestab[i] = g_ray.distance;
		g_ray1[i].fndvertwtx = (g_ray.horzhitdistance < g_ray.verthitdistance) ? 0 : 1;

		//rayspush(data, g_ray.walhitx * MINIMAP_SCALE_FACTOR, g_ray.walhity *
			//	MINIMAP_SCALE_FACTOR);
		g_ray1[i].angletab = g_ray.angle;
		g_ray.angle += data->fov_angle / g_ray.num_rays;
	}
	return ;
}
