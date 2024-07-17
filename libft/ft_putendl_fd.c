/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:15:48 by vafernan          #+#    #+#             */
/*   Updated: 2024/04/12 10:15:48 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}

/*#include <fcntl.h>
#include <unistd.h>
int main()
{
	int fd = open("putendl_Test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		ft_putstr_fd("Error opening file\n", STDERR_FILENO);
		return 1;
	}
	ft_putendl_fd("42 is nuts!", fd);
	close(fd);
	return 0;
}*/
/* need to compile the 3 function together */
/* cc -Wall -Wextra -Werror ft_putendl_fd.c ft_putstr_fd.c ft_strlen.c */
