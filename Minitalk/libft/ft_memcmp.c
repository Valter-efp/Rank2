/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:04:55 by vafernan          #+#    #+#             */
/*   Updated: 2024/04/12 10:04:55 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, int n)
{
	unsigned char	*comp1;
	unsigned char	*comp2;
	int				i;

	comp1 = (unsigned char *)s1;
	comp2 = (unsigned char *)s2;
	i = 0;
	if (n < 1)
		return (0);
	while (i < n)
	{
		if (comp1[i] != comp2[i])
			return (comp1[i] - comp2[i]);
		i++;
	}
	return (0);
}

/*#include "string.h"
int	main()
{
	char str1[] = "Is Nuts!";
	char str2[] = "is nuts!";
	int n = 5;
	printf("Custom ft_memchr result: %d\n", ft_memcmp(str1, str2, n));
	printf("Standard memchr result: %d\n", memcmp(str1, str2, n));
	return (0);
}*/