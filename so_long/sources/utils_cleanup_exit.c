/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cleanup_exit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 10:03:52 by vafernan          #+#    #+#             */
/*   Updated: 2024/07/01 11:22:22 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	cleanup_and_exit(t_mlx_data *data)
{
	if (data->mlx_ptr)
	{
		if (data->win_ptr)
		{
			destroy_image(data->mlx_ptr, data->grass);
			destroy_image(data->mlx_ptr, data->image1);
			destroy_image(data->mlx_ptr, data->image2);
			destroy_image(data->mlx_ptr, data->image3);
			destroy_image(data->mlx_ptr, data->image4);
			mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		}
		cleanup_map(data->map);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	exit(1);
}

void	destroy_image(void *mlx_ptr, void *image)
{
	if (image)
		mlx_destroy_image(mlx_ptr, image);
}
