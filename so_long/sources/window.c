/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:12:41 by vafernan          #+#    #+#             */
/*   Updated: 2024/07/04 10:56:31 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_data(t_mlx_data *data)
{
	ft_memset(data, 0, sizeof(t_mlx_data));
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		exit (MLX_ERROR);
	data->win = "so_long";
}

void	load_map_and_window(t_mlx_data *data, const char *map_path)
{
	char	**map;

	map = read_map(data, map_path);
	if (!map)
	{
		ft_printf("Error loading map\n");
		exit (MLX_ERROR);
	}
	data->map = map;
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			data->mapwidth * 100, data->mapheight * 100, data->win);
	if (data->win_ptr == NULL)
	{
		free(data->mlx_ptr);
		exit (MLX_ERROR);
	}
}

void	int_render_and_hooks(t_mlx_data *data)
{
	initialize_player_position(data);
	load_images(data);
	check_maperrors(data);
	render_map_with_image(data, data->map);
	mlx_key_hook(data->win_ptr, handle_input, data);
	mlx_hook(data->win_ptr, 17, 0, handle_close, data);
	mlx_loop(data->mlx_ptr);
}

void	cleanup_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	main(int argc, char **argv)
{
	t_mlx_data	data;

	if (argc != 2)
	{
		ft_printf("Usage: %s <map_file_path>\n", argv[0]);
		return (1);
	}
	init_data(&data);
	load_map_and_window(&data, argv[1]);
	int_render_and_hooks(&data);
	return (0);
}
