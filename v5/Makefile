NAME = push_swap

CC = gcc

CFLAGS = -Wall -Werror -Wextra


RM = rm -f

SRCS = push_swap.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(%.o): $(%.c)
	$(CC) $(CFLAGS) -o $@ -c $^

$(NAME): $(OBJS)
	$(CC) -o $@ $(OBJS)

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
