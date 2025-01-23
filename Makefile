# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julrusse <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/23 13:12:34 by julrusse          #+#    #+#              #
#    Updated: 2025/01/23 14:32:15 by julrusse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
TARGET = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -I includes -I $(LIBFT_DIR)

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

OBJ_DIR = obj
OBJ		= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: $(TARGET)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(TARGET): $(LIBFT) $(NAME)
	@$(CC) $(CFLAGS) -o $(TARGET) main.c $(NAME) -Llibft -lft

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@rm -f $(NAME) $(TARGET)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
