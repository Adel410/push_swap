/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:03:19 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/08/12 17:19:42 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_check_stack(t_stack **a, t_stack **b)
{
	if (ft_check_if_sorted(*a) == 1)
	{
		ft_free_stack(a);
		ft_error(5);
	}
	if (ft_get_sizeof_stack(*a) == 2)
		sa(a);
	else if (ft_get_sizeof_stack(*a) == 3)
	{
		ft_sort_three(a);
	}
	else if (ft_get_sizeof_stack(*a) == 4 || ft_get_sizeof_stack(*a) == 5)
		ft_sort_small_stack(a, b);
	else if (ft_get_sizeof_stack(*a) > 3)
		ft_index_sort(a, b);
}
