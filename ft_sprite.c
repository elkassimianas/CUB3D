/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaji-el <hnaji-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 17:27:59 by hnaji-el          #+#    #+#             */
/*   Updated: 2021/02/07 22:12:25 by hnaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void        ft_initial_sprite(void)
{
    int     x;
    int     y;
    int     index;

    y = 0;
    index = 0;
    if (!(g_sprite = (t_sprite *)malloc(sizeof(t_sprite) * g_c.count_spr)))
        return (NULL);
    while (y < g_c.square_y)
    {
        x = 0;
        while (x < g_c.square_x)
        {
            if (g_c.m[y][x] == '2')
            {
                g_sprite[index].x = x * TL_SZ + TL_SZ / 2;
                g_sprite[index].y = y * TL_SZ + TL_SZ / 2;
                index++;
            }
            x++;
        }
        y++;
    }
}

void    ft_get_data_sprite(void)
{
    int     index;

    index = 0;
    while (index < g_c.count_spr)
    {
        sprite[index].dis = hypot(g_p.pos_x - sprite[index].x,
         g_p.pos_y - sprite[index].y);
        sprite[index].ang = atan2((sprite[index].y - g_p.pos_y),
         (sprite[index].x - g_p.pos_x));
        if ((g_p.rot_ang - FOV / 2) - sprite[index].ang > M_PI)
			sprite[index].ang += 2 * M_PI;
		if (sprite[index].ang - (g_p.rot_ang - FOV / 2) > M_PI)
			sprite[index].ang -= 2 * M_PI;
        index++;
    }
}

void    ft_sort_dis_sprite(t_spr *sprite)
{
    t_spr   tmp;
    int     i;
    int     j;

    i = 0;
    while (i < g_c.count_spr - 1)
    {
        j = i + 1;
        while (j < g_c.count_spr)
        {
            if (sprite[i].dis < sprite[j].dis)
            {
                tmp = sprite[i];
                sprite[i] = sprite[j];
                sprite[j] = tmp;
            }
            j++;
        }
        i++;
    }
}

void	ft_render_sprite(int x, double distance, double stripe_h, int bottom)
{
	int		i;
	int		top;
	int		y;
    int     color_spr;

	i = x;
    bottom = (g_c.win_h + stripe_h) / 2;
	while (i < (x + stripe_h))
	{
		top = (g_c.win_h - stripe_h) / 2;
		y = 0;
		if (i >= 0 && i < g_c.win_w && distance < g_rays[i].ray_dis)
		{
			while (top < bottom)
			{
                color_spr = (int)(y / stripe_h * TILE_SIZE) * TILE_SIZE;
                color_spr += (int)((i - x) / stripe_h * TILE_SIZE);
                if (color_spr >= 0 && color_spr < (TILE_SIZE * TILE_SIZE))
				    my_mlx_spixel_put(i, top, g_t.ts_add[4][color_spr]);
				top++;
				y++;
			}
		}
		i++;
	}
}

void	ft_draw_sprite(t_spr *sprite)
{
	double  stripe_h;
    double  column_c;
    int		i;
    double  dis_player_pp;

	i = 0;
    dis_player_pp = (g_c.win_w / 2) / tan(FOV / 2);
	ft_get_data_sprite(sprite);
	ft_sort_dis_sprite(sprite);
	while (i < g_c.count_spr)
	{
		stripe_h = (TILE_SIZE / sprite[i].dis) * dis_player_pp;
		column_c = (sprite[i].ang - (g_p.rot_ang - FOV / 2)) / (FOV / g_c.win_w);
		ft_render_sprite(column_c - (stripe_h / 2), sprite[i].dis, stripe_h, 0);
		i++;
	}
}

