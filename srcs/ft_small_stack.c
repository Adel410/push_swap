/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:49:08 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/07/10 16:56:38 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_rotate_to_position(t_stack **stack, int position,
		void (*rotate)(t_stack **), void (*reverse_rotate)(t_stack **))
{
	int	size;

	size = ft_get_sizeof_stack(*stack);
	if (position <= size / 2)
	{
		while (position--)
			rotate(stack);
	}
	else
	{
		while (position++ < size)
			reverse_rotate(stack);
	}
}

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

void	ft_insert_sorted(t_stack **a, t_stack **b)
{
	int	b_val;
	int	size;
	int	pos;

	b_val = (*b)->value;
	size = ft_get_sizeof_stack(*a);
	pos = 0;
	while (pos < size && (*a)->value < b_val)
	{
		ra(a);
		pos++;
	}
	pa(a, b);
	while (pos > 0)
	{
		rra(a);
		pos--;
	}
}

void	ft_sort_stack_of_four_or_five(t_stack **a, t_stack **b)
{
	int	size;
	int	min_pos;

	size = ft_get_sizeof_stack(*a);
	while (size > 3)
	{
		min_pos = ft_find_min_position(*a);
		ft_rotate_to_position(a, min_pos, ra, rra);
		pb(a, b);
		size--;
	}
	ft_sort_three(a);
	while (*b)
	{
		ft_insert_sorted(a, b);
	}
}
