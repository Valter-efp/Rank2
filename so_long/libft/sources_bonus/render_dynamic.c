/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_dynamic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 16:35:20 by vafernan          #+#    #+#             */
/*   Updated: 2024/07/02 10:04:26 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	render_player_image(t_mlx_data *data, int x, int y)
{
	if (data->player_pos == 0)
		put_image(data, data->image4, x, y);
	if (data->player_pos == 1)
		put_image(data, data->image41, x, y);
	if (data->player_pos == 2)
		put_image(data, data->image42, x, y);
	if (data->player_pos == 3)
		put_image(data, data->image43, x, y);
}

void	render_enemy_image(t_mlx_data *data, int x, int y)
{
	if (data->enemy_frame == 0)
		put_image(data, data->image5, x, y);
	if (data->enemy_frame == 1)
		put_image(data, data->image51, x, y);
	if (data->enemy_frame == 2)
		put_image(data, data->image52, x, y);
	if (data->enemy_frame == 3)
		put_image(data, data->image53, x, y);
}

int	render_next_frame(t_mlx_data *data)
{
	int	x;
	int	y;

	usleep(135000);
	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'Y')
				render_enemy_image(data, x, y);
			x++;
		}
		y++;
	}
	data->enemy_frame = (data->enemy_frame + 1) % 4;
	return (0);
}
