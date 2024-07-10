/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:00:46 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/07/10 16:49:59 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa(t_stack **a)
{
	t_stack	*first;
	t_stack	*second;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	first = *a;
	second = (*a)->next;
	first->next = second->next;
	second->next = first;
	*a = second;
	ft_printf("sa\n");
}

void	sb(t_stack **b)
{
	t_stack	*first;
	t_stack	*second;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	first = *b;
	second = (*b)->next;
	first->next = second->next;
	second->next = first;
	*b = second;
	ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b)
{
	t_stack	*first_a;
	t_stack	*second_a;
	t_stack	*first_b;
	t_stack	*second_b;

	if (*a && (*a)->next && *b && (*b)->next)
	{
		first_a = *a;
		second_a = (*a)->next;
		first_b = *b;
		second_b = (*b)->next;
		first_a->next = second_a->next;
		second_a->next = first_a;
		*a = second_a;
		first_b->next = second_b->next;
		second_b->next = first_b;
		*b = second_b;
		ft_printf("ss\n");
	}
}
