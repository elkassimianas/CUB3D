/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 11:11:02 by ael-kass          #+#    #+#             */
/*   Updated: 2019/11/06 14:51:57 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *p, int c, size_t n)
{
	unsigned char	*e;
	size_t			i;

	e = (unsigned char *)p;
	i = 0;
	while (i < n)
	{
		e[i] = (unsigned char)c;
		i++;
	}
	return (p);
}
