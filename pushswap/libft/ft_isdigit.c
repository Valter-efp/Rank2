/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:22:05 by valter            #+#    #+#             */
/*   Updated: 2024/08/23 14:59:19 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/*#include "ctype.h"
int	main()
{
	printf("Standard isdigit('V'): %d\n", isdigit('V'));
	printf("Custom   isdigit('V'): %d\n", ft_isdigit('V'));
	printf("Standard isdigit('4'): %d\n", isdigit('4'));
	printf("Custom   isdigit('4'): %d\n", ft_isdigit('4'));
	return(0);
}*/