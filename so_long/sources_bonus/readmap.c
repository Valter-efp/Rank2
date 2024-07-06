/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:02:34 by vafernan          #+#    #+#             */
/*   Updated: 2024/07/03 12:08:50 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static int	map_width(char *string)
{
	int	width;

	width = 0;
	while (string[width] != '\0')
	{
		width++;
	}
	if (string[width - 1] == '\n')
	{
		width--;
	}
	return (width);
}

static char	**open_and_allocate_map(const char *file_path, int *fd)
{
	char	**map;

	*fd = open(file_path, O_RDONLY);
	if (*fd < 0)
		return (NULL);
	map = malloc(sizeof(char *) * 101);
	if (!map)
	{
		close(*fd);
		return (NULL);
	}
	return (map);
}

static char	*read_next_map_line(t_mlx_read_map *context)
{
	char	*line;

	line = get_next_line(context->fd);
	if (line != NULL)
	{
		context->map[*(context->row)] = ft_strdup(line);
		free(line);
		if (!context->map[*(context->row)])
		{
			while (*(context->row) > 0)
				free(context->map[--(*(context->row))]);
			free(context->map);
			close(context->fd);
			return (NULL);
		}
		if (*(context->data_mapwidth) == 0)
			*(context->data_mapwidth)
				= map_width(context->map[*(context->row)]);
		(*(context->data_mapheight))++;
		(*(context->row))++;
	}
	return (line);
}

char	**read_map(t_mlx_data *data, const char *file_path)
{
	t_mlx_read_map	context;
	int				row;
	char			*line;

	row = 0;
	data->mapheight = 0;
	data->mapwidth = 0;
	context.map = open_and_allocate_map(file_path, &(context.fd));
	if (!context.map)
		return (NULL);
	context.row = &row;
	context.data_mapheight = &(data->mapheight);
	context.data_mapwidth = &(data->mapwidth);
	line = read_next_map_line(&context);
	while (line != NULL)
	{
		line = read_next_map_line(&context);
	}
	context.map[row] = NULL;
	close(context.fd);
	return (context.map);
}
