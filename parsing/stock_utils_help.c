/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_utils_help.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 10:43:03 by ael-kass          #+#    #+#             */
/*   Updated: 2021/02/14 10:43:42 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		ft_floor_help(char **f_free)
{
	ft_strlen1(f_free[0]) > 3 ? ft_print_errors(12) : 3;
	g_tex.rf = ft_atoi(f_free[0]);
	g_tex.rf == -1 || g_tex.rf > 255 ? ft_print_errors(12) : g_tex.rf;
	ft_strlen1(f_free[1]) > 3 ? ft_print_errors(12) : 3;
	g_tex.gf = ft_atoi(f_free[1]);
	g_tex.gf == -1 || g_tex.gf > 255 ? ft_print_errors(12) : g_tex.gf;
	ft_strlen1(f_free[2]) > 3 ? ft_print_errors(12) : 3;
	g_tex.bf = ft_atoi(f_free[2]);
	g_tex.bf == -1 || g_tex.bf > 255 ? ft_print_errors(12) : g_tex.bf;
}

void		ft_ceilling_help(char **f_free)
{
	ft_strlen1(f_free[0]) > 3 ? ft_print_errors(14) : 3;
	g_tex.rc = ft_atoi(f_free[0]);
	g_tex.rc == -1 || g_tex.rc > 255 ? ft_print_errors(14) : g_tex.rc;
	ft_strlen1(f_free[1]) > 3 ? ft_print_errors(14) : 3;
	g_tex.gc = ft_atoi(f_free[1]);
	g_tex.gc == -1 || g_tex.gc > 255 ? ft_print_errors(14) : g_tex.gc;
	ft_strlen1(f_free[2]) > 3 ? ft_print_errors(14) : 3;
	g_tex.bc = ft_atoi(f_free[2]);
	g_tex.bc == -1 || g_tex.bc > 255 ? ft_print_errors(14) : g_tex.bc;
}

int			haswallat(double x, double y)
{
	int	mapindex_x;
	int	mapindex_y;

	if (x < 0 || x >= g_dt.img_w || y < 0 || y >= g_dt.img_h)
		return (1);
	mapindex_x = floor(x / TL_SZ);
	mapindex_y = floor(y / TL_SZ);
	if (g_dt.map[mapindex_y][mapindex_x] == '1')
		return (1);
	return (0);
}
