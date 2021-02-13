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

int		update(void)
{
	mlx_hook(g_dt.win, 2, 0, keypressed, (void*)0);
	mlx_hook(g_dt.win, 3, 1, keyrelease, (void *)0);
	mlx_hook(g_dt.win, 17, 0L, quit_win, (void*)0);
	draw_new_map();
	castallg_rs(-1);
	render3dprojectedwalls();
	ft_draw_sprite();
	mlx_put_image_to_window(g_dt.mlx, g_dt.win, g_dt.img, 0, 0);
	return (0);
}

void	ft_initial_var(void)
{
	g_dt.img_w = TL_SZ * g_p.len;
	g_dt.img_h = TL_SZ * g_p.inc;
	g_r.num_rays = g_dt.win_w / WALL_STRIP_WIDTH;
	g_dt.turndirection = 0;
	g_dt.walkdirection = 0;
	g_dt.walkdirection_side = 0;
	g_dt.movespeed = 5;
	g_dt.rotationspeed = 4 * (M_PI / 180);
	g_dt.fov_angle = 60 * (M_PI / 180);
}

int	main(int argc, char * argv[])
{	
	g_dt.mlx = mlx_init();
	ft_readfile(argc, argv);
	ft_initial_sprite();
	buffertexture();
	ft_initial_var();
	if (argc == 2)
		g_dt.win = mlx_new_window(g_dt.mlx, g_dt.win_w, g_dt.win_h, "cub3D");
	g_dt.img = mlx_new_image(g_dt.mlx, g_dt.win_w, g_dt.win_h);
	g_dt.addr = (int *)mlx_get_data_addr(g_dt.img, &g_dt.bits_per_pixel,
			&g_dt.line_length, &g_dt.endian);
	if (argc == 3)
	{
		draw_new_map();
		castallg_rs(-1);
		render3dprojectedwalls();
		ft_draw_sprite();
		create_file_bmp(0);
		exit (EXIT_SUCCESS);
	}
	mlx_loop_hook(g_dt.mlx, update, (void*) 0);
	mlx_loop(g_dt.mlx);
}
