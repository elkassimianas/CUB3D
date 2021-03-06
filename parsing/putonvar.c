/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putonvar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 18:50:30 by ael-kass          #+#    #+#             */
/*   Updated: 2021/02/14 10:11:27 by ael-kass         ###   ########.fr       */
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
	return (put_check_ceilling(i, b));
}
