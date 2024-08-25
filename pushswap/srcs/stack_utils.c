/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:43:43 by vafernan          #+#    #+#             */
/*   Updated: 2024/08/24 09:56:42 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/// @brief Creates a new node with the provided content.
/// @param content Value to be stored in the new node.
/// @return Ptr to the new node created.
t_stack	*stack_create_node(int content)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = content;
	new_node->next = NULL;
	return (new_node);
}

/// @brief Add new node to the top of the stack.
/// @param lst Ptr to the top of the stack.
/// @param new_node Ptr to the node to be added.
void	stack_add_top(t_stack **lst, t_stack *new_node)
{
	if (new_node)
	{
		new_node->next = *lst;
		*lst = new_node;
	}
}

/// @brief Finds the last node of the stack.
/// @param lst Ptr to the top of the stack.
/// @return Ptr to the last node of the stack.
t_stack	*stack_find_last(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/// @brief Determines the stack size.
/// @param stack Ptr to the top of the stack.
/// @return The nbr of the nodes in the stack.
int	stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}
