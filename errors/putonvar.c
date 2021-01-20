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
    while (g_par.line[i] == ' ')
        i++;
    return (i);
}

int     put_check(int i, int b)
{
    if (g_par.line[i] == 'R')
    {
        resolution();
        b++;
        return (b);
    }
    if (g_par.line[i] == 'N' && g_par.line[i+1] == 'O')
    {
        if (g_par.line[i + 2] != ' ')
            ft_print_errors(2);
         if (g_str[1] == '1')
            ft_print_errors(16);
        else
            g_str[1] = '1';
        no_so_we_ea_s(1,1);
        b++;
        return (b);
    }
    if (g_par.line[i] == 'S' && g_par.line[i+1] == 'O')
    {
        if (g_par.line[i+2] != ' ')
            ft_print_errors(2);
        if (g_str[2] == '1')
            ft_print_errors(17);
        else
            g_str[2] = '1';
        no_so_we_ea_s(1,2);
        b++;
        return (b);
    }
    if (g_par.line[i] == 'W' && g_par.line[i+1] == 'E')
    {
        if (g_par.line[i+2] != ' ')
            ft_print_errors(2);
        if (g_str[3] == '1')
            ft_print_errors(18);
        else
            g_str[3] = '1';
        no_so_we_ea_s(1,3);
        b++;
        return (b);
    }
    if (g_par.line[i] == 'E' && g_par.line[i+1] == 'A')
    {
        if (g_par.line[i+2] != ' ')
            ft_print_errors(2);
        if (g_str[4] == '1')
            ft_print_errors(19);
        else
            g_str[4] = '1';
        no_so_we_ea_s(1, 4);
        b++;
        return (b);
    }
    if (g_par.line[i] == 'S')
    {
        if (g_par.line[i+1] != ' ')
            ft_print_errors(2);
        if (g_str[5] == '1')
            ft_print_errors(20);
        else
            g_str[5] = '1';
        no_so_we_ea_s(1,5);
        b++;
        return (b);
    }
    if (g_par.line[i] == 'F' && g_par.line[i+1] == ' ')
    {
        char    **line;

        line = ft_split(g_par.line, ' ');
        if (g_str[6] == '1')
            ft_print_errors(21);
        else
            g_str[6] = '1';
        ft_floor(line);
        b++;
        return (b);
    }
    if (g_par.line[i] == 'C' && g_par.line[i+1] == ' ')
    {
        char    **line;

        line = ft_split(g_par.line, ' ');
        if (g_str[7] == '1')
            ft_print_errors(22);
        else
            g_str[7] = '1';
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
        ft_print_errors1("you need to put all the elements of the file\n", 0);
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
        ft_print_errors1("Ceilling color: The C information is wrong\n", 0);
    if (index == 15)
        ft_print_errors1("there is a duplication\n", 1);
    if (index == 16)
        ft_print_errors1("there is a duplication\n", 3);
    if (index == 17)
        ft_print_errors1("there is a duplication\n", 4);
    if (index == 18)
        ft_print_errors1("there is a duplication\n", 5);
    if (index == 19)
        ft_print_errors1("there is a duplication\n", 6);
    if (index == 20)
        ft_print_errors1("there is a duplication\n", 7);
    if (index == 21)
        ft_print_errors1("Floor color: there is a duplication\n", 0);
    if (index == 22)
        ft_print_errors1("Ceilling color: there is a duplication\n", 0);
    if (index == 24)
        ft_print_errors1("Empty File\n", 0);
    if (index == 25)
        ft_print_errors1("no valid map\n", 0);
}