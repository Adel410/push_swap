/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:37:58 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/07/12 15:32:30 by ahadj-ar         ###   ########.fr       */
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

static int	calc_total_length(char **argv, int index, int acc)
{
	if (argv[index] == NULL)
		return (acc);
	if (index > 1)
		acc += 1;
	acc += ft_strlen(argv[index]);
	return (calc_total_length(argv, index + 1, acc));
}

char	*concat_args(int argc, char **argv)
{
	int		len;
	char	*all_args;
	int		index;

	if (argc == 1)
		ft_error(1);
	if (argc == 2)
		return (ft_strdup(argv[1]));
	len = calc_total_length(argv, 1, 0);
	all_args = ft_calloc(len + 1, sizeof(char));
	if (!all_args)
		ft_error(1);
	all_args[0] = '\0';
	index = 1;
	while (argv[index] != NULL)
	{
		if (index > 1)
			ft_strcat(all_args, " ");
		ft_strcat(all_args, argv[index]);
		index++;
	}
	return (all_args);
}
