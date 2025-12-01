# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otton-sousa <otton-sousa@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/14 20:15:54 by osousa-d          #+#    #+#              #
#    Updated: 2025/12/01 01:35:29 by otton-sousa      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client

SRC_SERVER = server.c 
SRC_CLIENT = client.c

SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

SRC_SERVER_BONUS = server_bonus.c 
SRC_CLIENT_BONUS = client_bonus.c

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

OBJ_SERVER_BONUS = $(SRC_SERVER_BONUS:.c=.o)
OBJ_CLIENT_BONUS = $(SRC_CLIENT_BONUS:.c=.o)

INCLUDES = -Ilibftprintf/ft_printf -Ilibftprintf/libft -I.

LIBFTPRINTF_DIR = libftprintf
LIBFTPRINTF = $(LIBFTPRINTF_DIR)/libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: $(SERVER) $(CLIENT)

$(SERVER): $(OBJ_SERVER) $(LIBFTPRINTF)
	$(CC) $(OBJ_SERVER) -Llibftprintf -lftprintf -o $(SERVER)

$(CLIENT): $(OBJ_CLIENT) $(LIBFTPRINTF)
	$(CC) $(OBJ_CLIENT) -Llibftprintf -lftprintf -o $(CLIENT)

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER_BONUS): $(OBJ_SERVER_BONUS) $(LIBFTPRINTF)
	$(CC) $(OBJ_SERVER_BONUS) -Llibftprintf -lftprintf -o $(SERVER_BONUS)

$(CLIENT_BONUS): $(OBJ_CLIENT_BONUS) $(LIBFTPRINTF)
	$(CC) $(OBJ_CLIENT_BONUS) -Llibftprintf -lftprintf -o $(CLIENT_BONUS)

$(LIBFTPRINTF):
	make -C $(LIBFTPRINTF_DIR)
	
clean:
	rm -f $(OBJ_SERVER) $(OBJ_CLIENT) $(OBJ_SERVER_BONUS) $(OBJ_CLIENT_BONUS)
	make clean -C $(LIBFTPRINTF_DIR)

fclean: clean
	rm -f $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)
	make fclean -C $(LIBFTPRINTF_DIR)

re: fclean all

.PHONY: all clean fclean re
