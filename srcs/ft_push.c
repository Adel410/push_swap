/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:03:22 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/07/10 16:47:15 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (*b)
	{
		temp = *b;
		*b = (*b)->next;
		temp->next = *a;
		*a = temp;
	}
	ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (*a)
	{
		temp = *a;
		*a = (*a)->next;
		temp->next = *b;
		*b = temp;
	}
	ft_printf("pb\n");
}

void	rotate_stack(t_stack **s)
{
	t_stack	*last;
	t_stack	*prev;

	last = *s;
	prev = NULL;
	if (*s && (*s)->next)
	{
		while (last->next)
		{
			prev = last;
			last = last->next;
		}
		prev->next = NULL;
		last->next = *s;
		*s = last;
	}
}

void	rrr(t_stack **a, t_stack **b)
{
	rotate_stack(a);
	rotate_stack(b);
	ft_printf("rrr\n");
}
