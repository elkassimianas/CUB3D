/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 13:25:39 by ael-kass          #+#    #+#             */
/*   Updated: 2020/12/05 14:46:06 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double		normalizeangle(double angle)
{
	angle = (angle - (int)(angle / (2 * M_PI)) * (2 * M_PI));
	if (angle < 0)
		angle += (2 * M_PI);
	return (angle);
}

void		rayspush(double x2, double y2)
{
	double		y1;
	double		x1;
	double		xinc;
	double		yinc;
	int			steps;

	x1 = g_player.xplayer * MINIMAP_SCALE_FACTOR;
	y1 = g_player.yplayer * MINIMAP_SCALE_FACTOR;
	g_tilecolor = 0xFF4500;
	steps = abs((int)x2 - (int)x1) > abs((int)y2 - (int)y1) ? abs((int)x2 -
			(int)x1) : abs((int)y2 - (int)y1);
	xinc = (x2 - x1) / (double)steps;
	yinc = (y2 - y1) / (double)steps;
	x2 = -1;
	while (++x2 <= steps)
	{
		if (y1 >= 0 && x1 >= 0 && x1 < g_ray.win_w && y1 < g_ray.win_h)
			g_data.addr[(int)y1 * g_ray.win_w + (int)x1] = g_tilecolor;
		x1 = x1 + xinc;
		y1 = y1 + yinc;
	}
	return ;
}

double		distancebetweenpoints(double x1, double y1, double x2, double y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void			drawing_walls3d(double x, double y, double tile_z1)
{
	double		x1;
	double		y1;

	x1 = WALL_STRIP_WIDTH + x;
	y1 = tile_z1 + y;
	g_tilecolor = 0xFFFFFF;
	while (y < y1)
	{
		while (x < x1)
		{
			if (y >= 0 && x >= 0 && x < g_ray.win_w && y < g_ray.win_h)
				g_data.addr[((int)y * g_ray.win_w) + (int)x] = g_tilecolor;
			x++;
		}
		x -= WALL_STRIP_WIDTH;
		y++;
	}
	return ;
}

void		render3dprojectedwalls()
{
	int			i;
	int			y;
	int			a;
	int			distancefromtop;
	unsigned int long	color;

	/*loop every g_ray in the arg_ray of g_rays*/
	i = -1;
	while (++i < g_ray.num_rays)
	{
		//cowalldistance = g_ray1[i].distancestab;
		/*"cos(angle - g_data.rotationangle)" get the perpendicular distance to the wall to fix Fishbowl distortion*/
		g_render3d.cowalldistance = g_ray1[i].distancestab * cos(g_ray1[i].angletab - g_data.rotationangle);
		/*calculate the distance to the projection plane*/
		g_render3d.distanceprojectionplane = (g_ray.win_w / 2) / tan(g_data.fov_angle / 2);
		/*projected wall height*/
		g_render3d.wallstripheight = (TILE_SIZE / g_render3d.cowalldistance) * g_render3d.distanceprojectionplane;
		g_render3d.walltoppixel = (g_ray.win_h / 2) - (g_render3d.wallstripheight / 2);
		g_render3d.walltoppixel = g_render3d.walltoppixel < 0 ? 0 : g_render3d.walltoppixel;
		g_render3d.wa_btm_pxl = (g_ray.win_h / 2) + (g_render3d.wallstripheight / 2);
		//g_render3d.wa_btm_pxl = g_render3d.walltoppixel + g_render3d.wallstripheight; 
		g_render3d.wa_btm_pxl = g_render3d.wa_btm_pxl > g_ray.win_h ? g_ray.win_h : g_render3d.wa_btm_pxl;
		
		// set the color of the ceiling
		y = 0;
		while (y < g_render3d.walltoppixel)
		{
			g_data.addr[(y * g_ray.win_w) + i] = 0x9bc8de;
			y++;
		}
		//drawing_walls3d(data, i, g_render3d.walltoppixel, g_render3d.wallstripheight);

		// calculate textureOffsetX
		if (g_ray1[i].fndvertwtx)
		{
			// perform offset for the verticel hit
			g_tex.offsetx = (int)g_ray1[i].walhity % TILE_SIZE;
		}
		else{
			// perform offset for the horizontal hit
			g_tex.offsetx = (int)g_ray1[i].walhitx % TILE_SIZE;
		}

		if (g_ray1[i].rayfup && !g_ray1[i].fndvertwtx)
			a = 0;
		else if (!g_ray1[i].fndvertwtx && !g_ray1[i].rayfup)
			a = 1;
		else if (!g_ray1[i].rayfright && g_ray1[i].fndvertwtx)
			a = 2;
		else if (g_ray1[i].rayfright && g_ray1[i].fndvertwtx)
			a = 3;
		// render the wall from walltoppixel to wallbottompixel
		y = g_render3d.walltoppixel;
		while (y < g_render3d.wa_btm_pxl)
		{
			// calculate textureOffsetY
			distancefromtop = y + (g_render3d.wallstripheight / 2) - (g_ray.win_h / 2);
			g_tex.offsety = distancefromtop * ((double)TEXTURE_HEIGHT / g_render3d.wallstripheight);
			g_tex.offsety = g_tex.offsety >= TILE_SIZE ? TILE_SIZE - 1 : g_tex.offsety;
			// set the color of wall based on the color from the texture
			//printf("%d" , (TEXTURE_WIDTH * g_tex.offsety) + g_tex.offsetx);
			color = g_tex.addr[a][(TEXTURE_WIDTH * g_tex.offsety) + g_tex.offsetx];
		//	printf("%zu\n", g_tilecolor);
			g_data.addr[(y * g_ray.win_w) + i] = color;
			y++;
		}
		// set the color of the floor
		y = g_render3d.wa_btm_pxl;
		while (y < g_ray.win_h)
		{
			g_data.addr[(y * g_ray.win_w) + i] = 0x5f5a39;
			y++;
		}
	}
	return ;
}