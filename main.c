/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 11:09:17 by ael-kass          #+#    #+#             */
/*   Updated: 2020/12/04 10:23:34 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	update(t_data *data)
{
	int		i = 0;
	
	mlx_hook(data->win, 2, 0, keypressed, data);
	mlx_hook(data->win, 3, 1, keyrelease, data);
	draw_new_map(data);
	// map(data);
	castallg_rays(data);
	buffertexture(data);
	render3dprojectedwalls(data);
	map(data);
	i = -1;
	while (++i < g_ray.num_rays)
		rayspush(data, g_ray1[i].walhitx * MINIMAP_SCALE_FACTOR, g_ray1[i].walhity * 
			MINIMAP_SCALE_FACTOR);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

void	ft_readfile()
{
	int		a = 1;

	g_check.fd = open("map.cub", O_RDONLY);
	if (g_check.fd != -1)
	{
		a = get_next_line(g_check.fd, &g_check.line);
		a == 0 ? ft_print_errors("you need to put all the element of the file\n") : a;
		put_check(a);
	}
	else
		ft_print_errors("in the file Name\n");
}

int	main(void)
{
	t_data		data;

	ft_readfile();
	exit(EXIT_SUCCESS);

	
	g_ray.win_w = 15 * TILE_SIZE;
	g_ray.win_h = 11 * TILE_SIZE;
	g_ray.num_rays = g_ray.win_w / WALL_STRIP_WIDTH;
	// g_ray1[g_ray.num_rays];
	g_texture.filenameup = "./images/txt64-3.xpm";
	g_texture.filenamedown = "./images/txt64-2.xpm";
	g_texture.filenameleft = "./images/txt64-4.xpm";
	g_texture.filenameright = "./images/txt6 4-1.xpm";
	data.turndirection = 0;
	data.walkdirection = 0;
	data.rotationangle = M_PI_2;
	data.movespeed = 4;
	data.rotationspeed = 3 * (M_PI / 180);
	data.fov_angle = 60 * (M_PI / 180);
	g_player.xplayer = (15 * TILE_SIZE) / 2;
	g_player.yplayer = (11 * TILE_SIZE) / 2;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, g_ray.win_w, g_ray.win_h, "cub3D");
	data.img = mlx_new_image(data.mlx, g_ray.win_w, g_ray.win_h);
	data.addr = (int *)mlx_get_data_addr(data.img, &data.bits_per_pixel,
			&data.line_length, &data.endian);
	map(&data);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_loop_hook(data.mlx, update, &data);
	mlx_loop(data.mlx);
}
