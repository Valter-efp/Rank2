/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:36:41 by vafernan          #+#    #+#             */
/*   Updated: 2024/06/07 10:40:47 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"
/* Test with 1K char < 1 sec */
/* Test with 10K char < 4 sec*/
/* Test with 30K char < 30 sec*/
/* Test with 60K char < 2 min*/
/* Test with 100K char <  min*/
size_t	usleep_dynamic(size_t n)
{
	size_t	i;

	i = 0;
	if (n <= 10000)
		i = 10;
	else if (n <= 30000)
		i = 100;
	else if (n <= 60000)
		i = 300;
	else if (n <= 100000)
		i = 500;
	else if (n <= 1000000)
		i = 10000;
	return (i);
}

void	send_str(int pid, char *str)
{
	int		bit;
	size_t	i;
	size_t	usleep_i;

	usleep_i = 0;
	i = 0;
	while (i <= ft_strlen(str))
	{
		bit = 0;
		while (bit < 8)
		{
			if ((str[i] >> bit) & 1)
				kill (pid, SIGUSR1);
			else
				kill (pid, SIGUSR2);
			usleep_i = usleep_dynamic(i);
			usleep(usleep_i);
			bit++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*str;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		str = argv[2];
		send_str(pid, str);
	}
	else
	{
		ft_printf("You must provide the PID and string to print!\n");
		ft_printf("Example:\n./client '123(pid)' '42 is great(string)'");
	}
}
