/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_text.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:08:38 by vafernan          #+#    #+#             */
/*   Updated: 2024/07/03 12:19:49 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	render_text(t_mlx_data *data)
{
	render_text_moves(data);
	render_text_collectables(data);
}

void	render_text_collectables(t_mlx_data *data)
{
	char	*current_collectables_str;
	char	*total_collectables_str;
	char	*collectables_text;
	char	*temp_str;

	current_collectables_str = ft_itoa(data->collectables);
	total_collectables_str = ft_itoa(data->totalcollctables);
	collectables_text = ft_strjoin("Collectables: ", current_collectables_str);
	temp_str = ft_strjoin(collectables_text, " / ");
	free(collectables_text);
	collectables_text = ft_strjoin(temp_str, total_collectables_str);
	free(temp_str);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 60,
		TEXT_COLOR, collectables_text);
	free(current_collectables_str);
	free(total_collectables_str);
	free(collectables_text);
}

void	render_text_moves(t_mlx_data *data)
{
	char	*moves_text;
	char	*final_moves_str;

	moves_text = ft_itoa(data->moves);
	final_moves_str = ft_strjoin("Moves: ", moves_text);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 40,
		TEXT_COLOR, final_moves_str);
	free(moves_text);
	free(final_moves_str);
}
