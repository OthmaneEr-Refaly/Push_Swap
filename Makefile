NAME = push_swap
NAME_1 = checker

SRC = push_swap.c init_stack_a.c res.c rotate.c sort_three.c \
	  ./swap.c stack_sorted.c rev_rotate.c \
	  ./sort_stacks.c push.c init_a_to_b.c init_b_to_a.c errors.c split.c \

SRCB = checker.c init_stack_a_bonus.c get_next_line.c get_next_line_utils.c ft_strcmp.c \
	   ./errors.c split.c init_stack_a.c rev_rotate.c rotate.c swap.c push.c ft_putstr_fd.c

OBG = $(SRC:.c=.o)
OBGB = $(SRCB:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBG)
	$(CC) $(CFLAGS) $(OBG) $(FLAGS) -o $(NAME)

bonus : $(NAME_1)

$(NAME_1): $(OBGB) 
	$(CC) $(CFLAGS) $(OBGB) -o $(NAME_1)

clean:
	rm -rf $(OBG)
	rm -rf $(OBGB)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(NAME1)

re: fclean all 