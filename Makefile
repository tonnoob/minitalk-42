# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: osousa-d <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/14 20:15:54 by osousa-d          #+#    #+#              #
#    Updated: 2025/11/14 20:15:57 by osousa-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = server
NAME2 = client

SRC1 = server.c 
SRC2 = client.c

INCLUDES = -Ilibftprintf/ft_printf -Ilibftprintf/libft -I.

LIBFTPRINTF_DIR = libftprintf
LIBFTPRINTF = $(LIBFTPRINTF_DIR)/libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

OBJ1 = $(SRC1:.c=.o)
OBJ2 = $(SRC2:.c=.o)

all: $(NAME1) $(NAME2)

$(NAME1): $(OBJ1) $(LIBFTPRINTF)
	$(CC) $(OBJ1) -Llibftprintf -lftprintf -o $(NAME1)

$(NAME2): $(OBJ2) $(LIBFTPRINTF)
	$(CC) $(OBJ2) -Llibftprintf -lftprintf -o $(NAME2)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFTPRINTF):
	make -C $(LIBFTPRINTF_DIR)
	
clean:
	rm -f $(OBJ1) $(OBJ2)
	make clean -C $(LIBFTPRINTF_DIR)

fclean: clean
	rm -f $(NAME1) $(NAME2)
	make fclean -C $(LIBFTPRINTF_DIR)

re: fclean all

.PHONY: all clean fclean re
