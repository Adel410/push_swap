/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:29:45 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/07/10 16:55:16 by ahadj-ar         ###   ########.fr       */
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

// STRUCTS
typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;

// PROTOTYPES
t_stack				*get_next_min(t_stack **stack);
t_stack				*ft_find_max(t_stack **a);
t_stack				*ft_lstnew_int(int value);
t_stack				*ft_args_to_stack(char *all_args, t_stack *head);
int					ft_secu(int argc, char *argv[]);
int					ft_check_args(char *args);
int					ft_check_if_sorted(t_stack *head);
int					ft_get_sizeof_stack(t_stack *head);
int					ft_find_min_position(t_stack *a);
int					find_min_position(t_stack *stack);
long				ft_atol(const char *str);
char				*ft_strcat(char *dest, const char *src);
char				*concat_args(int argc, char **argv);
void				ft_free_split(char **split);
void				ft_error(int i);
void				ft_check_if_digit(char *av);
void				ft_lstadd_back_stack(t_stack **lst, t_stack *new);
void				ft_check_overflow(char *str);
void				ft_alloc_failed(t_stack *head, char **split);
void				ft_radix_sort(t_stack **a, t_stack **b);
void				ft_read_stack(t_stack **head);
void				ft_sort_three(t_stack **a);
void				ft_sort_stack_of_four_or_five(t_stack **a, t_stack **b);
void				ft_free_stack(t_stack **head);
void				ft_check_stack(t_stack **a, t_stack **b);
void				ft_sort_small_stack(t_stack **a);

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