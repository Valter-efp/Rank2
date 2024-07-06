/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 16:39:16 by vafernan          #+#    #+#             */
/*   Updated: 2024/07/01 10:57:01 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	load_images(t_mlx_data *data)
{
	int	width;
	int	height;

	load_images_base(data, &width, &height);
	load_img_dynamic(data, &width, &height);
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
	data->image33 = mlx_xpm_file_to_image(data->mlx_ptr,
			IMAGE33_IMG, width, height);
	if (data->grass == NULL
		|| data->image1 == NULL
		|| data->image3 == NULL
		|| data->image33 == NULL)
	{
		ft_printf("Error loading image, check sprite files!\n");
		cleanup_and_exit(data);
	}
}

void	load_img_dynamic(t_mlx_data *data, int *width, int *height)
{
	data->image4 = mlx_xpm_file_to_image(data->mlx_ptr,
			IMAGE4_IMG, width, height);
	data->image41 = mlx_xpm_file_to_image(data->mlx_ptr,
			IMAGE41_IMG, width, height);
	data->image42 = mlx_xpm_file_to_image(data->mlx_ptr,
			IMAGE42_IMG, width, height);
	data->image43 = mlx_xpm_file_to_image(data->mlx_ptr,
			IMAGE43_IMG, width, height);
	data->image5 = mlx_xpm_file_to_image(data->mlx_ptr,
			IMAGE5_IMG, width, height);
	data->image51 = mlx_xpm_file_to_image(data->mlx_ptr,
			IMAGE51_IMG, width, height);
	data->image52 = mlx_xpm_file_to_image(data->mlx_ptr,
			IMAGE52_IMG, width, height);
	data->image53 = mlx_xpm_file_to_image(data->mlx_ptr,
			IMAGE53_IMG, width, height);
	if (data->image4 == NULL || data->image41 == NULL
		|| data->image42 == NULL || data->image43 == NULL
		|| data->image5 == NULL || data->image51 == NULL
		|| data->image52 == NULL || data->image53 == NULL)
	{
		ft_printf("Error loading image, check sprite files!\n");
		cleanup_and_exit(data);
	}
}
