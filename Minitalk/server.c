/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:36:36 by vafernan          #+#    #+#             */
/*   Updated: 2024/07/07 15:49:09 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

/// @brief Appends a character to the end of a string.
/// @param str The original string.
/// @param c The character to append.
/// @return char* The new string with the appended character.
char	*append_char(char *str, char c)
{
	int		i;
	int		len;
	char	*new_str;

	if (!str)
	{
		str = malloc(sizeof(char));
		str[0] = '\0';
	}
	len = ft_strlen(str);
	new_str = (char *)malloc(sizeof(char) * (len + 2));
	if (!new_str)
		return (0);
	i = 0;
	while (i < len)
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i++] = c;
	new_str[i] = '\0';
	free(str);
	return (new_str);
}

/// @brief Signal handler to process the received bits.
/// @param sig The received signal (SIGUSR1 or SIGUSR2).
/* 
	When2 SIGUSR1" is recieved we set the corresponding bit in "current_char"
	using bitwise (|=) and we shift the left.
	After that we increment until one char is completed,
	and check for the end of the string.
 */
void	handle_signal(int sig)
{
	static int	current_char;
	static int	bit_index;
	static char	*message;

	if (sig == SIGUSR1)
		current_char |= (1 << bit_index);
	bit_index++;
	if (bit_index == 8)
	{
		if (current_char == '\0')
		{
			ft_printf("%s\n", message);
			free(message);
			message = NULL;
		}
		else
			message = append_char(message, current_char);
		bit_index = 0;
		current_char = 0;
	}
}

/// @brief Main function for the server program.
/// @param  No parameter is being passed into main.
/// @return 
int	main(void)
{
	int	server_pid;

	server_pid = getpid();
	ft_printf("Server Started, PID = %d\n", server_pid);
	while (1)
	{
		signal(SIGUSR1, handle_signal);
		signal(SIGUSR2, handle_signal);
	}
}
