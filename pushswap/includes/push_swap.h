/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 18:24:24 by vafernan          #+#    #+#             */
/*   Updated: 2024/08/24 09:58:24 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

const char			*skip_spaces(const char *str);
t_stack				*stack_init(int argc, char *argv[]);
t_stack				*stack_create_node(int content);
t_stack				*stack_find_last(t_stack *lst);
void				stack_add_top(t_stack **lst, t_stack *new_node);
void				stack_free(t_stack *stack);
void				exit_error(t_stack *stack);
void				cleanup_and_exit(t_stack *stack, char **numbers);
void				sa(t_stack **stack_a);
void				sb(t_stack **stack_b);
void				ss(t_stack **stack_a, t_stack **stack_b);
void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_a, t_stack **stack_b);
void				ra(t_stack **stack_a);
void				rb(t_stack **stack_b);
void				rr(t_stack **stack_a, t_stack **stack_b);
void				rra(t_stack **stack_a);
void				rrb(t_stack **stack_b);
void				rrr(t_stack **stack_a, t_stack **stack_b);
void				sort_stack_a(t_stack **stack_a);
void				big_sort(t_stack **a, t_stack **b);
void				rotate_to_min(t_stack **a);
int					check_sorted(t_stack *stack);
int					parse_arg(const char *str, int *error);
int					stack_size(t_stack *stack);
int					max_value(t_stack *stack);
int					min_value(t_stack *stack);
int					cost_determine(t_stack *a, t_stack *b, int value);
int					rotation_cost(int size, int pos);
int					ft_absolute(int num);
int					find_position(t_stack *b, int value);
int					find_index(t_stack *stack, int value);
#endif