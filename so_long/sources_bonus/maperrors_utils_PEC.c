/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maperrors_utils_PEC.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 09:40:59 by vafernan          #+#    #+#             */
/*   Updated: 2024/07/04 11:08:33 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	check_p_e_c_count(t_mlx_data *data)
{
	if (!check_player_count(data))
		return (0);
	if (!check_exit_count(data))
		return (0);
	if (!check_collect_count(data))
		return (0);
	return (1);
}

int	check_player_count(t_mlx_data *data)
{
	int	player_count;
	int	i;
	int	j;

	player_count = 0;
	i = 0;
	while (i < data->mapheight)
	{
		j = 0;
		while (j < data->mapwidth)
		{
			if (data->map[i][j] == 'P')
				player_count++;
			j++;
		}
		i++;
	}
	if (player_count != 1)
	{
		ft_printf("Map must have exactly one 'P'\n");
		return (0);
	}
	return (1);
}

int	check_exit_count(t_mlx_data *data)
{
	int	exit_count;
	int	i;
	int	j;

	exit_count = 0;
	i = 0;
	while (i < data->mapheight)
	{
		j = 0;
		while (j < data->mapwidth)
		{
			if (data->map[i][j] == 'E')
				exit_count++;
			j++;
		}
		i++;
	}
	if (exit_count != 1)
	{
		ft_printf("Map must have exactly one 'E'\n");
		return (0);
	}
	return (1);
}

int	check_collect_count(t_mlx_data *data)
{
	int	collect_count;
	int	i;
	int	j;

	collect_count = 0;
	i = 0;
	while (i < data->mapheight)
	{
		j = 0;
		while (j < data->mapwidth)
		{
			if (data->map[i][j] == 'C')
				collect_count++;
			j++;
		}
		i++;
	}
	if (collect_count == 0)
	{
		ft_printf("Map must have at least one 'C'\n");
		return (0);
	}
	return (1);
}

int	check_map_content(t_mlx_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->mapheight)
	{
		j = 0;
		while (j < data->mapwidth)
		{
			if (!is_valid_character(data->map[i][j]))
			{
				ft_printf("Invalid character '%c' found in the map.\n",
					data->map[i][j]);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
