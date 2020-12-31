/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:43:26 by ael-kass          #+#    #+#             */
/*   Updated: 2019/11/21 05:21:16 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			ft_strlen(const char *str)
{
	unsigned int		i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int		len;
	unsigned int		i;
	unsigned int		b;
	char				*dst;

	b = 0;
	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		dst[i] = s1[i];
		i++;
	}
	while (s2[b] != '\0')
		dst[i++] = s2[b++];
	dst[i] = '\0';
	return (dst);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*dst;
	unsigned int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (start > (unsigned int)ft_strlen(s))
		len = 0;
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
		return (NULL);
	while (s[start] != '\0' && (i < len))
	{
		dst[i] = s[start];
		i++;
		start++;
	}
	dst[i] = '\0';
	return (dst);
}

char		*ft_strdup(const char *s1)
{
	size_t			i;
	char			*dst;

	i = 0;
	dst = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (dst == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char		*ft_calloc(size_t count, size_t size)
{
	char			*dst;
	size_t			n;
	size_t			i;

	i = 0;
	n = count * size;
	dst = (char *)malloc(n);
	if (dst == NULL)
		return (NULL);
	while (i < n)
	{
		dst[i] = 0;
		i++;
	}
	return (dst);
}
