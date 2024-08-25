/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 18:33:38 by vafernan          #+#    #+#             */
/*   Updated: 2024/08/23 14:03:26 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* 
	Double pointers are beeing usedinstead of simple pointers.
	This is so we can also change the pointer and not only the value.
	We also verify if stack is valid and has at least 2 elements.
*/

/// @brief Rotate the elements of the stack upwards(Top becomes last and vice).
/// @param stack Pointer to the stack to be rotated.
static void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	last = stack_find_last(*stack);
	last->next = first;
}

/// @brief Rotate stack A.
/// @param stack_a Ptr to stack A.
void	ra(t_stack **stack_a)
{
	rotate(stack_a);
	ft_putstr_fd("ra\n", 1);
}

/// @brief  Rotate stack B.
/// @param stack_b Ptr to stack B.
void	rb(t_stack **stack_b)
{
	rotate(stack_b);
	ft_putstr_fd("rb\n", 1);
}

/// @brief Rotates both stacks.
/// @param stack_a Ptr to stack A.
/// @param stack_b Ptr to stack B.
void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr_fd("rr\n", 1);
}
