/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 18:33:58 by vafernan          #+#    #+#             */
/*   Updated: 2024/08/24 10:46:12 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* 
	Declare two variables, "last" and "second_to_last".
	last = will uptdate untill the last node of the stack.
	second_to_last = same, but second o last LOL.
	last will become the 1st element of the list.
	second_to_last, will become the last element
*/

/// @brief Rotates the elements of the stack downwards.
/// @param stack Ptr to the top of the stack.
static void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*second_to_last;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	last = *stack;
	second_to_last = NULL;
	while (last->next != NULL)
	{
		second_to_last = last;
		last = last->next;
	}
	second_to_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

/// @brief Rotates the stack downwards.
/// @param stack_a Ptr to stack A.
void	rra(t_stack **stack_a)
{
	reverse_rotate(stack_a);
	ft_putstr_fd("rra\n", 1);
}

/// @brief Rotates the stack downwards.
/// @param stack_b Ptr to stack B.
void	rrb(t_stack **stack_b)
{
	reverse_rotate(stack_b);
	ft_putstr_fd("rrb\n", 1);
}

/// @brief Rotates both stacks downwards.
/// @param stack_a Ptr to stack A.
/// @param stack_b Ptr to stack B.
void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putstr_fd("rrr\n", 1);
}
