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
	draw_new_map();
	// map((void *)0);
	castallg_rays();
	buffertexture();
	render3dprojectedwalls();
	map();
	i = -1;
	while (++i < g_ray.num_rays)
		rayspush(g_ray1[i].walhitx * MINIMAP_SCALE_FACTOR, g_ray1[i].walhity * 
			MINIMAP_SCALE_FACTOR);
	mlx_put_image_to_window(g_data.mlx, g_data.win, g_data.img, 0, 0);
	return (0);
}

void	ft_readfile()
{
	int		a;
	int		i;
	int 	b;

	a = 1;
	b = 0;
	// argc > 3 || argc == 1 ? ft_print_errors(5) : argc;
	// if (argc == 3 && strncmp(av[2], "--save", 7))
	// 	ft_print_errors(5);
	//if (ft_strrchr(av[1], '.') && !ft_strncmp(ft_strrchr(av[1], '.'), ".cub", 5))
		g_p.fd = open("map.cub", O_RDONLY);
	// else
	// 	ft_print_errors(6);
	g_str = malloc(9 * sizeof(char));
  	if (g_str == 0)
    	exit(EXIT_FAILURE);
  	i = -1;
 	while (++i < 8)
    	g_str[i] = '0';
  	g_str[i] = 0;
	if (g_p.fd != -1)
	{
		a = get_next_line(g_p.fd, &g_p.ln);
		if (a == 0 && g_p.ln[0] == '\0')
			ft_print_errors(24);
		while (g_p.ln[0] == '\0')
		{
            if (a == 0)
				ft_print_errors(24);
			a = get_next_line(g_p.fd, &g_p.ln);
		}
		i = 0;
		while (g_p.ln[i] == ' ')
            i++;
		b = put_check(i, b);
		while (a != 0)
		{
			i = 0;
			a = get_next_line(g_p.fd, &g_p.ln);
			while (g_p.ln[i] == ' ')
            	i++;
			while (g_p.ln[0] == '\0' && a != 0)
				a = get_next_line(g_p.fd, &g_p.ln);
			if ((g_p.ln[i] == '1' || g_p.ln[i] == ' ') && b >= 8)
				break ;
			i = put_check(i, b);
			if (i == 0 && b == 8)
				break ;
			else if (i != 0)
				b = i;
			else if (i == 0)
				ft_print_errors(2);
		}
		if (b >= 8 && a == 0)
		{
			if ((g_p.ln[i] == '1' || g_p.ln[i] == ' ') && b >= 8)
				ft_print_errors(29);
			ft_print_errors(31);
		}
		check_map();
	}
	else
		ft_print_errors(7);
}

int	main()
{
	// t_data		data;
	g_data.mlx = mlx_init();

	ft_readfile();
//	exit(EXIT_SUCCESS);

	
	// g_ray.win_w = 15 * TILE_SIZE;
	// g_ray.win_h = 11 * TILE_SIZE;
	g_ray.num_rays = g_ray.win_w / WALL_STRIP_WIDTH;
	//g_ray1[g_ray.num_rays] ;
	// g_tex.filenameup = "./images/txt64-3.xpm";
	// g_tex.filenamedown = "./images/txt64-2.xpm";
	// g_tex.filenameleft = "./images/txt64-4.xpm";
	// g_tex.filenameright = "./images/txt64-1.xpm";
	g_data.turndirection = 0;
	g_data.walkdirection = 0;
	//g_data.rotationangle = M_PI_2;
	g_data.movespeed = 4.0;
	g_data.rotationspeed = 3 * (M_PI / 180);
	g_data.fov_angle = 60 * (M_PI / 180);
	// g_player.xplayer = (15 * TILE_SIZE) / 2;
	// g_player.yplayer = (11 * TILE_SIZE) / 2;
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
