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
	//int		i = 0;
	
	mlx_hook(g_dt.win, 2, 0, keypressed, (void*)0);
	mlx_hook(g_dt.win, 3, 1, keyrelease, (void *)0);
	mlx_hook(g_dt.win, 17, 0L, quit_win, (void*)0);
	draw_new_map();
	castallg_rs();
	//ft_draw_sprite();
	render3dprojectedwalls();
	//map();
	ft_draw_sprite();
	// i = -1;
	// while (++i < g_r.num_rays)
	// 	rayspush(g_r1[i].w_hitx * MINIMAP_SCALE_FACTOR, g_r1[i].w_hity * 
	// 		MINIMAP_SCALE_FACTOR);
	mlx_put_image_to_window(g_dt.mlx, g_dt.win, g_dt.img, 0, 0);
	return (0);
}

void	ft_readfile(int argc, char *av[])
{
	int		a;
	int		i;
	int 	b;

	a = 1;
	b = 0;
	argc > 3 || argc == 1 ? ft_print_errors(5) : argc;
	if (argc == 3 && strncmp(av[2], "--save", 7))
		ft_print_errors(5);
	if (ft_strrchr(av[1], '.') && !ft_strncmp(ft_strrchr(av[1], '.'), ".cub", 5))
		g_p.fd = open(av[1], O_RDONLY);
	else
	 	ft_print_errors(6);
	if (!(g_str = (char *)malloc(9 * sizeof(char))))
    	exit(EXIT_FAILURE);
	i = -1;
 	while (++i < 8)
    	g_str[i] = '0';
  	g_str[i] = '\0';
	if (g_p.fd != -1)
	{
		a = get_next_line(g_p.fd, &g_p.ln);
		if (a == 0 && g_p.ln[0] == '\0')
			ft_print_errors(24);
		while (g_p.ln[0] == '\0')
		{
            if (a == 0)
				ft_print_errors(24);
			ft_free(&g_p.ln);
			a = get_next_line(g_p.fd, &g_p.ln);
		}
		i = 0;
		while (g_p.ln[i] == ' ')
            i++;
		b = put_check(i, b);
		while (a != 0)
		{
			i = 0;
			ft_free(&g_p.ln);
			a = get_next_line(g_p.fd, &g_p.ln);
			while (g_p.ln[i] == ' ')
            	i++;
			while (g_p.ln[0] == '\0' && a != 0)
			{
				ft_free(&g_p.ln);
				a = get_next_line(g_p.fd, &g_p.ln);
			}
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
		ft_free(&g_str);
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

int	main(int argc, char * argv[])
{	
	g_dt.mlx = mlx_init();
	ft_readfile(argc, argv);
	ft_initial_sprite();
	buffertexture();
	g_dt.img_w = TL_SZ * g_p.len;
	g_dt.img_h = TL_SZ * g_p.inc;
	g_r.num_rays = g_dt.win_w / WALL_STRIP_WIDTH;
	g_dt.turndirection = 0;
	g_dt.walkdirection = 0;
	g_dt.walkdirection_side = 0;
	g_dt.movespeed = 5;
	g_dt.rotationspeed = 4 * (M_PI / 180);
	g_dt.fov_angle = 60 * (M_PI / 180);
	if (argc == 2)
		g_dt.win = mlx_new_window(g_dt.mlx, g_dt.win_w, g_dt.win_h, "cub3D");
	g_dt.img = mlx_new_image(g_dt.mlx, g_dt.win_w, g_dt.win_h);
	g_dt.addr = (int *)mlx_get_data_addr(g_dt.img, &g_dt.bits_per_pixel,
			&g_dt.line_length, &g_dt.endian);
	if (argc == 3)
	{
		draw_new_map();
		castallg_rs();
		render3dprojectedwalls();
		ft_draw_sprite();
		create_file_bmp(0);
		exit (EXIT_SUCCESS);
	}
	//map();
	//mlx_put_image_to_window(g_dt.mlx, g_dt.win, g_dt.img, 0, 0);
	mlx_loop_hook(g_dt.mlx, update, (void*) 0);
	mlx_loop(g_dt.mlx);
}
