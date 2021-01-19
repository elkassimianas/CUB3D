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
    if (g_str[0] == '1')
        ft_print_errors(15);
    else
        g_str[0] = '1';
    nu_information(line) != 3 ? ft_print_errors(1) : 3;
    g_ray.win_w = ft_atoi(line[1]);
    g_ray.win_w == 0 || g_ray.win_w == -1 ? ft_print_errors(1) : g_ray.win_w;
    g_ray.win_w = g_ray.win_w > WIN_WMAX ? WIN_WMAX : g_ray.win_w;
    g_ray.win_h = ft_atoi(line[2]);
    g_ray.win_h == 0 || g_ray.win_w == -1 ? ft_print_errors(1) : g_ray.win_h;
    g_ray.win_h = g_ray.win_h > WIN_HMAX ? WIN_HMAX : g_ray.win_h;
}

void    ft_floor(char **line)
{
    int     i;
    int     a;

    nu_information(line) != 2 ? ft_print_errors(12) : 2;
    i = -1;
    a = 0;
    while (line[1][++i] != '\0')
    {
        if (line[1][i] == ',')
        {
            if (line[1][i+1] == ',')
                ft_print_errors(13);
            a++;
        }
        a != 2 && line[1][i + 1] == '\0' ? ft_print_errors(13) : a;
    }
    line = ft_split(line[1], ',');
    nu_information(line) != 3 ? ft_print_errors(12) : 2;
    g_texture.rf = ft_atoi(line[0]);
    g_texture.rf == -1 || g_texture.rf > 255 ? ft_print_errors(12) : g_texture.rf; 
    g_texture.gf = ft_atoi(line[1]);
    g_texture.gf == -1 || g_texture.gf > 255 ? ft_print_errors(12) : g_texture.gf;
    g_texture.bf = ft_atoi(line[2]);
    g_texture.bf == -1 || g_texture.bf > 255 ? ft_print_errors(12) : g_texture.bf;
}

void    ft_ceilling(char **line)
{
    int     i;
    int     a;

    nu_information(line) != 2 ? ft_print_errors(14) : 2;
    i = -1;
    a = 0;
    while (line[1][++i] != '\0')
    {
        if (line[1][i] == ',')
        {
            if (line[1][i+1] == ',')
                ft_print_errors(13);
            a++;
        }
        a != 2 && line[1][i+1] == '\0' ? ft_print_errors(13) : a;

    }
    line = ft_split(line[1], ',');
    nu_information(line) != 3 ? ft_print_errors(14) : 2;
    g_texture.rc = ft_atoi(line[0]);
    g_texture.rc == -1 || g_texture.rc > 255 ? ft_print_errors(14) : g_texture.rc; 
    g_texture.gc = ft_atoi(line[1]);
    g_texture.gc == -1 || g_texture.gc > 255 ? ft_print_errors(14) : g_texture.gc;
    g_texture.bc = ft_atoi(line[2]);
    g_texture.bc == -1 || g_texture.bc > 255 ? ft_print_errors(14) : g_texture.bc;
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
    while (line[i] != 0)
        i++;
    return (i);
}