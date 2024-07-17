/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 18:34:18 by vafernan          #+#    #+#             */
/*   Updated: 2024/07/17 18:44:15 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;

	if (argc < 2)
		exit(EXIT_FAILURE);
	stack_a = init_stack(argc, argv);
	if (stack_a && !is_sorted(stack_a))
		sort_stack(&stack_a);
	free_stack(stack_a);
	return (0);
}
