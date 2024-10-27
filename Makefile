# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/27 14:26:15 by ahadj-ar          #+#    #+#              #
#    Updated: 2024/10/27 15:06:44 by ahadj-ar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
### ARGUMENTS

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCDIR = ./srcs
INCDIR = ./include

## SOURCES
SRC = 	./srcs/ft_check.c \
		./srcs/ft_error.c \
		./srcs/ft_push.c \
		./srcs/ft_rotate.c \
		./srcs/ft_small_sort.c \
		./srcs/ft_big_sort.c \
		./srcs/ft_swap.c \
		./srcs/ft_utils.c \
		./srcs/ft_utils2.c \
		./srcs/ft_utils3.c \
		./srcs/ft_utils4.c \
		./srcs/ft_split.c \
		./srcs/main.c

OBJ = $(SRC:.c=.o)

################################################################################
### RULES

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -I$(INCDIR) -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
