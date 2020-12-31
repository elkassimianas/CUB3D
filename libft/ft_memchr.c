/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 18:58:21 by ael-kass          #+#    #+#             */
/*   Updated: 2019/11/06 15:50:56 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int ch, size_t n)
{
	const unsigned char		*e;
	unsigned char			a;
	size_t					i;

	e = (const unsigned char *)s;
	a = (unsigned char)ch;
	i = 0;
	while (i < n)
	{
		if (e[i] == a)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
