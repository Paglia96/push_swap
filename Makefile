CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address,leak -g
NAME = push_swap

SRCS = push_swap.c utils.c parser.c moves.c lst_utils.c check_lst.c insertion_sort_2.c
OBJS := $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

%o: %c
	$(CC) $(CFLAGS) $< -c $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
