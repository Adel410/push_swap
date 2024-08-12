/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:40:18 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/08/12 17:33:46 by ahadj-ar         ###   ########.fr       */
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
		(sa(a), rra(a));
	else if (first > second && first > third)
		ra(a);
	else if (second > third && first < third)
		(sa(a), ra(a));
	else if (first < second && second > third)
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

void	ft_simplify_stack(t_stack *stack)
{
	t_stack	*current;
	t_stack	*temp;
	int		index;

	current = stack;
	while (current)
	{
		temp = stack;
		index = 0;
		while (temp)
		{
			if (temp->value < current->value)
				index++;
			temp = temp->next;
		}
		current->index = index;
		current = current->next;
	}
}

void	ft_index_sort_stack_b(t_stack **a, t_stack **b, int b_size, int n_bits)
{
	while (b_size-- && !ft_check_if_sorted(*a))
	{
		if ((((*b)->index >> n_bits) & 1) == 0)
			rb(b);
		else
			pa(a, b);
	}
	if (ft_check_if_sorted(*a))
	{
		while (*b)
		{
			pa(a, b);
		}
	}
}

void	ft_index_sort(t_stack **a, t_stack **b)
{
	int	n_bits;
	int	max_bits;
	int	size;

	max_bits = 0;
	ft_simplify_stack(*a);
	size = ft_get_sizeof_stack(*a);
	while (((size - 1) >> max_bits) != 0)
		++max_bits;
	n_bits = 0;
	while (n_bits <= max_bits)
	{
		size = ft_get_sizeof_stack(*a);
		while (size-- && !ft_check_if_sorted(*a))
		{
			if ((((*a)->index >> n_bits) & 1) == 0)
				pb(a, b);
			else
				ra(a);
		}
		ft_index_sort_stack_b(a, b, ft_get_sizeof_stack(*b), n_bits + 1);
		n_bits++;
	}
	while (*b)
		pa(a, b);
}
