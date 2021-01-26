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

// int	    map1[11][15] = {{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//                    	   {1,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
//                    	   {1,0,0,1,0,1,0,0,0,1,0,0,1,0,1},
//                    	   {1,1,1,1,1,0,0,0,0,0,1,0,1,0,1},
//                    	   {1,0,0,0,0,0,0,0,0,0,1,0,1,0,1},
//                    	   {1,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
//                    	   {1,0,0,1,1,1,1,1,1,1,1,1,0,0,1},
//             	   	   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//                    	   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//                    	   {1,0,0,0,0,0,0,1,0,0,0,0,0,0,1},
//                    	   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};

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
	return (0);
}

int		keyrelease(int keycode)
{
	if (keycode == LEFT || keycode == RIGHT)
		g_data.turndirection = 0;
	if (keycode == W || keycode == S)
		g_data.walkdirection = 0;
	return (0);
}

int		haswallat(double x, double y)
{
	int		mapindex_x;
	int		mapindex_y;

	if (x < 0 || x > g_ray.win_w || y < 0 || y > g_ray.win_h)
		return (1);
	mapindex_x = floor(x / TILE_SIZE);
	mapindex_y = floor(y / TILE_SIZE);
	//printf("map_x:%d\nmap_y:%d\n", mapindex_x, mapindex_y);
	if (g_data.map[mapindex_y][mapindex_x] == '1')
		return (1);
	return (0);
}

void		draw_new_map()
{
	float		movestep;
	float		newplayerx = 0;
	float		newplayery = 0;

	// mlx_clear_window(g_data.mlx, g_data.win);
	// mlx_destroy_image(g_data.mlx, g_data.img);
	// g_data.img = mlx_new_image(g_data.mlx, g_ray.win_w, g_ray.win_h);
	// g_data.addr = (int *)mlx_get_data_addr(g_data.img, &g_data.bits_per_pixel,
	// 		&g_data.line_length, &g_data.endian);
	g_data.rotationangle += g_data.turndirection * g_data.rotationspeed;
	movestep = g_data.walkdirection * g_data.movespeed;
	newplayerx = g_player.xplayer + cos(g_data.rotationangle) * movestep;
	newplayery = g_player.yplayer + sin(g_data.rotationangle) * movestep;
	if (!haswallat(newplayerx, newplayery))
	{
		g_player.xplayer = newplayerx;
		g_player.yplayer = newplayery;
	}
	g_tilecolor = 0xFF0000;
}
