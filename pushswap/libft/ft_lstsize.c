/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:34:46 by vafernan          #+#    #+#             */
/*   Updated: 2024/04/14 10:59:30 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Takes a pointer to the beggining of a list.
// In the loop we iterate through each position of the list.

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	cnt;

	cnt = 0;
	while (lst)
	{
		cnt++;
		lst = lst->next;
	}
	return (cnt);
}
