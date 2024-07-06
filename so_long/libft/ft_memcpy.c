/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:08:28 by vafernan          #+#    #+#             */
/*   Updated: 2024/04/12 10:08:28 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Void pointers are used when we don't know what type of variable
we are pointing, it's a non type specific pointer*/
/*Points a dst memory block and a src memory block and copies n
bytes from src to dst*/
/*while (i < n && (src || dst)) - iterates until n and if
src||dest != '/0'*/

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	const char		*temp_src;
	char			*temp_dst;

	i = 0;
	temp_src = (const char *)src;
	temp_dst = (char *)dst;
	if (!src && !dst)
		return (0);
	while (i < n)
	{
		temp_dst[i] = temp_src[i];
		i++;
	}
	return (dst);
}

/*#include "string.h"
int	main()
{
	char src[] = "42 is nuts!";
	char dst[strlen(src) + 1];
	printf("Src = %s\n", src);
	printf("Dest before memcpy = %s\n", dst);
	memcpy(dst, src, strlen(src) + 1);
	printf("Dest after standard memcpy = %s\n", dst);
	ft_memcpy(dst, src, strlen(src) + 1);
	printf("Dest after custom memcpy = %s\n", dst);
	return (0);
}*/
