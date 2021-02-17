/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaji-el <hnaji-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 17:27:59 by hnaji-el          #+#    #+#             */
/*   Updated: 2021/02/13 17:58:05 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int				ft_initial_sprite(void)
{
	int			x;
	int			y;
	int			index;

	y = 0;
	index = 0;
	if (!(g_sprite = (t_sprite *)malloc(sizeof(t_sprite) * g_p.count_spri)))
		return (0);
	while (y < g_p.inc)
	{
		x = 0;
		while (x < (int)g_p.len)
		{
			if (g_dt.map[y][x] == '2')
			{
				g_sprite[index].x = x * TL_SZ + TL_SZ / 2;
				g_sprite[index].y = y * TL_SZ + TL_SZ / 2;
				index++;
			}
			x++;
		}
		y++;
	}
	return (0);
}

void			ft_get_data_sprite(void)
{
	int			index;

	index = 0;
	while (index < g_p.count_spri)
	{
		g_sprite[index].dis = hypot(g_pl.x_p - g_sprite[index].x,
				g_pl.y_p - g_sprite[index].y);
		g_sprite[index].ang = atan2((g_sprite[index].y - g_pl.y_p),
				(g_sprite[index].x - g_pl.x_p));
		while ((g_dt.ro_angle - g_dt.fov_angle / 2) -
		g_sprite[index].ang > M_PI)
			g_sprite[index].ang += 2 * M_PI;
		while (g_sprite[index].ang - (g_dt.ro_angle - g_dt.fov_angle / 2)
		> M_PI)
			g_sprite[index].ang -= 2 * M_PI;
		index++;
	}
}

void			ft_sort_dis_sprite(void)
{
	t_sprite	tmp;
	int			i;
	int			j;

	i = 0;
	while (i < g_p.count_spri - 1)
	{
		j = i + 1;
		while (j < g_p.count_spri)
		{
			if (g_sprite[i].dis < g_sprite[j].dis)
			{
				tmp = g_sprite[i];
				g_sprite[i] = g_sprite[j];
				g_sprite[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void			render_sprite(int x, double dis, double stripe_h, int btm)
{
	int			i;
	int			top;
	int			y;
	int			color_spr;

	i = x;
	btm = (g_dt.win_h + stripe_h) / 2;
	while (i < (x + stripe_h))
	{
		top = (g_dt.win_h - stripe_h) / 2;
		y = 0;
		if (i >= 0 && i < g_dt.win_w && dis < g_r1[i].dis_t)
		{
			while (top < btm)
			{
				color_spr = (int)(y / stripe_h * TL_SZ) * TL_SZ;
				color_spr += (int)((i - x) / stripe_h * TL_SZ);
				if (color_spr >= 0 && color_spr < (TL_SZ * TL_SZ))
					my_mlx_pixels_put(i, top, g_tex.addr[4][color_spr]);
				top++;
				y++;
			}
		}
		i++;
	}
}

void			ft_draw_sprite(void)
{
	double		stripe_h;
	double		column_c;
	int			i;
	double		dis_player_pp;

	i = 0;
	dis_player_pp = (g_dt.win_w / 2) / tan(g_dt.fov_angle / 2);
	ft_get_data_sprite();
	ft_sort_dis_sprite();
	while (i < g_p.count_spri)
	{
		stripe_h = (TL_SZ / g_sprite[i].dis) * dis_player_pp;
		column_c = (g_sprite[i].ang - (g_dt.ro_angle - g_dt.fov_angle / 2))
			/ (g_dt.fov_angle / g_dt.win_w);
		render_sprite(column_c - (stripe_h / 2), g_sprite[i].dis, stripe_h, 0);
		i++;
	}
}
