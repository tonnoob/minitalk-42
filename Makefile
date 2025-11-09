NAME1 = server
NAME2 = client

SRC1 = 
SRC2 =

CC = cc
CFLAGS = -Wall -Wextra -Werror

OBJ1 = $(SRC1:.c=.o)
OBJ2 = $(SRC2:.c=.o)

all: $(NAME1) $(NAME2)

clean:

fclean: clean
	rm -f 

re: fclean all

.PHONY: all clean fclean re