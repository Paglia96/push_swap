CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address,leak -g
NAME = push_swap

SRCS = push_swap.c utils.c parser.c index_lst.c moves.c double_moves.c lst_utils.c check_lst.c struct_intializers.c simple_min_max_extraction_method.c round_sqrt.c chunk_sort.c adaptive.c radix_sort.c
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
