/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:37:58 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/07/12 15:21:33 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_check_if_sorted(t_stack *head)
{
	t_stack	*temp;

	if (!head)
		return (1);
	temp = head;
	while (temp->next)
	{
		if (temp->value > temp->next->value)
		{
			return (0);
		}
		temp = temp->next;
	}
	return (1);
}

static int	calc_total_length(char **argv, int index, int acc)
{
	if (argv[index] == NULL)
		return (acc);
	if (index > 1)
		acc += 1;
	acc += ft_strlen(argv[index]);
	return (calc_total_length(argv, index + 1, acc));
}

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

void	ft_free_stack(t_stack **head)
{
	t_stack	*current;
	t_stack	*next;

	current = *head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(head);
}

void	ft_alloc_failed(t_stack *head, char **split)
{
	ft_free_stack(&head);
	ft_free_split(split);
	exit(1);
}
