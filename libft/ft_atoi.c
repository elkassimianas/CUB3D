/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:58:58 by ael-kass          #+#    #+#             */
/*   Updated: 2021/01/14 10:08:04 by ael-kass         ###   ########.fr       */
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

int		ft_atoi(const char *str)
{
	long		nb;
	int			sign;
	int			i;

	i = 0;
	nb = 0;
	sign = 1;
	if (str[i] == '-')
		return (-1);
	while (str[i] >= 48 && str[i] <= 57)
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	if (ft_isdigit(str[i]) == 0 && str[i] != '\0')
		return (-1);
	return (nb * sign);
}
