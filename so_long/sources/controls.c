/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:40:45 by vafernan          #+#    #+#             */
/*   Updated: 2024/07/01 11:12:22 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_map(t_mlx_data *data)
{
	int	y;
	int	x;

	ft_printf("Map state:\n");
	y = 0;
	while (y < data->mapheight)
	{
		x = 0;
		while (x < data->mapwidth)
		{
			ft_printf("%c", data->map[y][x]);
			x++;
		}
		ft_printf("\n");
		y++;
	}
	ft_printf("\n");
}

void	move_up(t_mlx_data *data)
{
	data->player_pos = 1;
	if (data->map[data->j - 1][data->i] != '1' &&
		!(data->map[data->j - 1][data->i] == 'E' && data->open == 0))
	{
		if (data->map[data->j - 1][data->i] == 'C')
		{
			data->collectables++;
		}
		else if (data->map[data->j - 1][data->i] == 'E' && data->open == 1)
		{
			win_event(data);
			return ;
		}
		data->map[data->j][data->i] = '0';
		update_render(data, data->j, data->i, '0');
		data->map[data->j - 1][data->i] = 'P';
		update_render(data, data->j, data->i, 'P');
		data->j--;
		check_exit(data);
	}
}

void	move_down(t_mlx_data *data)
{
	data->player_pos = 0;
	if (data->map[data->j + 1][data->i] != '1' &&
		!(data->map[data->j + 1][data->i] == 'E' && data->open == 0))
	{
		if (data->map[data->j + 1][data->i] == 'C')
		{
			data->collectables++;
		}
		else if (data->map[data->j + 1][data->i] == 'E' && data->open == 1)
		{
			win_event(data);
			return ;
		}
		data->map[data->j][data->i] = '0';
		update_render(data, data->j, data->i, '0');
		data->map[data->j + 1][data->i] = 'P';
		update_render(data, data->j, data->i, 'P');
		data->j++;
		check_exit(data);
	}
}

void	move_left(t_mlx_data *data)
{
	data->player_pos = 2;
	if (data->map[data->j][data->i - 1] != '1' &&
		!(data->map[data->j][data->i - 1] == 'E' && data->open == 0))
	{
		if (data->map[data->j][data->i - 1] == 'C')
		{
			data->collectables++;
		}
		else if (data->map[data->j][data->i - 1] == 'E' && data->open == 1)
		{
			win_event(data);
			return ;
		}
		data->map[data->j][data->i] = '0';
		update_render(data, data->j, data->i, '0');
		data->map[data->j][data->i - 1] = 'P';
		update_render(data, data->j, data->i, 'P');
		data->i--;
		check_exit(data);
	}
}

void	move_right(t_mlx_data *data)
{
	data->player_pos = 3;
	if (data->map[data->j][data->i + 1] != '1' &&
		!(data->map[data->j][data->i + 1] == 'E' && data->open == 0))
	{
		if (data->map[data->j][data->i + 1] == 'C')
		{
			data->collectables++;
		}
		else if (data->map[data->j][data->i + 1] == 'E' && data->open == 1)
		{
			win_event(data);
			return ;
		}
		data->map[data->j][data->i] = '0';
		update_render(data, data->j, data->i, '0');
		data->map[data->j][data->i + 1] = 'P';
		update_render(data, data->j, data->i, 'P');
		data->i++;
		check_exit(data);
	}
}
