/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 18:33:25 by vafernan          #+#    #+#             */
/*   Updated: 2024/08/24 10:49:39 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* 
	Double pointers are beeing usedinstead of simple pointers.
	This is so we can also change the pointer and not onlythe value.
	We also verify if stack is valid and has at least 2 elements.
*/

/// @brief Swap the first two elements of the stack.
/// @param stack Ptr to the top of the stack
static void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

/// @brief Swap the top two elements of stack A.
/// @param stack_a Ptr to stack A.
void	sa(t_stack **stack_a)
{
	swap(stack_a);
	ft_putstr_fd("sa\n", 1);
}

/// @brief Swap the top two elements of stack B.
/// @param stack_b Ptr to stack B.
void	sb(t_stack **stack_b)
{
	swap(stack_b);
	ft_putstr_fd("sb\n", 1);
}

/// @brief Swap the top two elements of tack A and B.
/// @param stack_a Ptr to stack A.
/// @param stack_b Ptr to stack B.
void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putstr_fd("ss\n", 1);
}
