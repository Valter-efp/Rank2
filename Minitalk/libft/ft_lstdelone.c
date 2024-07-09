/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:09:58 by vafernan          #+#    #+#             */
/*   Updated: 2024/04/14 09:04:13 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// if (!del) - if fn to delete is invalid, return.
// (*del)(lst->content); - applies the del fn to the node pointed.
// free(lst); - Frees the memory that was being used to store the node.

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!del)
		return ;
	if (lst)
	{
		(*del)(lst->content);
		free(lst);
	}
}
