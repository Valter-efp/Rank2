/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 16:39:16 by vafernan          #+#    #+#             */
/*   Updated: 2024/07/01 11:21:27 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	load_images(t_mlx_data *data)
{
	int	width;
	int	height;

	load_images_base(data, &width, &height);
}

void	load_images_base(t_mlx_data *data, int *width, int *height)
{
	data->grass = mlx_xpm_file_to_image(data->mlx_ptr,
			GRASS_IMG, width, height);
	data->image1 = mlx_xpm_file_to_image(data->mlx_ptr,
			IMAGE1_IMG, width, height);
	data->image2 = mlx_xpm_file_to_image(data->mlx_ptr,
			IMAGE2_IMG, width, height);
	data->image3 = mlx_xpm_file_to_image(data->mlx_ptr,
			IMAGE3_IMG, width, height);
	data->image4 = mlx_xpm_file_to_image(data->mlx_ptr,
			IMAGE4_IMG, width, height);
	if (data->grass == NULL
		|| data->image1 == NULL
		|| data->image3 == NULL
		|| data->image4 == NULL)
	{
		ft_printf("Error loading image, check sprite files!\n");
		cleanup_and_exit(data);
	}
}
