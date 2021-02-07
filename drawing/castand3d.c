/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 13:25:39 by ael-kass          #+#    #+#             */
/*   Updated: 2021/02/07 16:30:11 by ael-kass         ###   ########.fr       */
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

	x1 = g_pl.x_p * MINIMAP_SCALE_FACTOR;
	y1 = g_pl.y_p * MINIMAP_SCALE_FACTOR;
	g_tilecolor = 0xFF4500;
	steps = abs((int)x2 - (int)x1) > abs((int)y2 - (int)y1) ? abs((int)x2 -
			(int)x1) : abs((int)y2 - (int)y1);
	xinc = (x2 - x1) / (double)steps;
	yinc = (y2 - y1) / (double)steps;
	x2 = -1;
	while (++x2 <= steps)
	{
		if (y1 >= 0 && x1 >= 0 && x1 < g_dt.win_w && y1 < g_dt.win_h)
			g_dt.addr[(int)y1 * g_dt.win_w + (int)x1] = g_tilecolor;
		x1 = x1 + xinc;
		y1 = y1 + yinc;
	}
	return ;
}

double		dis_bet_points(double x1, double y1, double x2, double y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void		drawing_walls3d(double x, double y, double tile_z1)
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
			if (y >= 0 && x >= 0 && x < g_dt.win_w && y < g_dt.win_h)
				g_dt.addr[((int)y * g_dt.win_w) + (int)x] = g_tilecolor;
			x++;
		}
		x -= WALL_STRIP_WIDTH;
		y++;
	}
	return ;
}

void		ft_floor_ceilling(int i)
{
		unsigned int	color;
		int				y;
		
		/*set the color of the ceiling*/
		y = 0;
		while (y < g_rd.wall_top)
		{
			color = create_trgb(g_tex.rc, g_tex.gc, g_tex.bc);
			g_dt.addr[(y * g_dt.win_w) + i] = color;
			y++;
		}
		/*set the color of the floor*/
		y = g_rd.wa_bmt;
		while (y < g_dt.win_h)
		{
			color = create_trgb(g_tex.rf, g_tex.gf, g_tex.bf);
			g_dt.addr[(y * g_dt.win_w) + i] = color;
			y++;
		}
}

int			ft_math_utils(int i, int a)
{
	/*"cos(angle - g_dt.ro_angle)" get the perpendicular distance to the wall to fix Fishbowl distortion*/
	g_rd.cowal_dis = g_r1[i].dis_t * cos(g_r1[i].anglet - g_dt.ro_angle);
	/*calculate the distance to the projection plane*/
	g_rd.dis_proj_plan = (g_dt.win_w / 2) / tan(g_dt.fov_angle / 2);
	/*projected wall height*/
	if (g_rd.cowal_dis == 0)
		g_rd.cowal_dis = 0.2;
	g_rd.w_strip_h = (TL_SZ / g_rd.cowal_dis) * g_rd.dis_proj_plan;
	g_rd.wall_top = (g_dt.win_h / 2) - (g_rd.w_strip_h / 2);
	g_rd.wall_top = g_rd.wall_top < 0 ? 0 : g_rd.wall_top;
	g_rd.wa_bmt = (g_dt.win_h / 2) + (g_rd.w_strip_h / 2);
	g_rd.wa_bmt = g_rd.wall_top + g_rd.w_strip_h; 
	g_rd.wa_bmt = g_rd.wa_bmt > g_dt.win_h ? g_dt.win_h : g_rd.wa_bmt;
	/* calculate textureOffsetX*/
	if (g_r1[i].fndvertwtx)
		/*perform offset for the verticel hit*/
		g_tex.offsetx = (int)g_r1[i].w_hity % TL_SZ;
	else
		/*perform offset for the horizontal hit*/
		g_tex.offsetx = (int)g_r1[i].w_hitx % TL_SZ;
	if (g_r1[i].rayfup && !g_r1[i].fndvertwtx)
		a = 0;
	if (!g_r1[i].fndvertwtx && !g_r1[i].rayfup)
		a = 1;
	if (!g_r1[i].rayfright && g_r1[i].fndvertwtx)
		a = 2;
	if (g_r1[i].rayfright && g_r1[i].fndvertwtx)
		a = 3;
	return (a);
}

void		render3dprojectedwalls()
{
	int					i;
	int					y;
	int					a;
	int					distancefromtop;
	unsigned int long	color;
	/*loop every g_r in the arg_r of g_rs*/
	i = -1;
	while (++i < g_r.num_rays)
	{
		a = ft_math_utils(i, a);
		/*render the wall from walltoppixel to wallbottompixel*/
		y = g_rd.wall_top;
		while (y < g_rd.wa_bmt)
		{
			/*calculate textureOffsetY*/
			distancefromtop = y + (g_rd.w_strip_h / 2) - (g_dt.win_h / 2);
			g_tex.offsety = distancefromtop * ((double)TL_SZ / g_rd.w_strip_h);
			g_tex.offsety = g_tex.offsety >= TL_SZ ? TL_SZ - 1 : g_tex.offsety;
			/*set the color of wall based on the color from the texture*/
			color = g_tex.addr[a][(TL_SZ * g_tex.offsety) + g_tex.offsetx];
			g_dt.addr[(y * g_dt.win_w) + i] = color;
			y++;
		}
		ft_floor_ceilling(i);
	}
	return ;
}