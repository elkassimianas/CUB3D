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
    //unsigned int    n_w;
   // int     i;
    
    line = ft_split(g_check.line, ' ');
    //len_line = nu_information(line);
    nu_information(line) != 3 ? ft_print_errors("number of informations must be 3\n") : 3;
    ft_strlen(line[0]) != 1 ? ft_print_errors("in the first information\n") : 1;
    g_ray.win_w = ft_atoi(line[1]);
    g_ray.win_w == 0 ? ft_print_errors("in the second information\n") : g_ray.win_w;
    g_ray.win_w = g_ray.win_w > WIN_WMAX ? WIN_WMAX : g_ray.win_w;
   // printf("win_W: %d\n", g_ray.win_w);
    g_ray.win_h = ft_atoi(line[2]);
    g_ray.win_h == 0 ? ft_print_errors("in the third information\n") : g_ray.win_h;
    g_ray.win_h = g_ray.win_h > WIN_HMAX ? WIN_HMAX : g_ray.win_h;
   // printf("win_H: %d\n", g_ray.win_h);
    exit(EXIT_SUCCESS);
}

size_t    nu_information(char **line)
{
    size_t     i;
    
    i = 0;
    while (line[i] != '\0')
        i++;
    return (i);
}