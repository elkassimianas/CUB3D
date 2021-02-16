/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 15:14:44 by ael-kass          #+#    #+#             */
/*   Updated: 2021/01/25 11:52:28 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int			resolution(int b)
{
	char	**line;
	int		f_len;

	line = ft_split(g_p.ln, ' ');
	ft_strlen(line[0]) != 1 ? ft_print_errors(2) : 1;
	if (g_str[0] == '1')
		ft_print_errors(15);
	else
		g_str[0] = '1';
	nu_information(line) != 3 ? ft_print_errors(1) : 3;
	ft_strlen1(line[1]) == -1 ? ft_print_errors(1) : g_dt.win_w;
	g_dt.win_w = ft_strlen1(line[1]) > 4 ? WIN_WMAX : g_dt.win_w;
	g_dt.win_w = (g_dt.win_w != WIN_WMAX) ? ft_atoi(line[1]) : g_dt.win_w;
	g_dt.win_w = g_dt.win_w > WIN_WMAX ? WIN_WMAX : g_dt.win_w;
	ft_strlen1(line[2]) == -1 ? ft_print_errors(1) : g_dt.win_h;
	g_dt.win_h = ft_strlen1(line[2]) > 4 ? WIN_HMAX : g_dt.win_h;
	g_dt.win_h = (g_dt.win_h != WIN_HMAX) ? ft_atoi(line[2]) : g_dt.win_h;
	g_dt.win_h = g_dt.win_h > WIN_HMAX ? WIN_HMAX : g_dt.win_h;
	f_len = len_of_line(line);
	ft_free1(line, f_len);
	return (b + 1);
}

void		ft_floor(char **line)
{
	int		i;
	int		a;
	int		f_len;
	char	**f_free;

	nu_information(line) != 2 ? ft_print_errors(12) : 2;
	i = -1;
	a = 0;
	while (line[1][++i] != '\0')
	{
		if (line[1][i] == ',')
		{
			if (line[1][i + 1] == ',')
				ft_print_errors(13);
			a++;
		}
		a != 2 && line[1][i + 1] == '\0' ? ft_print_errors(13) : a;
	}
	f_free = ft_split(line[1], ',');
	nu_information(f_free) != 3 ? ft_print_errors(12) : 3;
	ft_floor_help(f_free);
	f_len = len_of_line(f_free);
	ft_free1(f_free, f_len);
}

void		ft_ceilling(char **line)
{
	int		i;
	int		a;
	char	**f_free;
	int		f_len;

	nu_information(line) != 2 ? ft_print_errors(14) : 2;
	i = -1;
	a = 0;
	while (line[1][++i] != '\0')
	{
		if (line[1][i] == ',')
		{
			if (line[1][i + 1] == ',')
				ft_print_errors(13);
			a++;
		}
		a != 2 && line[1][i + 1] == '\0' ? ft_print_errors(13) : a;
	}
	f_free = ft_split(line[1], ',');
	nu_information(f_free) != 3 ? ft_print_errors(14) : 2;
	ft_ceilling_help(f_free);
	f_len = len_of_line(f_free);
	ft_free1(f_free, f_len);
}

void		no_so_we_ea_s(int dx1, int dx2)
{
	char	**line;

	line = ft_split(g_p.ln, ' ');
	if (dx1 == 1)
	{
		if (!mlx_xpm_file_to_image(g_dt.mlx, line[1], &g_tex.w,
					&g_tex.h) || nu_information(line) != 2)
		{
			dx2 == 1 ? ft_print_errors(3) : dx2;
			dx2 == 2 ? ft_print_errors(4) : dx2;
			dx2 == 3 ? ft_print_errors(9) : dx2;
			dx2 == 4 ? ft_print_errors(10) : dx2;
			dx2 == 5 ? ft_print_errors(11) : dx2;
		}
		else
		{
			g_tex.fileup = dx2 == 1 ? ft_strdup(line[1]) : g_tex.fileup;
			g_tex.filedown = dx2 == 2 ? ft_strdup(line[1]) : g_tex.filedown;
			g_tex.fileleft = dx2 == 3 ? ft_strdup(line[1]) : g_tex.fileleft;
			g_tex.fileright = dx2 == 4 ? ft_strdup(line[1]) : g_tex.fileright;
			g_tex.filesprite = dx2 == 5 ? ft_strdup(line[1]) : g_tex.filesprite;
		}
	}
	dx1 = len_of_line(line);
	ft_free1(line, dx1);
}

size_t		nu_information(char **line)
{
	size_t		i;

	i = 0;
	while (line[i] != 0)
		i++;
	return (i);
}
