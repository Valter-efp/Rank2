/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:36:36 by vafernan          #+#    #+#             */
/*   Updated: 2024/06/07 10:42:36 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

char	*ft_cjoin(char *str, char c)
{
	char	*newstring;
	int		i;
	int		size;

	if (!str)
	{
		str = malloc(sizeof(char));
		str[0] = '\0';
	}
	size = ft_strlen(str);
	newstring = (char *)malloc(sizeof(char) * (size + 2));
	if (!newstring)
		return (0);
	i = 0;
	while (str[i])
	{
		newstring[i] = str[i];
		i++;
	}
	newstring[i++] = c;
	newstring[i] = '\0';
	if (str)
		free(str);
	return (newstring);
}

void	read_bits_and_print(int signal)
{
	static int	received_char = 0;
	static int	bit = 0;
	static char	*str;

	if (!str)
		str = NULL;
	if (signal == SIGUSR1)
		received_char = received_char | (1 << bit);
	bit += 1;
	if (bit == 8)
	{
		if (received_char == '\0')
		{
			ft_printf("%s\n", str);
			free(str);
			str = NULL;
		}
		else
			str = ft_cjoin(str, received_char);
		bit = 0;
		received_char = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("Server Started, PID = %d\n", pid);
	while (1)
	{
		signal(SIGUSR1, read_bits_and_print);
		signal(SIGUSR2, read_bits_and_print);
	}
}
