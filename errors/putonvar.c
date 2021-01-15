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

int     put_check(int i, int b)
{
    if (g_check.line[i] == 'R')
    {
        resolution();
        b++;
        return (b);
    }
    if (g_check.line[i] == 'N' && g_check.line[i+1] == 'O')
    {
        if (g_check.line[i + 2] != ' ')
            ft_print_errors(2);
        no_so_we_ea_s(1,1);
        b++;
        return (b);
    }
    if (g_check.line[i] == 'S' && g_check.line[i+1] == 'O')
    {
        if (g_check.line[i+2] != ' ')
            ft_print_errors(2);
        no_so_we_ea_s(1,2);
        b++;
        return (b);
    }
    if (g_check.line[i] == 'W' && g_check.line[i+1] == 'E')
    {
        if (g_check.line[i+2] != ' ')
            ft_print_errors(2);
        no_so_we_ea_s(1,3);
        b++;
        return (b);
    }
    if (g_check.line[i] == 'E' && g_check.line[i+1] == 'A')
    {
        if (g_check.line[i+2] != ' ')
            ft_print_errors(2);
        no_so_we_ea_s(1, 4);
        b++;
        return (b);
    }
    if (g_check.line[i] == 'S')
    {
        if (g_check.line[i+1] != ' ')
            ft_print_errors(2);
        no_so_we_ea_s(1,5);
        b++;
        return (b);
    }
    if (g_check.line[i] == 'F' && g_check.line[i+1] == ' ')
    {
        char    **line;

        line = ft_split(g_check.line, ' ');
        ft_floor(line);
        b++;
        return (b);
    }
    if (g_check.line[i] == 'C' && g_check.line[i+1] == ' ')
    {
        char    **line;

        line = ft_split(g_check.line, ' ');
        ft_ceilling(line);
        b++;
        return (b);
    }
    ft_print_errors(2);
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
    if (index == 3)
        str = ft_strjoin("\x1B[37mNorth texture: ", str);
    if (index == 4)
        str = ft_strjoin("\x1B[37mSouth texture: ", str);
    if (index == 5)
        str = ft_strjoin("\x1B[37mWest texture: ", str);
    if (index == 6)
        str = ft_strjoin("\x1B[37mEast texture: ", str);
    if (index == 7)
        str = ft_strjoin("\x1B[37mSprite texture: ", str);
    ft_putstr(str);
    exit (EXIT_FAILURE);
}

void    ft_print_errors(int  index)
{
    if (index == 0)
        ft_print_errors1("you need to put all the information of the file\n", 0);
    if (index == 1)
        ft_print_errors1("The R information is wrong\n", 1);
    if (index == 2)
        ft_print_errors1("there is an error for informations of elements\n", 0);
    if (index == 3)
        ft_print_errors1("The NO information is wrong\n", 3);
    if (index == 4)
        ft_print_errors1("The SO information is wrong\n", 4);
    if (index == 5)
        ft_print_errors1("./cub3D <filename.cub> or ./cub3D <filename.cub> <--save>\n",0);
    if (index == 6)
        ft_print_errors1("first argument should be file in format *.cub\n", 0);
    if (index == 7)
        ft_print_errors1("no such file or directory\n", 0);
    if (index == 8)
        ft_print_errors1("Elements absent\n", 0);
    if (index == 9)
        ft_print_errors1("The WE information is wrong\n", 5);
    if (index == 10)
        ft_print_errors1("The EA information is wrong\n", 6);
    if (index == 11)
        ft_print_errors1("The S information is wrong\n", 7);
    if (index == 12)
        ft_print_errors1("Floor color: The F information is wrong\n", 0);
    if (index == 13)
        ft_print_errors1("put only one , between rgb\n", 0);
    if (index == 14)
        ft_print_errors1("ceilling color: The C information is wrong\n", 0);
}