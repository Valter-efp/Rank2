/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 19:01:09 by vafernan          #+#    #+#             */
/*   Updated: 2024/04/07 12:00:08 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(int nitems, int size)
{
	void	*str;

	str = malloc (nitems * size);
	if (!str)
		return (0);
	ft_bzero(str, size * nitems);
	return (str);
}

/*int	main()
{
	char *str;
	str = (char *) ft_calloc(9, sizeof(char));
	strcpy(str, "Vafernan");
	printf("String: %s, Address: %p\n", str, str);
	str = (char *) ft_calloc(9, sizeof(char));
	strcpy(str, "Vafernan");
	printf("String: %s, Address: %p\n", str, str);
	return (0);
}*/