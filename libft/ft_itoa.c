/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:23:59 by ael-kass          #+#    #+#             */
/*   Updated: 2019/11/05 16:24:16 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*condit(char *dst, unsigned int n, int i)
{
	int		a;

	if (n > 0)
	{
		while (n != 0)
		{
			a = n % 10;
			n = n / 10;
			dst[i] = a + 48;
			i--;
		}
		return (dst);
	}
	if (n == 0)
		dst[i] = n + 48;
	return (dst);
}

char	*effect(char *dst, int n, int len)
{
	int				i;
	unsigned int	b;

	i = len - 1;
	dst[i + 1] = '\0';
	if (n < 0)
	{
		dst[0] = 45;
		b = n * (-1);
		dst = condit(dst, b, i);
		return (dst);
	}
	else if (n >= 0)
	{
		dst = condit(dst, n, i);
		return (dst);
	}
	return (0);
}

char	*ft_itoa(int n)
{
	int		a;
	int		i;
	char	*dst;

	i = 0;
	if (n == 0)
	{
		dst = (char *)malloc(sizeof(char) * n + 2);
		return (dst == NULL ? (NULL) : effect(dst, n, 1));
	}
	if ((a = n) < 0)
	{
		while (a /= 10)
			i++;
		i++;
		i++;
	}
	while (a > 0 && a != 0)
	{
		a = a / 10;
		i++;
	}
	dst = (char *)malloc(i + 1);
	return (dst == NULL ? (NULL) : effect(dst, n, i));
}
