/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:41:40 by vafernan          #+#    #+#             */
/*   Updated: 2024/08/24 09:57:42 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/// @brief sorts a stach of three elements.
/// @param a Ptr to stack A.
void	sort_three(t_stack **a)
{
	int	frst;
	int	scnd;
	int	thrd;

	frst = (*a)->value;
	scnd = (*a)->next->value;
	thrd = (*a)->next->next->value;
	if (frst > scnd && frst < thrd)
		sa(a);
	else if (frst > scnd && scnd > thrd)
	{
		sa(a);
		rra(a);
	}
	else if (frst > scnd && scnd < thrd)
		ra(a);
	else if (frst < scnd && frst > thrd)
		rra(a);
	else if (frst < thrd && scnd > thrd)
	{
		sa(a);
		ra(a);
	}
}

/// @brief Totates stack A until min valu is on the head.
/// @param a  Ptr to stack A.
void	rotate_to_min(t_stack **a)
{
	int	min_val;
	int	pos_in_a;
	int	size;

	min_val = min_value(*a);
	pos_in_a = find_index(*a, min_val);
	size = stack_size(*a);
	if (pos_in_a <= size / 2)
	{
		while ((*a)->value != min_val)
			ra(a);
	}
	else
	{
		while ((*a)->value != min_val)
			rra(a);
	}
}

/// @brief Sorts a stack with up to 5 elements.
/// @param a  Ptr to stack A.
/// @param b Ptr to stack B.
void	sort_upto_five(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	while (size > 3)
	{
		rotate_to_min(a);
		pb(a, b);
		size--;
	}
	sort_three(a);
	while (*b)
		pa(a, b);
}

/// @brief Sort stack A based in the nbr of arg.
/// @param stack_a Ptr to stack A.
void	sort_stack_a(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		size;

	stack_b = NULL;
	size = stack_size(*stack_a);
	if (size == 2)
		sa(stack_a);
	else if (size <= 5)
		sort_upto_five(stack_a, &stack_b);
	else
		big_sort(stack_a, &stack_b);
	stack_free(stack_b);
}
