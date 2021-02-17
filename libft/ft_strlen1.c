/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 09:05:52 by ael-kass          #+#    #+#             */
/*   Updated: 2021/02/16 09:06:18 by ael-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strlen1(const char *str)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	while (str[j] == '0')
		j++;
	while (str[i] != '\0')
    {
		if(!ft_isdigit(str[i]))
        	return (-1);
        i++;
    }
	i -= j;
    return (i);
}
