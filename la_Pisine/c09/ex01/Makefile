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

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
NAME = libft.a
OBJS = $(SRCS:.c=.o)
INC = includes

all : $(NAME)

%.o : %.c
	$(CC) $(FLAGS) -c $^ -o $@ -I $(INC)

$(NAME) : $(OBJS)
	ar rc $@ $^

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
