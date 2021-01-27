/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 08:11:41 by ael-kass          #+#    #+#             */
/*   Updated: 2021/01/24 12:43:09 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_map(void)
{
	int			check_p;

	g_p.len = 0;
	g_p.len = ft_strlen(g_p.ln);
	g_p.str = g_p.ln;
	g_p.str = ft_strjoin(g_p.str, "c");
	check_first_end_line();
	check_p = ft_read_map();
	if (check_p == 0)
		ft_print_errors(27);
	ft_allocate(g_p.len, g_p.inc);
	ft_putmap(g_p.len, g_p.inc);
	change_spaces();
}

void	ft_allocate(int x, int y)
{
	int		i;

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

void	check_first_end_line(void)
{
	int		i;

	i = 0;
	while (g_p.ln[i] != '\0')
	{
		if (g_p.ln[i] == ' ' || g_p.ln[i] == '1')
			i++;
		else
			ft_print_errors(25);
	}
}

void	ft_putmap(int x, int y)
{
	int		i;
	int		j;
	int		a;

	i = 0;
	a = 0;
	while (i < y)
	{
		j = 0;
		while (g_p.str[a] != 'c')
		{
			g_data.map[i][j] = g_p.str[a];
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
	ft_valid_map(x, y);
}

int		ft_read_map(void)
{
	int		a;
	int		check;

	g_p.inc = 1;
	check = 0;
	a = 1;
	while (a != 0)
	{
		a = get_next_line(g_p.fd, &g_p.ln);
		if (a == 0 && g_p.ln[0] != '0')
			check_first_end_line();
		else if (a == 0)
			ft_print_errors(25);
		g_p.str = ft_strjoin(g_p.str, g_p.ln);
		g_p.str = ft_strjoin(g_p.str, "c");
		g_p.inc++;
		check = check_map1(check);
		g_p.len = g_p.len > ft_strlen(g_p.ln) ? g_p.len : ft_strlen(g_p.ln);
	}
	if (g_p.inc < 3)
		ft_print_errors(29);
	return (check);
}
