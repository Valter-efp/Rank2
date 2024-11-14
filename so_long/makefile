# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vafernan <vafernan@42student.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/01 11:39:09 by vafernan          #+#    #+#              #
#    Updated: 2024/07/02 09:52:33 by vafernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
BONUS_NAME = so_long_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a
MLXFLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_FLAGS = -L$(LIBFT_DIR) -lft

# Mandatory
SRC_DIR = sources
SRC = $(wildcard $(SRC_DIR)/*.c) \
      $(LIBFT_DIR)/GNL/get_next_line_bonus.c
OBJ = $(SRC:.c=.o)

# Bonus
SRC_DIR_BONUS = sources_bonus
SRC_BONUS = $(wildcard $(SRC_DIR_BONUS)/*.c) \
      $(LIBFT_DIR)/GNL/get_next_line_bonus.c
OBJ_BONUS = $(SRC_BONUS:.c=.o)

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	@make -s -C $(LIBFT_DIR)
	@make -s -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(MLXFLAGS) $(LIBFT) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(OBJ_BONUS)
	@make -s -C $(LIBFT_DIR)
	@make -s -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(MLXFLAGS) $(LIBFT) -o $(BONUS_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -s -C $(LIBFT_DIR)
	@make clean -s -C $(MLX_DIR)
	@rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	@make fclean -s -C $(LIBFT_DIR)
	@make clean -s -C $(MLX_DIR)
	@rm -f $(NAME) $(BONUS_NAME)
	

re: fclean all

download:
	@wget https://cdn.intra.42.fr/document/document/27195/minilibx-linux.tgz
	@tar -xzf minilibx-linux.tgz
	@rm minilibx-linux.tgz
	 
.PHONY: all clean fclean re bonus
