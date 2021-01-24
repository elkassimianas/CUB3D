/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 12:35:28 by ael-kass          #+#    #+#             */
/*   Updated: 2021/01/22 18:14:51 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		check_map1(int check)
{
	int		i;

	i = 0;
	while (g_p.ln[i] != '\0')
	{
		if (g_p.ln[i] == ' ' || g_p.ln[i] == '1' || g_p.ln[i] == '0' || g_p.ln[i] == '2')
			i++;
		else if (g_p.ln[i] ==  'N' || g_p.ln[i] == 'S')
		{
			if (check == 0)
				check = 1;
			else
				ft_print_errors(26);
			i++;
		}
		else if (g_p.ln[i] == 'E' || g_p.ln[i] == 'W')
		{
			if (check == 0)
				check = 1;
			else
				ft_print_errors(26);
			i++;
		}
		else
			ft_print_errors(30);
	}
	return (check);
}
