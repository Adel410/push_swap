/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:31:27 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/07/02 17:55:53 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_error(int i)
{
	if (i == 1)
		ft_printf("Error.\nWrong number of argument.\n");
	if (i == 2)
		ft_printf("Error.\nWrong types of arguments.\n");
	if (i == 3)
		ft_printf("Error.\nThere are duplicates.\n");
	if (i == 4)
		ft_printf("Error.\nThere is an overflow.\n");
	if (i == 5)
		ft_printf("Stack is already sorted.\n");
	exit(1);
}

int	ft_secu(int argc, char *argv[])
{
	(void)argv;
	if (argc <= 1)
		ft_error(1);
	return (0);
}
