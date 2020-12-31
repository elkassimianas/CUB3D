/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 12:58:59 by ael-kass          #+#    #+#             */
/*   Updated: 2019/11/06 15:48:40 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char			*dst1;
	const unsigned char		*src1;

	dst1 = (unsigned char *)dst;
	src1 = (const unsigned char *)src;
	if (src1 == dst1)
		return (dst);
	else if (dst1 > src1)
	{
		src1 = src1 + n - 1;
		dst1 = dst1 + n - 1;
		while (n > 0)
		{
			*dst1 = *src1;
			dst1--;
			src1--;
			n--;
		}
	}
	else
		dst = ft_memcpy(dst1, src1, n);
	return (dst);
}
