/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:15:03 by vafernan          #+#    #+#             */
/*   Updated: 2024/07/01 10:57:15 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	put_image(t_mlx_data *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img,
		x * IMG_WIDTH, y * IMG_HEIGHT);
}

void	render_tile(t_mlx_data *data, char tile, int x, int y)
{
	put_image(data, data->grass, x, y);
	if (tile == '1')
		put_image(data, data->image1, x, y);
	else if (tile == 'C')
		put_image(data, data->image2, x, y);
	else if (tile == 'E' && !data->open)
		put_image(data, data->image3, x, y);
	else if (tile == 'E' && data->open)
		put_image(data, data->image33, x, y);
	else if (tile == 'P')
		render_player_image(data, x, y);
	else if (tile == 'Y')
		render_enemy_image(data, x, y);
}

void	render_map_with_image(t_mlx_data *data, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			render_tile(data, map[y][x], x, y);
			x++;
		}
		y++;
	}
	render_text(data);
}

void	update_render(t_mlx_data *data, int y, int x, char tile)
{
	put_image(data, data->grass, x, y);
	if (tile == '1')
		put_image(data, data->image1, x, y);
	else if (tile == 'C')
		put_image(data, data->image2, x, y);
	else if (tile == 'E' && !data->open)
		put_image(data, data->image3, x, y);
	else if (tile == 'E' && data->open)
		put_image(data, data->image33, x, y);
	else if (tile == 'P')
		render_player_image(data, x, y);
	else if (tile == 'Y')
		render_enemy_image(data, x, y);
}
