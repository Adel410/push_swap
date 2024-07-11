/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:44:03 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/07/11 22:48:24 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_check_duplicates(t_stack *head)
{
	t_stack	*current;
	t_stack	*next_node;

	current = head;
	while (current && current->next)
	{
		next_node = current->next;
		while (next_node)
		{
			if (current->value == next_node->value)
			{
				return (1);
			}
			next_node = next_node->next;
		}
		current = current->next;
	}
	return (0);
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
