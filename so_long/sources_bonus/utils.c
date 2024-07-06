/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:15:26 by vafernan          #+#    #+#             */
/*   Updated: 2024/07/01 10:57:19 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	check_exit(t_mlx_data *data)
{
	if (data->totalcollctables - data->collectables == 0 && (data->open == 0))
	{
		data->open++;
	}
}

int	find_player_in_row(char *row, int width, int *player_position)
{
	int	x;

	x = 0;
	while (x < width)
	{
		if (row[x] == '\0')
			return (0);
		if (row[x] == 'P')
		{
			*player_position = x;
			return (1);
		}
		x++;
	}
	return (0);
}

void	initialize_player_position(t_mlx_data *data)
{
	int	player_position;
	int	y;

	y = 0;
	if (data->map == NULL || data->mapheight <= 0 || data->mapwidth <= 0)
		exit(EXIT_FAILURE);
	while (y < data->mapheight)
	{
		if (data->map[y] == NULL)
			exit(EXIT_FAILURE);
		if (find_player_in_row(data->map[y], data->mapwidth, &player_position))
		{
			data->i = player_position;
			data->j = y;
			return ;
		}
		y++;
	}
	ft_printf("Map must have a Player\n");
	exit(EXIT_FAILURE);
}

void	count_collectables(t_mlx_data *data)
{
	int	height;
	int	width;

	height = 0;
	while (height < data->mapheight)
	{
		width = 0;
		while (data->map[height][width] != '\0')
		{
			if (data->map[height][width] == 'C')
			{
				data->totalcollctables++;
			}
			width++;
		}
		height++;
	}
}
