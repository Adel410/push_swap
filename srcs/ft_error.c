/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:31:27 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/10/27 15:07:43 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_error(int i)
{
	if (i == 1)
		ft_putstr("Error.\nWrong number of argument.\n");
	if (i == 2)
		ft_putstr("Error.\nWrong types of arguments.\n");
	if (i == 3)
		ft_putstr("Error.\nThere are duplicates.\n");
	if (i == 4)
		ft_putstr("Error.\nThere is an overflow.\n");
	if (i == 5)
		ft_putstr("");
	exit(1);
}

int	ft_secu(int argc, char *argv[])
{
	(void)argv;
	if (argc <= 1)
		return (1);
	return (0);
}

void	ft_cleanup(t_stack **a, t_stack **b, char *str)
{
	if (str)
		ft_putstr(str);
	if (a)
		ft_free_stack(a);
	if (b)
		ft_free_stack(b);
	exit(1);
}
