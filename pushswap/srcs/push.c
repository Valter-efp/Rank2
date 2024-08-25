/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 18:32:39 by vafernan          #+#    #+#             */
/*   Updated: 2024/08/24 10:45:41 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/// @brief Moves the top element of stack src to the top of stack dest.
/// @param src_stack Ptr to the src stack.
/// @param dest_stack Ptr to the dest stack.
static void	push(t_stack **src_stack, t_stack **dest_stack)
{
	t_stack	*first;

	if (src_stack == NULL || *src_stack == NULL)
		return ;
	first = *src_stack;
	*src_stack = first->next;
	first->next = *dest_stack;
	*dest_stack = first;
}

/// @brief Pushes the top element from stack A to B.
/// @param stack_a Ptr to the dest stack A.
/// @param stack_b Ptr to the src stack B.
void	pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	ft_putstr_fd("pa\n", 1);
}

/// @brief Pushes the top element from stack B to A.
/// @param stack_a  Ptr to the src stack A.
/// @param stack_b Ptr to the dest stak B
void	pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	ft_putstr_fd("pb\n", 1);
}
