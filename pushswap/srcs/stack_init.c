/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:43:20 by vafernan          #+#    #+#             */
/*   Updated: 2024/08/24 10:47:06 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/// @brief Check if the stack has dup values.
/// @param stack Ptr to the stack to look.
/// @param value Reference value to check.
/// @return 1 if dupe, 0 if not.
static int	check_duplicate(t_stack *stack, int value)
{
	while (stack != NULL)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

/// @brief Adds a nbr to the top of the stack.
/// @param stack Stack to be filled.
/// @param str String with the number.
/// @return 
static int	add_nbr_to_stack(t_stack **stack, const char *str)
{
	t_stack	*new_node;
	int		value;
	int		error;

	error = 0;
	value = parse_arg(str, &error);
	if (error || check_duplicate(*stack, value))
		return (-1);
	new_node = stack_create_node(value);
	if (!new_node)
		return (-1);
	stack_add_top(stack, new_node);
	return (0);
}

/// @brief Fills the stack with str seprated by spaces.
/// @param stack Ptr to the stack
/// @param str Str containing the nbrs, separeted by spaces.
static void	fill_stack_from_string(t_stack **stack, char *str)
{
	char	**nbrs;
	int		i;

	nbrs = ft_split(str, ' ');
	if (!nbrs)
		exit_error(*stack);
	i = 0;
	while (nbrs[i] != NULL)
		i++;
	while (i > 0)
	{
		i--;
		if (add_nbr_to_stack(stack, nbrs[i]) == -1)
		{
			free(nbrs[i]);
			nbrs[i] = NULL;
			cleanup_and_exit(*stack, nbrs);
		}
		free(nbrs[i]);
	}
	free(nbrs);
}

/// @brief Inits the stack with nbrs from the argv. Checks if argv is valid.
/// @param argc 
/// @param argv 
/// @return Ptr to the iitialized stack.
t_stack	*stack_init(int argc, char *argv[])
{
	t_stack	*stack;
	int		i;

	stack = NULL;
	if (argc == 2)
	{
		if (argv[1] == NULL || *skip_spaces(argv[1]) == '\0')
			exit_error(stack);
		fill_stack_from_string(&stack, argv[1]);
	}
	else
	{
		i = argc - 1;
		while (i > 0)
		{
			if (add_nbr_to_stack(&stack, argv[i]) == -1)
				exit_error(stack);
			i--;
		}
	}
	return (stack);
}
