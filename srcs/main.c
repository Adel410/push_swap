/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:29:12 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/07/12 15:30:53 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*ft_args_to_stack(char *all_args, t_stack *head)
{
	char	**args;
	int		index;
	int		value;
	t_stack	*new_node;

	index = 0;
	args = ft_split(all_args, ' ');
	if (!args)
		return (NULL);
	while (args[index] != NULL)
	{
		value = ft_atol(args[index]);
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
	ft_check_args(all_args);
	*a = ft_args_to_stack(all_args, *a);
	free(all_args);
	ft_check_stack(a, b);
	ft_free_stack(a);
	ft_free_stack(b);
}
