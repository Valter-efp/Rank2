/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 09:51:11 by vafernan          #+#    #+#             */
/*   Updated: 2024/04/12 09:51:11 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* This function will fill "n" positions of the memory 
pointed by "s" with zero "'/0'" */
/* If "n==0" return; to handle if n=0*/

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*dest;

	if (n == 0)
		return ;
	i = 0;
	dest = s;
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
}

/*int	main() {
	char str[] = "42 Is nuts!";
	puts(str);
	ft_bzero(str, 3);
	puts(str);
	return(0);
}*/