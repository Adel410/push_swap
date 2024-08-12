# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/27 14:26:15 by ahadj-ar          #+#    #+#              #
#    Updated: 2024/08/12 17:15:25 by ahadj-ar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
### ARGUMENTS

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCDIR = ./srcs
INCDIR = ./include
LIBFTDIR = ./Libft
LIBFT = $(LIBFTDIR)/libft.a

## SOURCES
SRC = 	./srcs/ft_check.c \
		./srcs/ft_error.c \
		./srcs/ft_push.c \
		./srcs/ft_rotate.c \
		./srcs/ft_sort.c \
		./srcs/ft_swap.c \
		./srcs/ft_utils.c \
		./srcs/ft_utils2.c \
		./srcs/main.c

OBJ = $(SRC:.c=.o)

################################################################################
### RULES

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -I$(INCDIR) -o $(NAME) $(OBJ) -L$(LIBFTDIR) -lft

$(LIBFT):
	make -C $(LIBFTDIR)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBFTDIR) -c $< -o $@

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFTDIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFTDIR)

re: fclean all

.PHONY: all clean fclean re
