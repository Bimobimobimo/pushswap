# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/25 09:02:07 by lcollong          #+#    #+#              #
#    Updated: 2024/12/04 11:12:40 by lcollong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRCS = push_swap.c \
		Parameters/fill_stack_a.c \
		Parameters/error.c \
		Parameters/split.c \
		Algorithm/sort.c \
		Algorithm/sort_utils.c \
		Algorithm/sort_utils_2.c \
		Algorithm/sort_utils_3.c \
		Annexes/get.c \
		Annexes/utils.c \
		Operations/push.c \
		Operations/reverse_rotate.c \
		Operations/rotate.c \
		Operations/swap.c 

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
