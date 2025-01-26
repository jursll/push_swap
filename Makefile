# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julrusse <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/26 11:15:39 by julrusse          #+#    #+#              #
#    Updated: 2025/01/26 11:16:30 by julrusse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -I includes -I $(LIBFT_DIR)

SRC_DIR = sources
OBJ_DIR = $(SRC_DIR)/obj

SRC = free.c \
	  main.c \
	  errors.c \
	  sort_small.c \
	  sort_utils.c \
	  sort_large.c \
	  handle_inputs.c \
	  stack_rotate.c \
	  stack_rev_rot.c \
	  stack_swap_push.c

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) -L$(LIBFT_DIR) -lft -o $(NAME)

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
