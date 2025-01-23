NAME = push_swap

SRC_DIR = sources
SRC = $(SRC_DIR)/free.c \
	  $(SRC_DIR)/main.c \
	  $(SRC_DIR)/errors.c \
	  $(SRC_DIR)/sort_small.c \
	  $(SRC_DIR)/sort_utils.c \
	  $(SRC_DIR)/sort_large.c \
	  $(SRC_DIR)/handle_inputs.c \
	  $(SRC_DIR)/stack_rotate.c \
	  $(SRC_DIR)/stack_rev_rot.c \
	  $(SRC_DIR)/stack_swap_push.c

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror  -Iincludes/ -I. -Ilibft/
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_DIR) -lft -o $(NAME)

clean:
	@make clean -C $(LIBFT_DIR)
	rm -f $(OBJ)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
