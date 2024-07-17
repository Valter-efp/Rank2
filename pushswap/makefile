# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vafernan <vafernan@42student.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/17 18:47:19 by vafernan          #+#    #+#              #
#    Updated: 2024/07/17 19:28:42 by vafernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_FLAGS = -L$(LIBFT_DIR) -lft

SRC_DIR = srcs
INCLUDE_DIR = includes
LIBFT_INCLUDE_DIR = $(LIBFT_DIR)

SRC = $(wildcard $(SRC_DIR)/*.c) \
      $(LIBFT_DIR)/GNL/get_next_line_bonus.c
OBJ = $(SRC:.c=.o)

INCLUDES = -I$(INCLUDE_DIR) -I$(LIBFT_INCLUDE_DIR)

all: $(NAME)

$(NAME): $(OBJ)
	@make -s -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@make clean -s -C $(LIBFT_DIR)
	@rm -f $(OBJ)

fclean: clean
	@make fclean -s -C $(LIBFT_DIR)
	@rm -f $(NAME)

re: fclean all
	 
.PHONY: all clean fclean re bonus