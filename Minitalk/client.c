/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:36:41 by vafernan          #+#    #+#             */
/*   Updated: 2024/07/09 18:21:16 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

/// @brief determine the sleep duration based on the position in the message.
/// @param pos position of the char in the message.
/// @return the value to be updated in the usleep of sinal sending.
size_t	calculate_usleep(size_t pos)
{
	if (pos <= 10000)
		return (10);
	else if (pos <= 30000)
		return (100);
	else if (pos <= 60000)
		return (300);
	else if (pos <= 100000)
		return (500);
	else
		return (10000);
}

/// @brief Transmits the string to the specified process ID.
/// @param process_id PID of the server process.
/// @param message The message to be sent.
/*
	Iterate through each char of the srting, and for each bit of the char.
	Sends  the respective signal for each bit.
	SIGUSR1 = bit 1.
	SIGUSR2 = bit 0.
	sleep_duration = short sleep to ensure signal is processed.
 */
void	transmit_string(int process_id, char *message)
{
	int		bit;
	size_t	char_index;
	size_t	sleep_duration;

	char_index = 0;
	while (char_index <= ft_strlen(message))
	{
		bit = 0;
		while (bit < 8)
		{
			if ((message[char_index] >> bit) & 1)
				kill (process_id, SIGUSR1);
			else
				kill (process_id, SIGUSR2);
			sleep_duration = calculate_usleep(char_index);
			usleep(sleep_duration);
			bit++;
		}
		char_index++;
	}
}
/// @brief Main function for the client program.
/// @param argc Argument count.
/// @param argv Argument vector.
/// @return

int	main(int argc, char **argv)
{
	int		process_id;
	char	*message;

	if (argc == 3)
	{
		process_id = ft_atoi(argv[1]);
		message = argv[2];
		transmit_string(process_id, message);
	}
	else
	{
		ft_printf("You must provide the PID and string to print!\n");
		ft_printf("Example:\n./client '123(pid)' '42 is great(string)'");
	}
}
