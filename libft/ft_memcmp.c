/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 11:32:29 by ael-kass          #+#    #+#             */
/*   Updated: 2019/11/06 15:57:09 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char		*e1;
	const unsigned char		*e2;
	size_t					i;
	size_t					r;

	e1 = (const unsigned char *)s1;
	e2 = (const unsigned char *)s2;
	i = 0;
	r = 0;
	while (i < n)
	{
		if (e1[i] != e2[i])
		{
			r = e1[i] - e2[i];
			return (r);
		}
		i++;
	}
	return (r);
}
