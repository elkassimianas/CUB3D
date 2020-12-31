/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 10:41:22 by ael-kass          #+#    #+#             */
/*   Updated: 2019/11/06 18:20:02 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char		*a;
	const unsigned char		*b;
	size_t					r;
	size_t					i;

	a = (const unsigned char *)s1;
	b = (const unsigned char *)s2;
	i = 0;
	r = 0;
	if (n == 0)
		return (r);
	while ((a[i] == b[i] && a[i] != '\0') && i < n)
		i++;
	if (i == n)
		i--;
	r = a[i] - b[i];
	return (r);
}
