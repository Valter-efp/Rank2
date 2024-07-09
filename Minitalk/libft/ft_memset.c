/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:14:04 by vafernan          #+#    #+#             */
/*   Updated: 2024/04/12 10:14:04 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Since this funciotn must return a pointer to the memory block
modified, it is declared as void to return an unspecified pointer,*/
/*This is because we don't know wich data type the variable we will
be modifiyng is*/
/*(void *b, int c, size_t len) - b=destitation; c=character to be
useed to fill; len=length to be filled*/
/*(Size_t is used so any size possible is accomodated) */
/*Since the memory position zero is also used, we ccant put while (i <= len)*/

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	char			*dest;

	dest = b;
	i = 0;
	while (i < len)
	{
		dest[i] = c;
		i++;
	}
	return ((void *)b);
}

/*#include "string.h"
int	main()
{
	char str[50] = "42 is nuts!";
	puts(str);
	ft_memset(str, '-', 3);
	puts(str);
	return(0);
}*/