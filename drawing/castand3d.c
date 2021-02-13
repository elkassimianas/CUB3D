/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 13:25:39 by ael-kass          #+#    #+#             */
/*   Updated: 2021/02/13 17:50:50 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double		disbet_p(double x1, double y1, double x2, double y2)
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

	y = 0;
	while (y < g_rd.wall_top)
	{
		color = create_trgb(g_tex.rc, g_tex.gc, g_tex.bc);
		g_dt.addr[(y * g_dt.win_w) + i] = color;
		y++;
	}
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
	g_rd.cowal_dis = g_r1[i].dis_t * cos(g_r1[i].anglet - g_dt.ro_angle);
	g_rd.dis_proj_plan = (g_dt.win_w / 2) / tan(g_dt.fov_angle / 2);
	if (g_rd.cowal_dis == 0)
		g_rd.cowal_dis = 0.2;
	g_rd.w_strip_h = (TL_SZ / g_rd.cowal_dis) * g_rd.dis_proj_plan;
	g_rd.wall_top = (g_dt.win_h / 2) - (g_rd.w_strip_h / 2);
	g_rd.wall_top = g_rd.wall_top < 0 ? 0 : g_rd.wall_top;
	g_rd.wa_bmt = (g_dt.win_h / 2) + (g_rd.w_strip_h / 2);
	g_rd.wa_bmt = g_rd.wall_top + g_rd.w_strip_h;
	g_rd.wa_bmt = g_rd.wa_bmt > g_dt.win_h ? g_dt.win_h : g_rd.wa_bmt;
	if (g_r1[i].fndvertwtx)
		g_tex.offsetx = (int)g_r1[i].w_hity % TL_SZ;
	else
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

void		render3dprojectedwalls(void)
{
	int					i;
	int					y;
	int					a;
	int					distancefromtop;
	unsigned int long	color;

	i = -1;
	while (++i < g_r.num_rays)
	{
		a = ft_math_utils(i, a);
		y = g_rd.wall_top;
		while (y < g_rd.wa_bmt)
		{
			distancefromtop = y + (g_rd.w_strip_h / 2) - (g_dt.win_h / 2);
			g_tex.offsety = distancefromtop * ((double)TL_SZ / g_rd.w_strip_h);
			g_tex.offsety = g_tex.offsety >= TL_SZ ? TL_SZ - 1 : g_tex.offsety;
			color = g_tex.addr[a][(TL_SZ * g_tex.offsety) + g_tex.offsetx];
			g_dt.addr[(y * g_dt.win_w) + i] = color;
			y++;
		}
		ft_floor_ceilling(i);
	}
	return ;
}
