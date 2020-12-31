/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 19:46:26 by ael-kass          #+#    #+#             */
/*   Updated: 2019/11/06 18:16:40 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	int		i;
	int		a;
	char	*dst;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	a = ft_strlen(s);
	dst = (char *)malloc(sizeof(char) * (a + 1));
	if (dst == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		dst[i] = f(i, s[i]);
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
