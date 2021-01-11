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

int    ft_spaces()
{
    int     i;

    i = 0;
    while (g_check.line[i] == ' ')
        i++;
    return (i);
}

int     put_check(int a)
{
    while (a != 0)
    {
        int i = 0;
        int b = 0;
        while (g_check.line == '\0')
        {
            if (a == 0)
                ft_print_errors(0);
            else
                a = get_next_line(g_check.fd, &g_check.line);
        }
        while (g_check.line[i] == ' ')
            i++;
        if (g_check.line[i] == 'R')
        {
            resolution();
            b++;
        }
        if (g_check.line[0] == 'N' && g_check.line[1] == 'O')
        {
            north()
        }
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
        else
            ft_print_errors(8);
        if (a == 0)
            ft_print_errors(0);
        else
            a = get_next_line(g_check.fd, &g_check.line);
    }
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
        ft_print_errors1("The R information is wrong\n", 1);
    if (index == 5)
        ft_print_errors1("./cub3D <filename.cub> or ./cub3D <filename.cub> <--save>\n",0);
    if (index == 6)
        ft_print_errors1("first argument should be file in format *.cub\n", 0);
    if (index == 7)
        ft_print_errors1("no such file or directory\n", 0);
    if (index == 8)
        ft_print_errors1("Elements absent\n", 0);
}