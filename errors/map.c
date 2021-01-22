/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 08:11:41 by ael-kass          #+#    #+#             */
/*   Updated: 2021/01/20 08:11:49 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    check_map()
{
    int     a;
    int     len;
    int     check;
    int     inc;

    check = 0;
    len = 0;
    inc = 1;
    a = 1;
    len = ft_strlen(g_par.line);
    g_par.str = g_par.line;
    g_par.str = ft_strjoin(g_par.str, "c");
    check_first_end_line();
    while (a != 0)
    {
        a = get_next_line(g_par.fd, &g_par.line);
        if (a == 0 && g_par.line[0] != '0')
            check_first_end_line();
        else if (a == 0)
            ft_print_errors(25);
        g_par.str = ft_strjoin(g_par.str, g_par.line);
        g_par.str = ft_strjoin(g_par.str, "c");
        inc++;
        check = check_map1(check);
        len = len > (int)ft_strlen(g_par.line) ? len : ft_strlen(g_par.line);
    }
    if (inc < 3)
        ft_print_errors(29);
    if (check == 0)
        ft_print_errors(27);
    ft_allocate(len, inc);
    ft_putmap(len, inc);
}

void    ft_allocate(int x, int  y)
{
    int     i;
    
    g_data.map = (int **)malloc(y * sizeof(int *));
    if (g_data.map == NULL)
        exit(EXIT_FAILURE);
    i = -1;
    while (++i < y)
    {
        g_data.map[i] = (int *)malloc(x * sizeof(int));
        if (g_data.map[i] == NULL)
            exit(EXIT_FAILURE);
    }
}

void    check_first_end_line()
{
    int     i;

    i = 0;
    while (g_par.line[i] != '\0')
	{
		if (g_par.line[i] == ' ' || g_par.line[i] == '1')
            i++;
        else
            ft_print_errors(25);
    }
}

void    ft_putmap(int x, int y)
{
    int     i;
    int     j;
    int     a;

    i = 0;
    a = 0;
    while (i < y)
    {
        j = 0;
        while (g_par.str[a] != 'c')
        {
            g_data.map[i][j] = g_par.str[a];
            j++;
            a++;
        }
        while (j < x)
        {
            g_data.map[i][j] = ' ';
            j++;
        }
        a++;
        i++;
    }
    i = -1;
    a = 0;
    while (++i < y)
    {
        j = -1;
        while (++j < x)
        {
            if (j == 0)
            {
                while (g_data.map[i][j] == ' ')
                {
                    if (j == x - 1)
                        ft_print_errors(25);
                    j++;
                }
                if (g_data.map[i][j] != '1')
                    ft_print_errors(25);
            }
            if (i == 0 && g_data.map[i][j] == ' ')
            {
                if (j != x - 1)
                    g_data.map[i][j+1] == '1' || g_data.map[i][j+1] == ' ' ? 1 : ft_print_errors(25);
                g_data.map[i][j-1] == '1' || g_data.map[i][j-1] == ' ' ? 1 : ft_print_errors(25);
                g_data.map[i+1][j] == '1' || g_data.map[i+1][j] == ' ' ? 1 : ft_print_errors(25);
            }
            else if (g_data.map[i][j] == ' ')
            {
                g_data.map[i][j-1] == '1' || g_data.map[i][j-1] == ' ' ? 1 : ft_print_errors(25);
                if (j != x - 1)
                    g_data.map[i][j+1] == '1' || g_data.map[i][j+1] == ' ' ? 1 : ft_print_errors(25);
                g_data.map[i-1][j] == '1' || g_data.map[i-1][j] == ' ' ? 1 : ft_print_errors(25);
                if (i != y - 1)
                g_data.map[i+1][j] == '1' || g_data.map[i+1][j] == ' ' ? 1 : ft_print_errors(25);
            }
         } 
    }
}