/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:55:42 by vafernan          #+#    #+#             */
/*   Updated: 2024/04/12 10:55:42 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	char		*dest_ptr;
	const char	*src_ptr;
	size_t		size_left;
	size_t		src_length;

	dest_ptr = dest;
	src_ptr = src;
	size_left = size;
	src_length = 0;
	while (size_left > 1 && *src_ptr)
	{
		*dest_ptr++ = *src_ptr++;
		size_left--;
	}
	if (size_left > 0)
		*dest_ptr = '\0';
	while (*src++)
		src_length++;
	return (src_length);
}
