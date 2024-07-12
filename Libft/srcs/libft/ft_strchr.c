/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:27:27 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/07/12 11:26:04 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

static int	ft_strlen_stat(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int searched)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen_stat(str);
	while (str[i])
	{
		if (str[i] == (unsigned char)searched)
		{
			return ((char *)&str[i]);
		}
		i++;
	}
	if ((unsigned char)searched == '\0')
	{
		return ((char *)&str[size]);
	}
	return (NULL);
}
