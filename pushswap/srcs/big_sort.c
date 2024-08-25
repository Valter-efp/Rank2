/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:39:44 by vafernan          #+#    #+#             */
/*   Updated: 2024/08/24 10:45:11 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/// @brief Pushes the top 2 elements of stack A to B.
/// @param a Ptr to the src stack.
/// @param b Ptr to the dest stack.
void	push_to_b(t_stack **a, t_stack **b)
{
	int	count;

	count = 0;
	while (count < 2)
	{
		pb(a, b);
		count++;
	}
	if (check_sorted(*b))
		rb(b);
}

/// @brief Finds the element with less cost to move from A to B.
/// @param a Ptr to src stack.
/// @param b Ptr to dest stack.
/// @return The element with less cost.
t_stack	*find_elem(t_stack *a, t_stack *b)
{
	t_stack	*min_cost_elem;
	t_stack	*current;
	int		min_cost;
	int		cost;

	min_cost_elem = NULL;
	min_cost = INT_MAX;
	current = a;
	while (current)
	{
		cost = cost_determine(a, b, current->value);
		if (cost < min_cost)
		{
			min_cost = cost;
			min_cost_elem = current;
		}
		current = current->next;
	}
	return (min_cost_elem);
}

/// @brief Rotates on a single stack, based on rotation count and direction.
/// @param stack Ptr to thestack to be rotated.
/// @param rotations Number of rotations needed.
/// @param is_forward If it is forward rotation.
/// @param is_stack_a If it is stack A.
void	single_stack_rotations(t_stack **stack, int rotations,
	bool is_forward, bool is_stack_a)
{
	while (rotations > 0)
	{
		if (is_forward)
		{
			if (is_stack_a)
				ra(stack);
			else
				rb(stack);
		}
		else
		{
			if (is_stack_a)
				rra(stack);
			else
				rrb(stack);
		}
		rotations--;
	}
}

/// @brief Rotates both stacks.
/// @param stack_a Ptr to stack A.
/// @param a_cost Cost to rotate stack A.
/// @param stack_b Ptr to stack B.
/// @param b_cost Cost to rotate stack B.
void	perform_rotations(t_stack **stack_a, int a_cost,
	t_stack **stack_b, int b_cost)
{
	if (a_cost > 0 && b_cost > 0)
	{
		while (a_cost > 0 && b_cost > 0)
		{
			rr(stack_a, stack_b);
			a_cost--;
			b_cost--;
		}
	}
	else if (a_cost < 0 && b_cost < 0)
	{
		while (a_cost < 0 && b_cost < 0)
		{
			rrr(stack_a, stack_b);
			a_cost++;
			b_cost++;
		}
	}
	single_stack_rotations(stack_a, ft_absolute(a_cost), (a_cost >= 0), true);
	single_stack_rotations(stack_b, ft_absolute(b_cost), (b_cost >= 0), false);
}

/// @brief Pushes elements from stack A to B sorting them
/// @param a Ptr to stack A.
/// @param b Ptr to stack B.
void	big_sort(t_stack **a, t_stack **b)
{
	t_stack	*min_cost;
	int		pos_in_a;
	int		pos_in_b;
	int		a_cost;
	int		b_cost;

	push_to_b(a, b);
	while (*a)
	{
		min_cost = find_elem(*a, *b);
		pos_in_a = find_index(*a, min_cost->value);
		pos_in_b = find_position(*b, min_cost->value);
		a_cost = rotation_cost(stack_size(*a), pos_in_a);
		b_cost = rotation_cost(stack_size(*b), pos_in_b);
		perform_rotations(a, a_cost, b, b_cost);
		pb(a, b);
	}
	while (*b)
		pa(a, b);
	rotate_to_min(a);
}
