/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maperrors_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:33:14 by vafernan          #+#    #+#             */
/*   Updated: 2024/07/05 09:30:15 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	**allocate_visited(int height, int width)
{
	int		**visited;
	int		h;
	int		k;

	visited = malloc(height * sizeof(int *));
	h = 0;
	if (!visited)
		return (NULL);
	while (h < height)
	{
		visited[h] = ft_calloc(width, sizeof(int));
		if (!visited[h])
		{
			k = 0;
			while (k < h)
			{
				free(visited[k]);
				k++;
			}
			free(visited);
			return (NULL);
		}
		h++;
	}
	return (visited);
}

void	free_visited(int **visited, int height)
{
	int	h;

	h = 0;
	while (h < height)
	{
		free(visited[h]);
		h++;
	}
	free(visited);
}

void	visiting(t_mlx_data *data, int height, int width, int **visited)
{
	if (height < 0 || height >= data->mapheight || width < 0
		|| width >= data->mapwidth)
		return ;
	if (visited[height][width] || data->map[height][width] == '1'
		|| data->map[height][width] == 'F')
		return ;
	if (data->map[height][width] == 'C' && !visited[height][width])
		data->collecvisited++;
	visited[height][width] = 1;
	if (data->map[height][width] == 'E')
	{
		if (data->collecvisited == data->totalcollctables)
			return ;
		else
			return ;
	}
	visiting(data, height + 1, width, visited);
	visiting(data, height - 1, width, visited);
	visiting(data, height, width + 1, visited);
	visiting(data, height, width - 1, visited);
}

char	*trim_newline(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len > 0 && str[len - 1] == '\n')
		str[len - 1] = '\0';
	return (str);
}

int	is_valid_character(char c)
{
	return (c == '0' || c == '1' || c == 'P'
		|| c == 'C' || c == 'E');
}
