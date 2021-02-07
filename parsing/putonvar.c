/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putonvar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 18:50:30 by ael-kass          #+#    #+#             */
/*   Updated: 2021/01/25 11:32:57 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_spaces(void)
{
	int		i;

	i = 0;
	while (g_p.ln[i] == ' ')
		i++;
	return (i);
}

int		put_check(int i, int b)
{
	int		a;

	if (g_p.ln[i] == 'R')
	{
		return (resolution(b));
	}
	a = put_check_help1(i, b);
	if (a != 0)
		return (a);
	a = put_check_help2(i, b);
	if (a != 0)
		return (a);
	a = put_check_help3(i, b);
	if (a != 0)
		return (a);
	if (g_p.ln[i] == 'S' && g_p.ln[i + 1] == ' ')
	{
		if (g_str[5] == '1')
			ft_print_errors(20);
		else
			g_str[5] = '1';
		no_so_we_ea_s(1, 5);
		return (b + 1);
	}
	return (0);
}

void	ft_print_errors1(char *str, int index)
{
	
	ft_putstr("Error\n");
	if (index == 0)
	{
		ft_putstr(str);
		exit (EXIT_FAILURE);
		return ;
	}
	if (index == 1)
		str = ft_strjoin("Resolution: ", str);
	if (index == 2)
		str = ft_strjoin("usage: ", str);
	if (index == 3)
		str = ft_strjoin("North texture: ", str);
	if (index == 4)
		str = ft_strjoin("South texture: ", str);
	if (index == 5)
		str = ft_strjoin("West texture: ", str);
	if (index == 6)
		str = ft_strjoin("East texture: ", str);
	if (index == 7)
		str = ft_strjoin("Sprite texture: ", str);
	if (index == 8)
		str = ft_strjoin("Map: ", str);
	ft_putstr(str);
	ft_free(&str);
	ft_free(&g_str);
	ft_free(&g_p.str);
	ft_free(&g_p.ln);
	ft_free(&g_tex.filenamedown);
	ft_free(&g_tex.filenameleft);
	ft_free(&g_tex.filenameright);
	ft_free(&g_tex.filenameup);
	ft_free(&g_tex.filesprite);
	exit(EXIT_FAILURE);
}

void	ft_print_errors(int index)
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
		ft_print_errors1("./cub3D<file.cub> or ./cub3D <file.cub><--save>\n",0);
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
	ft_print_errors2(index);
	ft_print_errors3(index);
}

void	ft_print_errors2(int index)
{
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
}

void	ft_print_errors3(int index)
{
	if (index == 12)
		ft_print_errors1("Floor color: The F information is wrong\n", 0);
	if (index == 25)
		ft_print_errors1("no valid map\n", 8);
	if (index == 26)
		ft_print_errors1("multiplayer\n", 8);
	if (index == 27)
		ft_print_errors1("no player in the map\n", 8);
	if (index == 28)
		ft_print_errors1("map not found\n", 8);
	if (index == 29)
		ft_print_errors1("the map start with 3 lines at least\n", 8);
	if (index == 30)
		ft_print_errors1("there is a character not valid in the map\n", 8);
	if (index == 31)
		ft_print_errors1("There is no map\n", 8);
}

int		put_check_help1(int i, int b)
{
	if (g_p.ln[i] == 'N' && g_p.ln[i + 1] == 'O')
	{
		if (g_p.ln[i + 2] != ' ')
			ft_print_errors(2);
		if (g_str[1] == '1')
			ft_print_errors(16);
		else
			g_str[1] = '1';
		no_so_we_ea_s(1, 1);
		return (b + 1);
	}
	if (g_p.ln[i] == 'W' && g_p.ln[i + 1] == 'E')
	{
		if (g_p.ln[i + 2] != ' ')
			ft_print_errors(2);
		if (g_str[3] == '1')
			ft_print_errors(18);
		else
			g_str[3] = '1';
		no_so_we_ea_s(1, 3);
		return (b + 1);
	}
	return (0);
}

int		put_check_help2(int i, int b)
{
	if (g_p.ln[i] == 'E' && g_p.ln[i + 1] == 'A')
	{
		if (g_p.ln[i + 2] != ' ')
			ft_print_errors(2);
		if (g_str[4] == '1')
			ft_print_errors(19);
		else
			g_str[4] = '1';
		no_so_we_ea_s(1, 4);
		return (b + 1);
	}
	if (g_p.ln[i] == 'S' && g_p.ln[i + 1] == 'O')
	{
		if (g_p.ln[i + 2] != ' ')
			ft_print_errors(2);
		if (g_str[2] == '1')
			ft_print_errors(17);
		else
			g_str[2] = '1';
		no_so_we_ea_s(1, 2);
		return (b + 1);
	}
	return (0);
}

int		put_check_help3(int i, int b)
{
	char	**line;
	int		f_len;

	f_len = 0;
	if (g_p.ln[i] == 'F' && g_p.ln[i + 1] == ' ')
	{
		line = ft_split(g_p.ln, ' ');
		if (g_str[6] == '1')
			ft_print_errors(21);
		else
			g_str[6] = '1';
		ft_floor(line);
		f_len = len_of_line(line);
		ft_free1(line, f_len);
		return (b + 1);
	}
	if (g_p.ln[i] == 'C' && g_p.ln[i + 1] == ' ')
	{
		line = ft_split(g_p.ln, ' ');
		if (g_str[7] == '1')
			ft_print_errors(22);
		else
			g_str[7] = '1';
		ft_ceilling(line);
		f_len = len_of_line(line);
		ft_free1(line, f_len);
		return (b + 1);
	}
	return (0);
}