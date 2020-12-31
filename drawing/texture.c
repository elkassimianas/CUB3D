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

void    buffertexture(t_data *data)
{
    // int     x;
    int     i;
    void    *dataimg[4];
    // void    *dataimgvert;

    dataimg[0] = mlx_xpm_file_to_image (data->mlx, g_texture.filenameup, &g_texture.width, &g_texture.height);
    dataimg[1] = mlx_xpm_file_to_image (data->mlx, g_texture.filenamedown, &g_texture.width, &g_texture.height);
    dataimg[2] = mlx_xpm_file_to_image (data->mlx, g_texture.filenameleft, &g_texture.width, &g_texture.height);
    dataimg[3] = mlx_xpm_file_to_image (data->mlx, g_texture.filenameright, &g_texture.width, &g_texture.height);
    i = -1;
    while (++i < 4)
        g_texture.addr[i] = (int *)mlx_get_data_addr(dataimg[i], &data->bits_per_pixel, &data->line_length, &data->endian);
  //  dataimg = g_ray.isg_rayfacingright ? mlx_xpm_file_to_image (data->mlx, g_texture.filenameright, &g_texture.width, &g_texture.height) : dataimg;
    // g_texture.addr[0][0] = (int *)mlx_get_data_addr(dataimg, &data->bits_per_pixel, &data->line_length, &data->endian);
  //  / g_texture.addrvert = (int *)mlx_get_data_addr(dataimgvert, &data->bits_per_pixel, &data->line_length, &data->endian); 
}

//mlx_xpm_file_to_image ( void *mlx_ptr, char *filename, int *width, int *height );