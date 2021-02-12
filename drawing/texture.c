/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 09:44:39 by ael-kass          #+#    #+#             */
/*   Updated: 2020/12/15 09:44:54 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../cub3d.h"

void    buffertexture()
{
	// int     x;
	int     i;
	//void    *dataimg[4];

	dataimg[0] = mlx_xpm_file_to_image (g_dt.mlx, g_tex.filenameup, &g_tex.width, &g_tex.height);
	ft_free(&g_tex.filenameup);
	dataimg[1] = mlx_xpm_file_to_image (g_dt.mlx, g_tex.filenamedown, &g_tex.width, &g_tex.height);
	ft_free(&g_tex.filenamedown);
	dataimg[2] = mlx_xpm_file_to_image (g_dt.mlx, g_tex.filenameleft, &g_tex.width, &g_tex.height);
	ft_free(&g_tex.filenameleft);
	dataimg[3] = mlx_xpm_file_to_image (g_dt.mlx, g_tex.filenameright, &g_tex.width, &g_tex.height);
	ft_free(&g_tex.filenameright);
	dataimg[4] = mlx_xpm_file_to_image (g_dt.mlx, g_tex.filesprite, &g_tex.width, &g_tex.height);
	ft_free(&g_tex.filesprite);
	i = -1;
	while (++i < 5)
		g_tex.addr[i] = (int *)mlx_get_data_addr(dataimg[i], &g_dt.bits_per_pixel, &g_dt.line_length, &g_dt.endian);
  //  dataimg = g_r.isg_rfacingright ? mlx_xpm_file_to_image (g_dt.mlx, g_tex.filenameright, &g_tex.width, &g_tex.height) : dataimg;
	// g_tex.addr[0][0] = (int *)mlx_get_data_addr(dataimg, &g_dt.bits_per_pixel, &g_dt.line_length, &g_dt.endian);
  //  / g_tex.addrvert = (int *)mlx_get_data_addr(dataimgvert, &g_dt.bits_per_pixel, &g_dt.line_length, &g_dt.endian); 
	// i = -1;
	// while (++i < 4)
	//   mlx_destroy_image(g_dt.mlx, dataimg[i]);
}

//mlx_xpm_file_to_image ( void *mlx_ptr, char *filename, int *width, int *height );