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

int	    map1[11][15] = {{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                   	   {1,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
                   	   {1,0,0,1,0,1,0,0,0,1,0,0,1,0,1},
                   	   {1,1,1,1,1,0,0,0,0,0,1,0,1,0,1},
                   	   {1,0,0,0,0,0,0,0,0,0,1,0,1,0,1},
                   	   {1,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
                   	   {1,0,0,1,1,1,1,1,1,1,1,1,0,0,1},
            	   	   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                   	   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                   	   {1,0,0,0,0,0,0,1,0,0,0,0,0,0,1},
                   	   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};

int		keypressed(int keycode, t_data *data)
{
	if (keycode == LEFT)
		data->turndirection = -1;
	if (keycode == RIGHT)
		data->turndirection = 1;
	if (keycode == W)
		data->walkdirection = 1;
	if (keycode == S)
		data->walkdirection = -1;
	return (0);
}

int		keyrelease(int keycode, t_data *data)
{
	if (keycode == LEFT || keycode == RIGHT)
		data->turndirection = 0;
	if (keycode == W || keycode == S)
		data->walkdirection = 0;
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
	if (map1[mapindex_y][mapindex_x] != 0)
		return (1);
	return (0);
}

void		draw_new_map(t_data *data)
{
	float		movestep;
	float		newplayerx;
	float		newplayery;

	mlx_clear_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, g_ray.win_w, g_ray.win_h);
	data->addr = (int *)mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	data->rotationangle += data->turndirection * data->rotationspeed;
	movestep = data->walkdirection * data->movespeed;
	newplayerx = g_player.xplayer + cos(data->rotationangle) * movestep;
	newplayery = g_player.yplayer + sin(data->rotationangle) * movestep;
	if (!haswallat(newplayerx, newplayery))
	{
		g_player.xplayer = newplayerx;
		g_player.yplayer = newplayery;
	}
	g_tilecolor = 0xFF0000;
}
