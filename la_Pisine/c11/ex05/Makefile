# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youngjki <youngjki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/11 21:07:41 by youngjki          #+#    #+#              #
#    Updated: 2022/09/11 21:07:44 by youngjki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -g -Wall -Wextra -Werror
SRCS = main.c operator.c ft_atoi.c ft_putnbr.c
NAME = do-op
OBJS = $(SRCS:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(FLAGS) -c $^ -o $@

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $(SRCS) -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
