/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:04:36 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/10/27 15:08:15 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ra(t_stack **a)
{
	t_stack	*first;
	t_stack	*last;

	if (*a && (*a)->next)
	{
		first = *a;
		last = *a;
		while (last->next)
			last = last->next;
		*a = first->next;
		first->next = NULL;
		last->next = first;
	}
	ft_putstr("ra\n");
}

void	rb(t_stack **b)
{
	t_stack	*first;
	t_stack	*temp;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	first = *b;
	temp = *b;
	while (temp->next)
		temp = temp->next;
	*b = first->next;
	first->next = NULL;
	temp->next = first;
	ft_putstr("rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	t_stack	*a_last;
	t_stack	*b_last;
	t_stack	*a_first;
	t_stack	*b_first;

	if (*a && (*a)->next && *b && (*b)->next)
	{
		a_first = *a;
		*a = (*a)->next;
		a_last = *a;
		while (a_last->next)
			a_last = a_last->next;
		a_last->next = a_first;
		a_first->next = NULL;
		b_first = *b;
		*b = (*b)->next;
		b_last = *b;
		while (b_last->next)
			b_last = b_last->next;
		b_last->next = b_first;
		b_first->next = NULL;
	}
	ft_putstr("rr\n");
}

void	rra(t_stack **a)
{
	t_stack	*last;
	t_stack	*before_last;

	if (*a && (*a)->next)
	{
		last = *a;
		before_last = NULL;
		while (last->next)
		{
			before_last = last;
			last = last->next;
		}
		if (before_last)
			before_last->next = NULL;
		last->next = *a;
		*a = last;
	}
	ft_putstr("rra\n");
}

void	rrb(t_stack **b)
{
	t_stack	*last;
	t_stack	*before_last;

	if (*b && (*b)->next)
	{
		last = *b;
		before_last = NULL;
		while (last->next)
		{
			before_last = last;
			last = last->next;
		}
		if (before_last)
			before_last->next = NULL;
		last->next = *b;
		*b = last;
	}
	ft_putstr("rrb\n");
}
