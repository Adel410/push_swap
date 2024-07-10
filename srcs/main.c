/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:29:12 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/07/10 13:25:07 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_read_stack(t_stack **head)
{
	t_stack	*current;

	current = *head;
	while (current)
	{
		ft_printf("%d\n", current->value);
		current = current->next;
	}
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
