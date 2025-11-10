NAME1 = server
NAME2 = client

SRC1 = server.c 
SRC2 = client.C

LIBFTPRINTF_DIR = /libftprintf
LIBFTPRINTF = $(LIBFTPRINTF_DIR)/libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

OBJ1 = $(SRC1:.c=.o)
OBJ2 = $(SRC2:.c=.o)

all: $(NAME1) $(NAME2)
	
clean:
	rm -f $(OBJ1) $(OBJ2)


fclean: clean
	rm -f $(NAME1) $(NAME2)

re: fclean all

.PHONY: all clean fclean re
