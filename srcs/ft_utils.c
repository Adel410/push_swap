/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:29:36 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/07/10 16:57:07 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	*ft_strcat(char *dest, const char *src)
{
	int	dest_len;
	int	i;

	dest_len = 0;
	i = 0;
	while (dest[dest_len] != '\0')
	{
		dest_len++;
	}
	while (src[i] != '\0')
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest);
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

t_stack	*ft_find_max(t_stack **a)
{
	t_stack	*temp;
	t_stack	*biggest;

	temp = *a;
	while (temp->next)
	{
		if (temp->value > temp->next->value)
		{
			biggest = temp;
		}
		else
		{
			biggest = temp;
		}
		temp = temp->next;
	}
	return (biggest);
}

int	ft_find_min_position(t_stack *stack)
{
	int min;
	int pos;
	int min_pos;
	t_stack *current;

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