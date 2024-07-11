/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:03:19 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/07/11 22:52:53 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

long	ft_atol(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (sign * result);
}

static int	ft_is_valid_number(char **splitted, int current_index, char *args)
{
	char	*str;

	str = splitted[current_index];
	if (*str == '-' || *str == '+')
		str++;
	if (*str == '\0')
	{
		ft_free_split(splitted);
		free(args);
		ft_error(2);
	}
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
		{
			ft_free_split(splitted);
			free(args);
			ft_error(2);
		}
		str++;
	}
	return (1);
}

int	ft_check_overflow(char **splitted, long num, char *args)
{
	if (num < INT_MIN || num > INT_MAX)
	{
		ft_free_split(splitted);
		free(args);
		ft_error(4);
	}
	return (0);
}

static int	ft_has_duplicates(char **splitted, int current_index, long num,
		char *args)
{
	int	j;

	j = 0;
	while (j < current_index)
	{
		if (ft_atol(splitted[j]) == num)
		{
			ft_free_split(splitted);
			free(args);
			ft_error(3);
			return (1);
		}
		j++;
	}
	return (0);
}

int	ft_check_args(char *args)
{
	char	**splitted;
	long	num;
	int		i;

	splitted = ft_split(args, ' ');
	if (!splitted)
	{
		free(args);
		return (1);
	}
	i = 0;
	while (splitted[i])
	{
		ft_is_valid_number(splitted, i, args);
		num = ft_atol(splitted[i]);
		ft_check_overflow(splitted, num, args);
		ft_has_duplicates(splitted, i, num, args);
		i++;
	}
	ft_free_split(splitted);
	return (0);
}
