NAME = rush-02

SRCS = main.c
OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGSC = -c -Wall -Wextra -Werror
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
		$(CC) $(CFLAGS) $< -o $@
%.o: %.c
		$(CC) $(CFLAGSC) $< -o $@ 
clean :
		rm -rf $(OBJS)
fclean : clean
		rm -rf $(NAME)
re : fclean all

.PHONY : all clean fclean re
