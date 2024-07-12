/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:29:36 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/07/12 12:10:40 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_get_sizeof_stack(t_stack *head)
{
	int		size;
	t_stack	*temp;

	size = 0;
	temp = head;
	while (temp)
	{
		size++;
		temp = temp->next;
	}
	return (size);
}

t_stack	*ft_lstnew_int(int value)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back_stack(t_stack **lst, t_stack *new)
{
	t_stack	*temp;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

int	ft_find_min_position(t_stack *stack)
{
	int		min;
	int		pos;
	int		min_pos;
	t_stack	*current;

	min = stack->value;
	pos = 0;
	min_pos = 0;
	current = stack;
	while (current)
	{
		if (current->value < min)
		{
			min = current->value;
			min_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (min_pos);
}
