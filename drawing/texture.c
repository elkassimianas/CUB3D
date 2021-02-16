/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 09:44:39 by ael-kass          #+#    #+#             */
/*   Updated: 2021/02/14 10:51:19 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		buffertexture(void)
{
	int		i;

	g_dataimg[0] =
	mlx_xpm_file_to_image(g_dt.mlx, g_tex.fileup, &g_tex.w, &g_tex.h);
	ft_free(&g_tex.fileup);
	g_dataimg[1] =
	mlx_xpm_file_to_image(g_dt.mlx, g_tex.filedown, &g_tex.w, &g_tex.h);
	ft_free(&g_tex.filedown);
	g_dataimg[2] =
	mlx_xpm_file_to_image(g_dt.mlx, g_tex.fileleft, &g_tex.w, &g_tex.h);
	ft_free(&g_tex.fileleft);
	g_dataimg[3] =
	mlx_xpm_file_to_image(g_dt.mlx, g_tex.fileright, &g_tex.w, &g_tex.h);
	ft_free(&g_tex.fileright);
	g_dataimg[4] =
	mlx_xpm_file_to_image(g_dt.mlx, g_tex.filesprite, &g_tex.w, &g_tex.h);
	ft_free(&g_tex.filesprite);
	i = -1;
	while (++i < 5)
	{
		g_tex.addr[i] = (int *)mlx_get_data_addr(g_dataimg[i],
		&g_dt.bits_per_pixel, &g_dt.line_length, &g_dt.endian);
	}
}

void		my_mlx_pixels_put(int x, int y, int color_spr)
{
	if (y < g_dt.win_h && y >= 0 && color_spr > 0x000000)
		g_dt.addr[(y * g_dt.win_w) + x] = color_spr;
}

double		normalizeangle(double angle)
{
	angle = (angle - (int)(angle / (2 * M_PI)) * (2 * M_PI));
	if (angle < 0)
		angle = (2 * M_PI) + angle;
	return (angle);
}

int			create_trgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int			put_check_ceilling(int i, int b)
{
	char	**line;
	int		f_len;

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
