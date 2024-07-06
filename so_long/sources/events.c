/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:14:43 by vafernan          #+#    #+#             */
/*   Updated: 2024/07/01 11:12:48 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	ⓘ
	Handle Key inputs and close command
*/
#include "../so_long.h"

int	handle_input(int keysym, t_mlx_data *data)
{
	if (keysym == KEY_W || keysym == KEY_A
		|| keysym == KEY_S || keysym == KEY_D)
	{
		data->moves++;
		if (keysym == KEY_W)
			move_up(data);
		else if (keysym == KEY_A)
			move_left(data);
		else if (keysym == KEY_S)
			move_down(data);
		else if (keysym == KEY_D)
			move_right(data);
		render_map_with_image(data, data->map);
	}
	if (keysym == KEY_ESC)
	{
		ft_printf("The %d key (ESC) has been pressed\n\n", keysym);
		cleanup_and_exit(data);
	}
	ft_printf("Total collectables in map: %d\n", data->totalcollctables);
	ft_printf("Rupees collected: %d\n", data->collectables);
	ft_printf("You have moved: %d times\n\n", data->moves);
	return (0);
}

int	handle_close(t_mlx_data *data)
{
	ft_printf("Window close event detected\n");
	cleanup_and_exit(data);
	return (0);
}

void	win_event(t_mlx_data *data)
{
	printf("The Hero of Hyrule, savior of princess Zelda!\n");
	cleanup_and_exit(data);
}
