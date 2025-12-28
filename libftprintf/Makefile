# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: osousa-d <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/28 14:04:19 by osousa-d          #+#    #+#              #
#    Updated: 2025/12/28 14:04:28 by osousa-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

FT_PRINTF_DIR = ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/*.o

all: $(NAME)

$(NAME): $(LIBFT) $(FT_PRINTF)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(FT_PRINTF)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(FT_PRINTF):
	make -C $(FT_PRINTF_DIR)

clean: 
	make clean -C $(LIBFT_DIR)
	make clean -C $(FT_PRINTF_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(FT_PRINTF_DIR)

re: fclean all

.PHONY: all clean fclean re
