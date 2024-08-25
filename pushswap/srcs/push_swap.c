/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 18:34:18 by vafernan          #+#    #+#             */
/*   Updated: 2024/08/24 09:58:15 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/// @brief Check if the stack is sorted in ascendig order.
/// @param stack ptr to the stack beeing checked. 
/// @return 1 if sorted, 0 if not.
int	check_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

/// @brief Main function of the program.
/// @param argc 
/// @param argv 
/// @return 
int	main(int argc, char *argv[])
{
	t_stack	*stack_a;

	if (argc < 2)
		exit(EXIT_FAILURE);
	stack_a = stack_init(argc, argv);
	if (stack_a && !check_sorted(stack_a))
		sort_stack_a(&stack_a);
	stack_free(stack_a);
	return (0);
}
