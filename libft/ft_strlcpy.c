/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 12:23:50 by ael-kass          #+#    #+#             */
/*   Updated: 2019/11/06 15:58:07 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const	char *src, size_t dstsize)
{
	size_t		len_src;
	size_t		f;
	size_t		a;

	a = 0;
	len_src = ft_strlen(src);
	if (dstsize == 0)
		return (len_src);
	f = dstsize - 1;
	while (f > 0 && src[a] != '\0')
	{
		dst[a] = src[a];
		a++;
		f--;
	}
	dst[a] = '\0';
	return (len_src);
}
