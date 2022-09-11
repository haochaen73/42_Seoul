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

CC=gcc
FLAGS=-g -Wall -Wextra -Werror
SRC = main.c operator.c
NAME = libft.a
OBJS = $(SRC:.c=.o)

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) -c $^ -o $@

%.o = %.c

all : $(TARGET)
clean:
	rm -rf $(OBJS)

$(TARGET) : $(OBJS)
	$(CC) -O $@ $(OBJS)
fclean: clean
	rm -rf $(TARGET)

re: clean fclean
