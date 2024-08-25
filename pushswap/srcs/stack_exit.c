/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:42:41 by vafernan          #+#    #+#             */
/*   Updated: 2024/08/24 10:46:42 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/// @brief Fress the whole stack.
/// @param stack Ptr to the stack to be freed.
void	stack_free(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

/// @brief Frees and eits program.
/// @param stack Ptr to stack to be freed
/// @param nbrs Ptr to the str to be freed.
void	cleanup_and_exit(t_stack *stack, char **nbrs)
{
	int	i;

	i = 0;
	if (nbrs)
	{
		while (nbrs[i])
		{
			free(nbrs[i]);
			nbrs[i] = NULL;
			i++;
		}
		free(nbrs);
	}
	exit_error(stack);
}

/// @brief Prints error messsage and frees the stack before exiting.
/// @param stack Ptr to the stack to be freed.
void	exit_error(t_stack *stack)
{
	if (stack)
		stack_free(stack);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}
