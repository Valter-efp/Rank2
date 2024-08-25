/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:41:09 by vafernan          #+#    #+#             */
/*   Updated: 2024/08/24 09:56:09 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/// @brief Returns a number as absolue, removes - sign.
/// @param n Int to turn to absolute.
/// @return  The absolute value of int n.
int	ft_absolute(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

/// @brief Determines the cost of rotatig a stack to determined position.
/// @param size Total size of the stack.
/// @param pos Position of the element in the stack.
/// @return Minimum amount of ratation needed, with sign + for positive or -.
int	rotation_cost(int size, int pos)
{
	int	forward;
	int	reverse;

	forward = pos;
	reverse = size - pos;
	if (forward <= reverse)
		return (forward);
	else
		return (-reverse);
}

/// @brief Find the position of value in stack.
/// @param stack Ptr to the head of the stack.
/// @param value The value to be searched.
/// @return The position of the value in the stack.
int	find_index(t_stack *stack, int value)
{
	int	i;

	i = 0;
	while (stack->value != value)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

/// @brief Find the maximum value in the stack.
/// @param stack Ptr to the head of the stack.
/// @return The maximum value in the stack.
int	max_value(t_stack *stack)
{
	int	max;

	max = stack->value;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

/// @brief Find the minimum value in the stack.
/// @param stack Ptr to the head of the stack.
/// @return The minimum value in the stack.
int	min_value(t_stack *stack)
{
	int	min;

	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}
