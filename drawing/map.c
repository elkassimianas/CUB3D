/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 13:21:08 by ael-kass          #+#    #+#             */
/*   Updated: 2020/12/05 16:27:21 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		drawing_cub_walls(double tilex, double tiley)
{
	int		x;
	int		y;

	x = (TL_SZ * MINIMAP_SCALE_FACTOR) + tilex;
	y = (TL_SZ * MINIMAP_SCALE_FACTOR) + tiley;
	while (tiley < y)
	{
		while (tilex < x)
		{
			if (tiley >= 0 && tilex >= 0 && tilex < g_dt.win_w && tiley < g_dt.win_h)
				g_dt.addr[(int)tiley * g_dt.win_w + (int)tilex] = g_tilecolor;
			tilex += 0.1;
		}
		tilex -= (TL_SZ * MINIMAP_SCALE_FACTOR);
		tiley += 0.1;
	}
}

void		map()
{
	int			i;
	int			j;
	double		tiley;
	double		tilex;

	tilex = 0;
	tiley = 0;
	i = -1;
	while (++i < g_p.inc)
	{
		j = -1;
		while (++j < (int)g_p.len)
		{
			tilex = j * TL_SZ * MINIMAP_SCALE_FACTOR;
			tiley = i * TL_SZ * MINIMAP_SCALE_FACTOR;
			if (g_dt.map[i][j] == '1')
			{
				g_tilecolor = 0x5C413B;
				drawing_cub_walls(tilex, tiley);
			}
			else if (g_dt.map[i][j] == '2')
			{
				g_tilecolor = 0x33FF74;
				drawing_cub_walls(tilex, tiley);
			}
		}
	}
}
