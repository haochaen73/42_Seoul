# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youngjki <youngjki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/12 14:00:58 by youngjki          #+#    #+#              #
#    Updated: 2022/09/12 14:30:10 by youngjki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC: gcc
FLAGS: -Wall -Werror - Wextra -c
NAME : bsq
SRCS: *.c

all: $(NAME)

%.o : %.c
	$(CC) $(FLAGS) -c $^ -o $@

$(NAME) : $(SRCS)
	$(CC) $(FLAGS) -o $@ $^

clean: 
	rm -f 