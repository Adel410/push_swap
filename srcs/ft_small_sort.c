/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:28:52 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/08/13 16:32:50 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && first > third)
		ra(a);
	else if (second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third)
		rra(a);
}

void	ft_push_min_to_b(t_stack **a, t_stack **b, int *size)
{
	int	min_pos;

	min_pos = ft_find_min_position(*a);
	while (min_pos > 0)
	{
		if (min_pos > *size / 2)
		{
			rra(a);
			min_pos++;
			if (min_pos == *size)
				min_pos = 0;
		}
		else
		{
			ra(a);
			min_pos--;
		}
	}
	pb(a, b);
	(*size)--;
}

void	ft_sort_small_stack(t_stack **a, t_stack **b)
{
	int	size;

	size = ft_get_sizeof_stack(*a);
	while (size > 3)
		ft_push_min_to_b(a, b, &size);
	ft_sort_three(a);
	while (*b)
	{
		pa(a, b);
		while ((*a)->value > (*a)->next->value)
			ra(a);
	}
}
