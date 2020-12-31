/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:41:32 by ael-kass          #+#    #+#             */
/*   Updated: 2019/11/21 05:12:06 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_free(char **s)
{
	if (*s)
	{
		free(*s);
		*s = NULL;
	}
	return (-1);
}

int		ft_helpline(int i, char ***save, char **buffer)
{
	if (i < 0)
	{
		ft_free(&(**save));
		ft_free(&(*buffer));
		return (-1);
	}
	return (1);
}

int		ft_affect(int fd, char **save, char **buffer)
{
	char	*tmp2;
	int		ret2;
	int		len;
	int		i;

	i = 1;
	len = 0;
	while (i > 0)
	{
		i = read(fd, *buffer, BUFFER_SIZE);
		(*buffer)[i] = '\0';
		if ((ret2 = ft_helpline(i, &save, buffer)) < 0)
			return (-1);
		tmp2 = *save;
		if (!(*save = ft_strjoin(*save, *buffer)))
			return (-1);
		ft_free(&tmp2);
		while ((*save)[len] != '\0' && (*save)[len] != '\n')
			len++;
		if ((*save)[len] == '\n')
			break ;
	}
	return (len);
}

int		ft_linen(char **save, char ***line, int len)
{
	char	*tmp;

	if ((*save)[len] == '\n')
	{
		**line = ft_substr(*save, 0, len);
		if (**line == NULL)
			return (-1);
		tmp = *save;
		*save = ft_strdup(*save + len + 1);
		if (*save == NULL)
			return (-1);
		free(tmp);
		tmp = NULL;
		return (1);
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char		*save;
	char			*buffer;
	int				ret;
	int				len;

	if (BUFFER_SIZE < 0 || fd < 0 || line == NULL)
		return (-1);
	if (!(buffer = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char))))
		return (-1);
	if (save == NULL)
		if (!(save = (char *)ft_calloc(1, sizeof(char))))
			return (-1);
	len = ft_affect(fd, &save, &buffer);
	ft_free(&buffer);
	if (len < 0)
		return (-1);
	ret = ft_linen(&save, &line, len);
	if (ret == 1)
		return (1);
	if (save[len] == '\0')
		if (!(*line = ft_substr(save, 0, len)))
			return (-1);
	ft_free(&save);
	return (0);
}
