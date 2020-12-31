/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 21:13:04 by ael-kass          #+#    #+#             */
/*   Updated: 2019/11/06 15:45:41 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char			*d1;
	const unsigned char		*s1;
	unsigned char			c1;
	size_t					i;

	d1 = (unsigned char *)dest;
	s1 = (const unsigned char *)src;
	c1 = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		d1[i] = s1[i];
		if (s1[i] == c1)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
