/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:49:08 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/07/11 22:47:58 by ahadj-ar         ###   ########.fr       */
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
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

void	ft_sort_small_stack(t_stack **a, t_stack **b)
{
	int	size;
	int	min_pos;

	size = ft_get_sizeof_stack(*a);
	while (size > 3)
	{
		min_pos = ft_find_min_position(*a);
		while (min_pos > 0)
		{
			ra(a);
			min_pos--;
		}
		pb(a, b);
		size--;
	}
	ft_sort_three(a);
	while (*b)
	{
		pa(a, b);
		if ((*a)->value > (*a)->next->value)
			sa(a);
	}
}
