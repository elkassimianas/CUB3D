/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 15:14:44 by ael-kass          #+#    #+#             */
/*   Updated: 2020/12/31 15:14:46 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

void    resolution()
{
    char    **line;
    
    line = ft_split(g_check.line, ' ');
    ft_strlen(line[0]) != 1 ? ft_print_errors(2) : 1;
    nu_information(line) != 3 ? ft_print_errors(1) : 3;
    g_ray.win_w = ft_atoi(line[1]);
    g_ray.win_w == 0 ? ft_print_errors(1) : g_ray.win_w;
    g_ray.win_w = g_ray.win_w > WIN_WMAX ? WIN_WMAX : g_ray.win_w;
    g_ray.win_h = ft_atoi(line[2]);
    g_ray.win_h == 0 ? ft_print_errors(1) : g_ray.win_h;
    g_ray.win_h = g_ray.win_h > WIN_HMAX ? WIN_HMAX : g_ray.win_h;
}

void    ft_floor()
{
    char    **line;

    line = ft_split(g_check.line, ' ');
    ft_strlen(line[0]) != 1 ? ft_print_errors(2) : 1;
    nu_information(line) != 2 ? ft_print_errors(12) : 2;
    line = ft_split(line[1], ',');
    nu_information(line) != 3 ? ft_print_errors(1) : 3;
    
    printf("%s\n", line[1]);

}

void    no_so_we_ea_s(int dx1, int dx2)
{
    char    **line;

    line = ft_split(g_check.line, ' ');
    if (dx1 == 1)
    {
        if (!mlx_xpm_file_to_image (g_data.mlx, line[1], &g_texture.width, &g_texture.height) || nu_information(line) != 2)
        {
            dx2 == 1 ? ft_print_errors(3) : dx2;
            dx2 == 2 ? ft_print_errors(4) : dx2;
            dx2 == 3 ? ft_print_errors(9) : dx2;
            dx2 == 4 ? ft_print_errors(10) : dx2;
            dx2 == 5 ? ft_print_errors(11) : dx2;
        }
        else
        {
            g_texture.filenameup = dx2 == 1 ? line[1] : g_texture.filenameup;
            g_texture.filenamedown = dx2 == 2 ? line[1] : g_texture.filenamedown;
            g_texture.filenameleft = dx2 == 3 ? line[1] : g_texture.filenameleft;
            g_texture.filenameright = dx2 == 4 ? line[1] : g_texture.filenameright;
            g_texture.filesprite = dx2 == 5 ? line[1] : g_texture.filesprite;
        }
    }
}

size_t    nu_information(char **line)
{
    size_t     i;

    i = 0;
    while (line[i] != '\0')
        i++;
    return (i);
}