/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 11:09:17 by ael-kass          #+#    #+#             */
/*   Updated: 2020/12/31 09:31:16 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	update()
{
	int		i = 0;
	
	mlx_hook(g_data.win, 2, 0, keypressed, (void*)0);
	mlx_hook(g_data.win, 3, 1, keyrelease, (void *)0);
	draw_new_map((void *)0);
	// map((void *)0);
	castallg_rays((void *)0);
	buffertexture((void *)0);
	render3dprojectedwalls((void *)0);
	map((void *)0);
	i = -1;
	while (++i < g_ray.num_rays)
		rayspush(g_ray1[i].walhitx * MINIMAP_SCALE_FACTOR, g_ray1[i].walhity * 
			MINIMAP_SCALE_FACTOR);
	mlx_put_image_to_window(g_data.mlx, g_data.win, g_data.img, 0, 0);
	return (0);
}

void	ft_readfile()
{
	int		a = 1;
	int		i;
	int b = 0;
	// int		x = 1;

	//argc > 3 || argc == 1 ? ft_print_errors(5) : argc;
	//if (argc == 3 && strncmp(av[2], "--save", 7))
	//	ft_print_errors(5);
	//if (ft_strrchr(av[1], '.') && !ft_strncmp(ft_strrchr(av[1], '.'), ".cub", 5))
	g_check.fd = open("map.cub", O_RDONLY);
	//else
	//	ft_print_errors(6);
	if (g_check.fd != -1)
	{
		// a = get_next_line(g_check.fd, &g_check.line);
		// if (a == 0)
		// 	ft_print_errors(0);
		while (b < 8)
		{
			a = get_next_line(g_check.fd, &g_check.line);
			while (g_check.line[0] == '\0')
			{
                if (a == 0)
					exit(1);
				a = get_next_line(g_check.fd, &g_check.line);
			}
			i = 0;
			while (g_check.line[i] == ' ')
            	i++;
			b = put_check(i, b);
			//x = get_next_line(g_check.fd, &g_check.line);
		}
		if (b == 8)
		{
			printf("%d\n", b);
			exit(1);
		}
		else
			ft_print_errors(2);
	}
	else
		ft_print_errors(7);
}

int	main()
{
	// t_data		data;
	g_data.mlx = mlx_init();

	ft_readfile();
	exit(EXIT_SUCCESS);

	
	g_ray.win_w = 15 * TILE_SIZE;
	g_ray.win_h = 11 * TILE_SIZE;
	g_ray.num_rays = g_ray.win_w / WALL_STRIP_WIDTH;
	//g_ray1[g_ray.num_rays] ;
	// g_texture.filenameup = "./images/txt64-3.xpm";
	// g_texture.filenamedown = "./images/txt64-2.xpm";
	// g_texture.filenameleft = "./images/txt64-4.xpm";
	// g_texture.filenameright = "./images/txt64-1.xpm";
	g_data.turndirection = 0;
	g_data.walkdirection = 0;
	g_data.rotationangle = M_PI_2;
	g_data.movespeed = 4;
	g_data.rotationspeed = 3 * (M_PI / 180);
	g_data.fov_angle = 60 * (M_PI / 180);
	g_player.xplayer = (15 * TILE_SIZE) / 2;
	g_player.yplayer = (11 * TILE_SIZE) / 2;
	g_data.mlx = mlx_init();
	g_data.win = mlx_new_window(g_data.mlx, g_ray.win_w, g_ray.win_h, "cub3D");
	g_data.img = mlx_new_image(g_data.mlx, g_ray.win_w, g_ray.win_h);
	g_data.addr = (int *)mlx_get_data_addr(g_data.img, &g_data.bits_per_pixel,
			&g_data.line_length, &g_data.endian);
	map();
	mlx_put_image_to_window(g_data.mlx, g_data.win, g_data.img, 0, 0);
	mlx_loop_hook(g_data.mlx, update, (void*) 0);
	mlx_loop(g_data.mlx);
}
