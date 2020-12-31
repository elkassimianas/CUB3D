/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:34:35 by ael-kass          #+#    #+#             */
/*   Updated: 2019/11/06 16:00:48 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		len_src;
	size_t		len_dst;
	size_t		i;
	size_t		f;
	size_t		a;

	a = 0;
	len_src = ft_strlen(src);
	if (size == 0)
		return (len_src + size);
	len_dst = ft_strlen(dst);
	i = len_dst + len_src;
	if (size <= len_dst)
		return (len_src + size);
	f = size - len_dst - 1;
	while (f-- > 0 && src[a] != '\0')
		dst[len_dst++] = src[a++];
	dst[len_dst] = '\0';
	return (i);
}
