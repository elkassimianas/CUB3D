/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 12:35:28 by ael-kass          #+#    #+#             */
/*   Updated: 2021/01/24 16:16:21 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		check_map1(int check)
{
	int		i;

	i = 0;
	while (g_p.ln[i] != '\0')
	{
		if (g_p.ln[i] == ' ' || g_p.ln[i] == '1' || g_p.ln[i] == '0' ||
				g_p.ln[i] == '2')
			i++;
		else if (g_p.ln[i] == 'N' || g_p.ln[i] == 'S')
		{
			check == 0 ? check = 1 : ft_print_errors(26);
			i++;
		}
		else if (g_p.ln[i] == 'E' || g_p.ln[i] == 'W')
		{
			check == 0 ? check = 1 : ft_print_errors(26);
			i++;
		}
		else
			ft_print_errors(30);
	}
	return (check);
}

void	ft_valid_map(int x, int y)
{
	int		i;
	int		j;

	i = -1;
	while (++i < y)
	{
		j = -1;
		while (++j < x)
		{
			if (j == 0)
			{
				while (g_data.map[i][j] == ' ')
					j == x - 1 ? ft_print_errors(25) : j++;
				g_data.map[i][j] != '1' ? ft_print_errors(25) : 1;
			}
			ft_check_spaces(i, j, x, y);
		}
	}
}

void	ft_check_spaces(int i, int j, int x, int y)
{
	if (g_data.map[i][j] == ' ')
	{
		g_data.map[i][j - 1] == '1' || g_data.map[i][j - 1] == ' ' ? 1 :
			ft_print_errors(25);
		if (j != x - 1)
			g_data.map[i][j + 1] == '1' || g_data.map[i][j + 1] == ' ' ?
				1 : ft_print_errors(25);
		if (i != 0)
			g_data.map[i - 1][j] == '1' || g_data.map[i - 1][j] == ' ' ?
				1 : ft_print_errors(25);
		if (i != y - 1)
			g_data.map[i + 1][j] == '1' || g_data.map[i + 1][j] == ' ' ?
				1 : ft_print_errors(25);
	}
}

int		find_player(int j, int i)
{
	if (g_data.map[i][j] == 'N')
	{
		g_data.rotationangle = M_PI_2;
		return (1);
	}
	if (g_data.map[i][j] == 'S')
	{
		g_data.rotationangle = (3 * M_PI) / 2;
		return (1);
	}
	if (g_data.map[i][j] == 'E')
	{
		g_data.rotationangle = 0;
		return (1);
	}
	if (g_data.map[i][j] == 'W')
	{
		g_data.rotationangle = M_PI;
		return (1);
	}
	return (0);
}

void	change_spaces(void)
{
	int		i;
	int		j;

	i = -1;
	while (++i < g_p.inc)
	{
		j = 0;
		while (j < (int)g_p.len)
		{
			if (g_data.map[i][j] == ' ')
				g_data.map[i][j] = '1';
			
			if (find_player(j,i))
			{
				g_player.xplayer = j * TILE_SIZE + TILE_SIZE / 2;
				g_player.yplayer = i * TILE_SIZE + TILE_SIZE / 2;
				g_data.map[i][j] = '0';
			}
			j++;
		}
	}
}
