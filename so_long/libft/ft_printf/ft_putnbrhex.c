/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrhex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:07:26 by vafernan          #+#    #+#             */
/*   Updated: 2024/04/18 15:11:19 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbrhex(unsigned int nbr, const char c)
{
	char	*base;
	int		printed_chars;

	printed_chars = 0;
	if (c == 'x')
		base = "0123456789abcdef";
	else if (c == 'X')
		base = "0123456789ABCDEF";
	if (nbr >= 16)
	{
		printed_chars += ft_putnbrhex((nbr / 16), c);
		printed_chars += ft_putnbrhex((nbr % 16), c);
	}
	else
	{
		printed_chars += write(1, &base[nbr], 1);
	}
	return (printed_chars);
}
