NAME = push_swap

SRC = push_swap.c init_stack_a.c res.c rotate.c sort_three.c swap.c stack_sorted.c rev_rotate.c sort_stacks.c push.c init_a_to_b.c init_b_to_a.c errors.c extra.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(FLAGS) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all