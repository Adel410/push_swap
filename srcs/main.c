/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:29:12 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/08/12 17:12:53 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_free_node(t_stack *head)
{
	t_stack	*temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

int	ft_is_valid_number(char *str, char **args, t_stack *head)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			ft_printf("Invalid arguments\n");
			ft_free_node(head);
			ft_free_split(args);
			return (-1);
		}
		i++;
	}
	return (0);
}

int	ft_check_overflow(long value, char **args, t_stack *head)
{
	if (value > INT_MAX || value < INT_MIN)
	{
		ft_printf("Overflow\n");
		ft_free_node(head);
		ft_free_split(args);
		return (-1);
	}
	return (0);
}

t_stack	*ft_args_to_stack(char *all_args, t_stack *head)
{
	char	**args;
	int		index;
	long	value;
	t_stack	*new_node;

	index = 0;
	args = ft_split(all_args, ' ');
	if (!args)
		return (NULL);
	while (args[index] != NULL)
	{
		new_node = NULL;
		if (ft_is_valid_number(args[index], args, head) == -1)
			return (NULL);
		value = ft_atol(args[index]);
		if (ft_check_overflow(value, args, head) == -1)
			return (NULL);
		new_node = ft_lstnew_int(value);
		if (!new_node)
			ft_alloc_failed(head, args);
		ft_lstadd_back_stack(&head, new_node);
		index++;
	}
	ft_free_split(args);
	return (head);
}

int	main(int argc, char *argv[])
{
	t_stack	**a;
	t_stack	**b;
	char	*all_args;

	a = (t_stack **)malloc(sizeof(t_stack));
	b = (t_stack **)malloc(sizeof(t_stack));
	*a = NULL;
	*b = NULL;
	ft_secu(argc, argv);
	all_args = concat_args(argc, argv);
	if (!all_args)
		ft_error(1);
	*a = ft_args_to_stack(all_args, *a);
	free(all_args);
	if (*a == NULL || a == NULL)
		ft_cleanup(a, b, "");
	if (ft_check_duplicates(*a) == 1)
		ft_cleanup(a, b, "There is duplicates\n");
	ft_check_stack(a, b);
	ft_cleanup(a, b, "");
}
