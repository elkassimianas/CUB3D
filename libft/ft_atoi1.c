/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 10:56:23 by ael-kass          #+#    #+#             */
/*   Updated: 2021/01/13 11:34:57 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		is_space(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int		ft_passing(const char *str)
{
	int		i;

	i = 0;
	while (is_space(str[i]))
		i++;
	return (i);
}

int		ft_atoi1(char **str)
{
	long		nb;
	int			sign;
	int			i;

	i = 0;
	nb = 0;
	sign = 1;

	while (str[0][i] >= 48 && str[0][i] <= 57)
	{
		if (nb < 0)
			return ((sign > 0) ? -1 : 0);
		nb = nb * 10 + (str[0][i] - 48);
		i++;
	}
	return (nb * sign);
}
