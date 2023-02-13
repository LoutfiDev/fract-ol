# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/13 15:02:00 by yloutfi           #+#    #+#              #
#    Updated: 2023/02/13 15:07:04 by yloutfi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = fractol.c

OBJS = fractol.o

NAME = fractol
CFLAGS = -Wall -Wextra -Werror 
CC = cc

all : $(NAME)
	
$(NAME) : $(OBJS)
	$(CC) -g $(CFLAGS) $(OBJS) -o $(NAME) 

clean :
	-rm -f $(OBJS)
		
fclean : clean
	-rm -f $(NAME)

re : fclean	all

.PHONY: all clean fclean re