# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youngjki <youngjki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/10 16:16:25 by youngjki          #+#    #+#              #
#    Updated: 2022/09/10 16:39:46 by youngjki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS = -g -Wall -Wextra -Werror
SRCS = ft_putchar ft_swap ft_putstr ft_strlen ft_strcmp
NAME = libft.a
OBJS = $(SRC:.c=.o)
INC = 

$(NAME) : $(OBJS)
	$(CC) -O $@ $(OBJS)

all : $(NAME)
clean :
	rm -f $(OBJS)
fclean : clean
	rm -f $(NAME)
re : fclean all

a.out : a.o b.o main.o
	gcc -o a.out a.o b.o main.o
a.o : a.c
	gcc -c -o a.o a.c
b.o : b.c
	gcc -c -o b.o b.c
main.o : main.c
	gcc -c -o main.o main.c