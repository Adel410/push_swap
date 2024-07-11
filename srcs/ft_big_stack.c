/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:40:18 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/07/11 19:42:28 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

void	ft_radix_sort_stack_b(t_stack **a, t_stack **b, int b_size, int octet)
{
	while (b_size-- && !ft_check_if_sorted(*a))
	{
		if ((((*b)->index >> octet) & 1) == 0)
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

void	ft_radix_sort(t_stack **a, t_stack **b)
{
	int	octet;
	int	max_bits;
	int	size;

	max_bits = 0;
	ft_simplify_stack(*a);
	size = ft_get_sizeof_stack(*a);
	while (((size - 1) >> max_bits) != 0)
		++max_bits;
	octet = 0;
	while (octet <= max_bits)
	{
		size = ft_get_sizeof_stack(*a);
		while (size-- && !ft_check_if_sorted(*a))
		{
			if ((((*a)->index >> octet) & 1) == 0)
				pb(a, b);
			else
				ra(a);
		}
		ft_radix_sort_stack_b(a, b, ft_get_sizeof_stack(*b), octet + 1);
		octet++;
	}
	while (*b)
		pa(a, b);
}
