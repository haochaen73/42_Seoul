# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youngjki <youngjki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/12 14:00:58 by youngjki          #+#    #+#              #
#    Updated: 2022/09/13 22:37:22 by subilee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = bsq
SRCS = ft_check_map.c ft_check_zero.c ft_files.c ft_make_map.c ft_solve_print.c ft_std.c
OBJS = ft_check_map.o ft_check_zero.o ft_files.o ft_make_map.o ft_solve_print.o ft_std.o

all: $(NAME)

%.o : %.c
	$(CC) -c $(CFLAGS) -o $@ $^

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(SRCS)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
