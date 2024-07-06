/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafernan <vafernan@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 11:55:15 by vafernan          #+#    #+#             */
/*   Updated: 2024/07/04 10:27:19 by vafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include "libft/GNL/get_next_line_bonus.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>

# define MLX_ERROR 1
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define IMG_WIDTH 100
# define IMG_HEIGHT 100
# define KEY_ESC 65307
# define GRASS_IMG "./map/sprites/grass.xpm"
# define IMAGE1_IMG "./map/sprites/GrassAndDeadTreeBig.xpm"
# define IMAGE2_IMG "./map/sprites/RupeeYOnGrass.xpm"
# define IMAGE3_IMG "./map/sprites/GreatDeku.xpm"
# define IMAGE4_IMG "./map/sprites/LinkFOnGrass.xpm"
# define ERROR_IN_MAP_FILE "Error in map: Collectables or exit not reachable!\n"

typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		mapheight;
	int		mapwidth;
	int		moves;
	int		collectables;/* Count collectables in map and -- when collected */
	int		totalcollctables;
	int		collecvisited;
	int		open;/* Check if exit is open */
	int		i;/* Player position */
	int		j;/* Player position */
	int		player_pos;/* last move for image update */
	int		exit_count;/* variable for map validation */
	char	*win;
	char	**map;
	void	*grass;/* Grass */
	void	*image1;/* GrassAndDeadTreeBig */
	void	*image2;/* RupeeYOnGrass */
	void	*image3;/* GreatDeku */
	void	*image4;/* LinkFOnGrass */
}	t_mlx_data;

typedef struct s_mlx_read_map
{
	int		fd;
	char	**map;
	int		*row;
	int		*data_mapheight;
	int		*data_mapwidth;
}	t_mlx_read_map;

int		handle_input(int keysym, t_mlx_data *data);
int		handle_close(t_mlx_data *data);
int		find_player_in_row(char *row, int width, int *player_position);
int		check_maperrors(t_mlx_data *data);
int		path_checker(t_mlx_data *data, int height, int width);
int		check_path(t_mlx_data *data);
int		check_maperrors(t_mlx_data *data);
int		**allocate_visited(int height, int width);
int		check_p_e_c_count(t_mlx_data *data);
int		check_player_count(t_mlx_data *data);
int		check_exit_count(t_mlx_data *data);
int		check_collect_count(t_mlx_data *data);
int		render_next_frame(t_mlx_data *data);
int		check_map_content(t_mlx_data *data);
int		is_valid_character(char c);
char	**read_map(t_mlx_data *data, const char *file_path);
char	*trim_newline(char *str);
void	render_map_with_image(t_mlx_data *data, char **map);
void	load_images(t_mlx_data *data);
void	cleanup_and_exit(t_mlx_data *data);
void	initialize_player_position(t_mlx_data *data);
void	move_up(t_mlx_data *data);
void	move_down(t_mlx_data *data);
void	move_left(t_mlx_data *data);
void	move_right(t_mlx_data *data);
void	check_exit(t_mlx_data *data);
void	update_render(t_mlx_data *data, int y, int x, char tile);
void	win_event(t_mlx_data *data);
void	free_visited(int **visited, int height);
void	visiting(t_mlx_data *data, int height, int width, int **visited);
void	put_image(t_mlx_data *data, void *img, int x, int y);
void	load_images_base(t_mlx_data *data, int *width, int *height);
void	count_collectables(t_mlx_data *data);
void	cleanup_map(char **map);
void	destroy_image(void *mlx_ptr, void *image);

#endif