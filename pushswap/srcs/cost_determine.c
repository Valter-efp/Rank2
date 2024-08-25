/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_determine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:40:48 by vafernan          #+#    #+#             */
/*   Updated: 2024/08/24 10:45:25 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/// @brief Find the position in stack B to insert value while keeping order.
/// @param b Ptr to the head of stack B.
/// @param value The value should be inserted
/// @return The position index where the value should be inserted.
int	find_position(t_stack *b, int value)
{
	t_stack	*tmp;
	int		pos;

	if (value > b->value && value < stack_find_last(b)->value)
		pos = 0;
	else if (value > max_value(b) || value < min_value(b))
		pos = find_index(b, max_value(b));
	else
	{
		pos = 1;
		tmp = b->next;
		while (b->value < value || tmp->value > value)
		{
			b = b->next;
			tmp = b->next;
			pos++;
		}
	}
	return (pos);
}

/// @brief Determines the cost to rotate both stacks at the same time.
/// @param cost_a Ptr to the cost for rotating stack A.
/// @param cost_b Ptr to the cost for rotating stack B.
/// @return Total number of operations.
static int	cost_rotate(int *cost_a, int *cost_b)
{
	int	total;

	total = 0;
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		total++;
	}
	return (total);
}

/// @brief Determines the cost to rrotate both stacks at the same time.
/// @param cost_a Ptr to the cost for Rrotating stack A.
/// @param cost_b Ptr to the cost for Rrotating stack B.
/// @return Total number of operations.
static int	cost_rrotate(int *cost_a, int *cost_b)
{
	int	total;

	total = 0;
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		total++;
	}
	return (total);
}

/// @brief Determine the roataion cost for the two stacks.
/// @param cost_a  Cost for rotating stack A.
/// @param cost_b Cost for rotating stack B.
/// @return Total combined rotation cost.
static int	cost_double_rotation(int cost_a, int cost_b)
{
	int	total_cost;

	total_cost = 0;
	if (cost_a > 0 && cost_b > 0)
	{
		total_cost = cost_rotate(&cost_a, &cost_b);
		total_cost += cost_a + cost_b;
	}
	else if (cost_a < 0 && cost_b < 0)
	{
		total_cost = cost_rrotate(&cost_a, &cost_b);
		total_cost += ft_absolute(cost_a) + ft_absolute(cost_b);
	}
	else
		total_cost = ft_absolute(cost_a) + ft_absolute(cost_b);
	return (total_cost);
}

/// @brief Determines the total cost to move a value from stack B to A.
/// @param a Ptr to the head of stack A.
/// @param b Ptr to the head of stack B.
/// @param value The value that will be moved.
/// @return Te total cost of moving the value.
int	cost_determine(t_stack *a, t_stack *b, int value)
{
	int	pos_b;
	int	pos_a;
	int	cost_b;
	int	cost_a;

	pos_b = find_position(b, value);
	pos_a = find_index(a, value);
	cost_b = rotation_cost(stack_size(b), pos_b);
	cost_a = rotation_cost(stack_size(a), pos_a);
	return (cost_double_rotation(cost_a, cost_b));
}
