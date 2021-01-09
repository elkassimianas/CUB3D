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
            ft_print_errors(0);
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
       ft_print_errors(1);
    return (0);
}

void    ft_print_errors1(char *str, int index)
{
    ft_putstr("\x1B[31mError\n");
    if (index == 0)
        str = ft_strjoin("\x1B[37m", str);
    if (index == 1)
        str = ft_strjoin("\x1B[37mResolution: ", str);
    if (index == 2)
        str = ft_strjoin("\x1B[37musage: ", str);
    ft_putstr(str);
    exit (EXIT_FAILURE);
}

void ft_print_errors(int  index)
{
    if (index == 0)
        ft_print_errors1("you need to put all the information of the file\n", 0);
    if (index == 1)
        ft_print_errors1("in the first information", 1);
    if (index == 2)
        ft_print_errors1("in the second information", 1);
    if (index == 3)
        ft_print_errors1("in the Third information", 1);
    if (index == 4)
        ft_print_errors1("Number of informations must be 3", 1);
    if (index == 5)
        ft_print_errors1("./cub3D <filename.cub> or ./cub3D <filename.cub> <--save>",0);
}