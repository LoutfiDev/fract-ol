# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/13 15:02:00 by yloutfi           #+#    #+#              #
#    Updated: 2023/03/06 09:54:45 by yloutfi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
MLX = -lmlx -framework OpenGL -framework AppKit
MATH = -lm
CC = cc

SRCS = fractol.c parser.c helpers.c get_next_line.c	\
	get_next_line_utils.c ft_fatoi.c draw.c suites.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)
	
$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(MLX) $(MATH) $(OBJS) -o $(NAME) 

clean :
	-rm -f $(OBJS)
		
fclean : clean
	-rm -f $(NAME)

re : fclean	all

.PHONY: all clean fclean re