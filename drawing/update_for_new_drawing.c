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
		g_data.turndirection = -1;
	if (keycode == RIGHT)
		g_data.turndirection = 1;
	if (keycode == W)
		g_data.walkdirection = 1;
	if (keycode == S)
		g_data.walkdirection = -1;
	if (keycode == D)
		g_data.walkdirection_side = -1;
	if (keycode == A)
		g_data.walkdirection_side = 1;
	if (keycode == ESC)
	{
		exit (EXIT_SUCCESS);
	}
	return (0);
}

int		keyrelease(int keycode)
{
	if (keycode == LEFT || keycode == RIGHT)
		g_data.turndirection = 0;
	if (keycode == W || keycode == S)
		g_data.walkdirection = 0;
	if (keycode == D || keycode == A)
		g_data.walkdirection_side = 0;
	return (0);
}

int		quit_win()
{
	int		len;

	len = len_of_line(g_data.map);
	ft_free1(g_data.map, len);
	mlx_destroy_window(g_data.mlx, g_data.win);
	exit (1);
	return (0);
}

int		haswallat(double x, double y)
{
	int		mapindex_x;
	int		mapindex_y;

	if (x < 0 || x >= g_p.len * TILE_SIZE|| y < 0 || y >= g_p.inc * TILE_SIZE)
		return (1);
	mapindex_x = floor(x / TILE_SIZE);
	mapindex_y = floor(y / TILE_SIZE);
	if (g_data.map[mapindex_y][mapindex_x] == '1')
		return (1);
	return (0);
}

void		draw_new_map()
{
	float		movestep;
	float		newplayerx = 0;
	float		newplayery = 0;

	g_data.rotationangle += g_data.turndirection * g_data.rotationspeed;
	if (g_data.walkdirection != 0)
	{
		movestep = g_data.walkdirection * g_data.movespeed;
		newplayerx = g_player.xplayer + cos(g_data.rotationangle) * movestep;
		newplayery = g_player.yplayer + sin(g_data.rotationangle) * movestep;
	}
	if (g_data.walkdirection_side != 0)
	{
		movestep = g_data.walkdirection_side * g_data.movespeed;
		newplayerx = g_player.xplayer + cos(g_data.rotationangle - M_PI_2) * movestep;
		newplayery = g_player.yplayer + sin(g_data.rotationangle - M_PI_2) * movestep;
	}
	if (!haswallat(newplayerx, newplayery))
	{
		g_player.xplayer = newplayerx;
		g_player.yplayer = newplayery;
	}
	g_tilecolor = 0xFF0000;
}
