/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maperrors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 21:08:54 by vafernan          #+#    #+#             */
/*   Updated: 2024/07/04 09:37:07 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	check_outer_bounds(t_mlx_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->mapheight)
	{
		j = 0;
		while (j < data->mapwidth)
		{
			if ((i == 0 || i == data->mapheight - 1 || j == 0
					|| j == data->mapwidth - 1) && data->map[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_c_and_e(t_mlx_data *data, int height, int **visited)
{
	int	path;
	int	width;

	width = 0;
	path = 1;
	while (height < data->mapheight)
	{
		width = 0;
		while (width < data->mapwidth)
		{
			if ((data->map[height][width] == 'C'
				|| data->map[height][width] == 'E')
				&& !visited[height][width])
			{
				path = 0;
				break ;
			}
			width++;
		}
		if (!path)
			break ;
		height++;
	}
	return (path);
}

int	check_path(t_mlx_data *data)
{
	int	**visited;

	visited = allocate_visited(data->mapheight, data->mapwidth);
	if (!visited)
	{
		ft_printf(ERROR_IN_MAP_FILE);
		return (0);
	}
	visiting(data, data->j, data->i, visited);
	if (!check_c_and_e(data, 0, visited))
	{
		ft_printf(ERROR_IN_MAP_FILE);
		free_visited(visited, data->mapheight);
		return (0);
	}
	free_visited(visited, data->mapheight);
	return (1);
}

int	check_map_dimensions(t_mlx_data *data)
{
	int	width;
	int	height;
	int	first_row_length;

	if (data->mapheight < 1)
		return (0);
	first_row_length = ft_strlen(trim_newline(data->map[0]));
	height = 1;
	while (height < data->mapheight)
	{
		width = ft_strlen(trim_newline(data->map[height]));
		if (width != first_row_length)
			return (0);
		height++;
	}
	data->mapwidth = first_row_length;
	return (1);
}

int	check_maperrors(t_mlx_data *data)
{
	count_collectables(data);
	if (!check_map_content(data))
		cleanup_and_exit(data);
	if (!check_player_count(data))
	{
		cleanup_and_exit(data);
	}
	if (!check_p_e_c_count(data))
		cleanup_and_exit(data);
	if (!check_outer_bounds(data))
	{
		ft_printf("Outer positions of the map must all be '1'\n");
		cleanup_and_exit(data);
	}
	if (!check_path(data))
	{
		ft_printf("No valid path!\n");
		cleanup_and_exit(data);
	}
	if (!check_map_dimensions(data))
	{
		ft_printf("Map is not rectangular!\n");
		cleanup_and_exit(data);
	}
	return (1);
}
