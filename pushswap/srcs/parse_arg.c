/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:42:25 by vafernan          #+#    #+#             */
/*   Updated: 2024/08/24 09:54:44 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/// @brief Remove leading withespaces from the string.
/// @param str String to remove whitspaces.
/// @return Pointer to the first non whitespace char of the str.
const char	*skip_spaces(const char *str)
{
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	return (str);
}

/// @brief Parses a numerig string into a long int, checks for overflow
/// @param str The str that coints the numeric value to parse.
/// @param sign Sign of the number.
/// @return 
static long	ft_atol(const char *str, int sign, int *error)
{
	long	res;

	res = 0;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		if ((sign == 1 && res > INT_MAX) || (sign == -1 && (-res) < INT_MIN))
		{
			*error = 1;
			return (0);
		}
		str++;
	}
	if (*str != '\0')
	{
		*error = 1;
		return (0);
	}
	return (res);
}

/// @brief Parses an str into an int.
/// @param str the argv to be parsed.
/// @param error if 1st char is not digit or sign, error = 1.
/// @return returns the argv converted to an int.
int	parse_arg(const char *str, int *error)
{
	long	res;
	int		sign;

	sign = 1;
	str = skip_spaces(str);
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (*str < '0' || *str > '9')
	{
		*error = 1;
		return (0);
	}
	res = ft_atol(str, sign, error);
	if (res == 0 && (str[0] != '0' || str[1] != '\0'))
		return (0);
	return ((int)(res * sign));
}
