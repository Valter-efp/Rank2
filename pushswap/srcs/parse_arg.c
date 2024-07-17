/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:42:25 by vafernan          #+#    #+#             */
/*   Updated: 2024/07/17 18:45:15 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

const char	*trim_whitespace(const char *str)
{
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	return (str);
}

static long	parse_long(const char *str, int sign, int *error)
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

int	parse_arg(const char *str, int *error)
{
	long	res;
	int		sign;

	sign = 1;
	str = trim_whitespace(str);
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
	res = parse_long(str, sign, error);
	if (*error)
		return (0);
	return ((int)(res * sign));
}
