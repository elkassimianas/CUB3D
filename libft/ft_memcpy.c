/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 10:45:29 by ael-kass          #+#    #+#             */
/*   Updated: 2019/11/06 15:05:28 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char			*s1;
	const unsigned char		*s2;
	size_t					i;

	s1 = (unsigned char *)dest;
	s2 = (const unsigned char *)src;
	i = 0;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == s2)
		return (dest);
	while (i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	return (dest);
}
