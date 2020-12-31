/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 16:28:50 by ael-kass          #+#    #+#             */
/*   Updated: 2019/11/03 22:47:47 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		f_strcmp1(char const *s1, char const *s2)
{
	int		b;
	int		c;
	int		nb;

	b = 0;
	c = 0;
	while (s1[b] != '\0')
	{
		while (s2[c] != '\0')
		{
			nb = s1[b] - s2[c];
			if (nb == 0)
				break ;
			else
				c++;
		}
		c = 0;
		if (nb != 0)
			break ;
		else
			b++;
	}
	return (b);
}

int		f_strcmp2(char const *s1, char const *s2)
{
	int		i;
	int		a;
	int		nb;
	int		c;

	c = 0;
	a = 0;
	i = ft_strlen(s1) - 1;
	while (i >= a)
	{
		while (s2[c] != '\0')
		{
			nb = s1[i] - s2[c];
			if (nb == 0)
				break ;
			else
				c++;
		}
		c = 0;
		if (nb != 0)
			break ;
		else
			i--;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	int		i;
	int		b;
	int		d;
	char	*dst;

	if (!s1 || set == NULL)
		return (NULL);
	if (set == '\0')
		return (ft_strdup(s1));
	d = 0;
	b = f_strcmp1(s1, set);
	i = f_strcmp2(s1, set);
	if ((i - b + 1) < 0)
	{
		dst = (char *)malloc(sizeof(char) * 1);
		if (dst == NULL)
			return (NULL);
		dst[0] = '\0';
		return (dst);
	}
	len = i - b + 1;
	dst = ft_substr(s1, b, len);
	return (dst);
}
