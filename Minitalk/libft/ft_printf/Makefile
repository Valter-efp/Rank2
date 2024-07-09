# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vafernan <vafernan@42student.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/18 15:27:54 by vafernan          #+#    #+#              #
#    Updated: 2024/05/17 15:02:42 by vafernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -----------------Magusto alterado-------------
# NAME			= printf.a
# CC				= cc
# RM				= rm -f
# CFLAGS			= -Wall -Wextra -Werror

# SRCS			=	ft_printf.c\
# 					ft_putchar.c\
# 					ft_putnbr.c\
# 					ft_putnbrhex.c\
# 					ft_putptr.c\
# 					ft_putstr.c\
# 					ft_utoa.c\
					
# OBJS = $(SRCS:.c=.o)

# all:			$(NAME)

# $(NAME): $(OBJS)		
# 	@cp $(NAME)
# 	@ar $(NAME) $(OBJS)

# %.o: $(SRC)/%.c
# 	@$(CC) $(CFLAGS) -c $< -o $@

# clean:
# 	@$(RM) $(OBJS)

# fclean:		clean
# 			@$(RM) $(NAME)

# re:				fclean $(NAME)

# .PHONY:			all clean fclean re bonus

# -----------------ORIGINAL-------------
NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRCS	=	ft_printf.c\
			ft_putchar_printf.c\
			ft_putnbr_printf.c\
			ft_putnbrhex.c\
			ft_putptr.c\
			ft_putstr_printf.c\
			ft_utoa.c\

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		ar rc $(NAME) $(OBJS)

clean:
	$(RM) -f $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
