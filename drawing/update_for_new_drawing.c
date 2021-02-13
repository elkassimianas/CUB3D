/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_for_new_drawing.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 13:23:26 by ael-kass          #+#    #+#             */
/*   Updated: 2020/12/06 17:01:31 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		keypressed(int keycode)
{
	if (keycode == LEFT)
		g_dt.turndirection = -1;
	if (keycode == RIGHT)
		g_dt.turndirection = 1;
	if (keycode == W)
		g_dt.walkdirection = 1;
	if (keycode == S)
		g_dt.walkdirection = -1;
	if (keycode == D)
		g_dt.walkdirection_side = -1;
	if (keycode == A)
		g_dt.walkdirection_side = 1;
	if (keycode == ESC)
		exit (EXIT_SUCCESS);
	return (0);
}

int		keyrelease(int keycode)
{
	if (keycode == LEFT || keycode == RIGHT)
		g_dt.turndirection = 0;
	if (keycode == W || keycode == S)
		g_dt.walkdirection = 0;
	if (keycode == D || keycode == A)
		g_dt.walkdirection_side = 0;
	return (0);
}

int		quit_win()
{
	int		len;

	len = len_of_line(g_dt.map);
	ft_free1(g_dt.map, len);
	mlx_destroy_window(g_dt.mlx, g_dt.win);
	exit (1);
	return (0);
}

int		haswallat(double x, double y)
{
	int		mapindex_x;
	int		mapindex_y;

	if (x < 0 || x >= g_dt.img_w || y < 0 || y >= g_dt.img_h)
		return (1);
	mapindex_x = floor(x / TL_SZ);
	mapindex_y = floor(y / TL_SZ);
	if (g_dt.map[mapindex_y][mapindex_x] == '1')
		return (1);
	return (0);
}

void		draw_new_map()
{
	float		movestep;
	float		newplayerx = 0;
	float		newplayery = 0;

	g_dt.ro_angle += g_dt.turndirection * g_dt.rotationspeed;
	if (g_dt.walkdirection != 0)
	{
		movestep = g_dt.walkdirection * g_dt.movespeed;
		newplayerx = g_pl.x_p + cos(g_dt.ro_angle) * movestep;
		newplayery = g_pl.y_p + sin(g_dt.ro_angle) * movestep;
	}
	if (g_dt.walkdirection_side != 0)
	{
		movestep = g_dt.walkdirection_side * g_dt.movespeed;
		newplayerx = g_pl.x_p + cos(g_dt.ro_angle - M_PI_2) * movestep;
		newplayery = g_pl.y_p + sin(g_dt.ro_angle - M_PI_2) * movestep;
	}
	if (!haswallat(newplayerx, newplayery))
	{
		g_pl.x_p = newplayerx;
		g_pl.y_p = newplayery;
	}
	g_tilecolor = 0xFF0000;
}