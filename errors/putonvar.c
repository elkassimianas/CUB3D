/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putonvar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 18:50:30 by ael-kass          #+#    #+#             */
/*   Updated: 2020/12/31 09:46:45 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int     put_check(int a)
{
    //int i = -1;
    while (g_check.line == '\0')
    {
        if (a == 0)
            ft_print_errors("you need to put all the element of the file\n");
        else
            a = get_next_line(g_check.fd, &g_check.line);
    }
    // while (*g_check.line == 'R' || *g_check.line == ' ')
    // {
    //     if (a == 0)
    //         ft_print_errors("there is one line in the file map.cub\n");
    //     g_check.line++;
    //     while (*g_check.line == ' ')
    //         g_check.line++;
    //     if (*g_check.line == 'R')
    //     {
    //         g_check.line++;
    //         if (*g_check.line != ' ')
    //             ft_print_errors("u should be put the spaces between info\n");
    //         while (*g_check.line == ' ')
    //             g_check.line++;
            
            
    //     }
    //     if ((int)*g_check.line < WIN_WMAX)
    //         g_ray.win_w = (int)g_check.line;
    //         //printf("%d\n", g_ray.win_w);
    //     else
    //         g_ray.win_w = WIN_WMAX;
    // }
    // return (0);
    // i = ft_strncmp(g_check.line, "R", 1);
    if (g_check.line[0] == 'R')
        resolution();
   // i = ft_strncmp(g_check.line, "NO", 2);
//     if (g_check.line[0] == 'N' && g_check.line[1] == 'O')
//     {

//     }
//    // i = ft_strncmp(g_check.line, "SO", 2); 
//     if (g_check.line[0] == 'S' && g_check.line[1] == 'O')
//     {}
//    // i = ft_strncmp(g_check.line, "WE", 2);
//     if (g_check.line[0] == 'W' && g_check.line[1] == 'E')
//     {}
//     if (g_check.line[0] == 'E' && g_check.line[1] == 'A')
//     {

//     }
//     if (g_check.line[0] == 'S')
//     {

//     }
//     if (g_check.line[0] == 'F')
//     {}
//     if (g_check.line[0] == 'C')
//     {}

    return (0);
}

void    ft_print_errors(char *str)
{
    ft_putstr("\x1B[31merror: ");
    str = ft_strjoin("\x1B[37m", str);
    ft_putstr(str);
    exit (EXIT_FAILURE);
}