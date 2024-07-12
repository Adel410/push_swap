/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:03:19 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/07/12 15:30:19 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

void	ft_check_overflow_and_duplicates(char **splitted, long num,
		int current_index)
{
	int	j;

	if (num < INT_MIN || num > INT_MAX)
	{
		ft_free_split(splitted);
		ft_error(4);
	}
	j = 0;
	while (j < current_index)
	{
		if (ft_atol(splitted[j]) == num)
		{
			ft_free_split(splitted);
			ft_error(3);
		}
		j++;
	}
}

int	ft_check_args(char *args)
{
	char	**splitted;
	int		i;
	long	num;

	splitted = ft_split(args, ' ');
	i = 0;
	while (splitted[i])
	{
		if (!ft_is_valid_number(splitted, i, args))
			return (0);
		num = ft_atol(splitted[i]);
		ft_check_overflow_and_duplicates(splitted, num, i);
		i++;
	}
	ft_free_split(splitted);
	return (1);
}

void	ft_check_stack(t_stack **a, t_stack **b)
{
	(void)b;
	if (ft_check_duplicates(*a))
	{
		ft_free_stack(a);
		ft_error(2);
		return ;
	}
	if (ft_check_if_sorted(*a) == 1)
	{
		ft_free_stack(a);
		ft_error(5);
	}
	if (ft_get_sizeof_stack(*a) == 2)
		sa(a);
	if (ft_get_sizeof_stack(*a) == 3)
	{
		ft_sort_three(a);
	}
	else if (ft_get_sizeof_stack(*a) == 4 || ft_get_sizeof_stack(*a) == 5)
		ft_sort_small_stack(a, b);
	else if (ft_get_sizeof_stack(*a) > 3)
		ft_radix_sort(a, b);
}
