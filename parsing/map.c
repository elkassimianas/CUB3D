/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 08:11:41 by ael-kass          #+#    #+#             */
/*   Updated: 2021/02/14 09:56:18 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		check_map(void)
{
	int		check_p;

	g_p.len = 0;
	g_p.count_spri = 0;
	g_p.len = ft_strlen(g_p.ln);
	g_p.str = ft_strjoin(g_p.ln, "c");
	check_first_end_line();
	ft_free(&g_p.ln);
	check_p = ft_read_map(0, 1);
	if (check_p == 0)
		ft_print_errors(27);
	ft_allocate(g_p.len, g_p.inc);
	ft_putmap(g_p.len, g_p.inc);
	ft_free(&g_p.str);
	change_spaces();
}

void		ft_allocate(int x, int y)
{
	int		i;

	g_dt.map = malloc(y * sizeof(char *));
	if (g_dt.map == NULL)
		exit(EXIT_FAILURE);
	i = -1;
	while (++i < y)
	{
		g_dt.map[i] = malloc(x * sizeof(char));
		if (g_dt.map[i] == NULL)
			exit(EXIT_FAILURE);
	}
}

void		check_first_end_line(void)
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

void		ft_putmap(int x, int y)
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
			g_dt.map[i][j] = g_p.str[a];
			j++;
			a++;
		}
		while (j < x)
		{
			g_dt.map[i][j] = ' ';
			j++;
		}
		a++;
		i++;
	}
	ft_valid_map(x, y);
}

int			ft_read_map(int check, int a)
{
	char	*free1;

	g_p.inc = 1;
	while (a != 0)
	{
		a = get_next_line(g_p.fd, &g_p.ln);
		if (g_p.ln[0] != ' ' && g_p.ln[0] != '1')
			ft_print_errors(25);
		if (a == 0)
			check_first_end_line();
		free1 = g_p.str;
		g_p.str = ft_strjoin(free1, g_p.ln);
		ft_free(&free1);
		free1 = g_p.str;
		g_p.str = ft_strjoin(free1, "c");
		ft_free(&free1);
		g_p.inc++;
		check = check_map1(check, 0);
		g_p.len = g_p.len > ft_strlen(g_p.ln) ? g_p.len : ft_strlen(g_p.ln);
		ft_free(&g_p.ln);
	}
	if (g_p.inc < 3)
		ft_print_errors(29);
	return (check);
}
