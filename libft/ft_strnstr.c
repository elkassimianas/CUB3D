/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 11:05:33 by ael-kass          #+#    #+#             */
/*   Updated: 2019/11/06 16:32:02 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	a;
	size_t	j;
	size_t	b;

	a = 0;
	if (s2[a] == '\0')
		return ((char *)s1);
	if (s1 == NULL && n == 0)
		return (NULL);
	while ((s1[a] != '\0') && n > 0)
	{
		b = 0;
		j = n;
		while (s1[a + b] == s2[b] && j > 0)
		{
			if (s2[b + 1] == '\0')
				return ((char *)s1 + a);
			j--;
			b++;
		}
		a++;
		n--;
	}
	return (NULL);
}
