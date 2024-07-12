/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:29:45 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/07/12 15:21:48 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft/includes/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

// STRUCTURE

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;

// STACK MANAGMENT FUNCTIONS

t_stack				*ft_lstnew_int(int value);
t_stack				*get_next_min(t_stack **stack);
t_stack				*ft_args_to_stack(char *all_args, t_stack *head);
int					ft_get_sizeof_stack(t_stack *head);
int					ft_find_min_position(t_stack *a);
void				ft_lstadd_back_stack(t_stack **lst, t_stack *new);
void				ft_free_stack(t_stack **head);
void				ft_read_stack(t_stack **head);

// SORTING FUNCTIONS

void				ft_radix_sort(t_stack **a, t_stack **b);
void				ft_sort_three(t_stack **a);
void				ft_sort_small_stack(t_stack **a, t_stack **b);

// CHECKERS AND VALIDATIONS FUNCTIONS

int					ft_check_if_sorted(t_stack *head);
void				ft_check_stack(t_stack **a, t_stack **b);
void				ft_check_if_digit(char *av);

// SECURITY AND ERROR HANDLING FUNCTIONS

int					ft_secu(int argc, char *argv[]);
int					ft_check_args(char *args);
void				ft_error(int i);
void				ft_alloc_failed(t_stack *head, char **split);

// UTILS

char				*concat_args(int argc, char **argv);
static int			calc_total_length(char **argv, int index, int acc);
int					ft_check_duplicates(t_stack *head);

// INSTRUCTIONS
void				sa(t_stack **a);
void				sb(t_stack **b);
void				ss(t_stack **a, t_stack **b);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);
void				ra(t_stack **a);
void				rb(t_stack **b);
void				rr(t_stack **a, t_stack **b);
void				rra(t_stack **a);
void				rrb(t_stack **b);

#endif