SERVER = server
CLIENT = client
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

SRC_DIR = src
OBJ_DIR = obj

SRC_SERVER = $(SRC_DIR)/server.c
SRC_CLIENT = $(SRC_DIR)/client.c
SRC_SERVER_BONUS = $(SRC_DIR)/server_bonus.c
SRC_CLIENT_BONUS = $(SRC_DIR)/client_bonus.c

OBJ_SERVER = $(SRC_SERVER:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJ_CLIENT = $(SRC_CLIENT:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJ_SERVER_BONUS = $(SRC_SERVER_BONUS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJ_CLIENT_BONUS = $(SRC_CLIENT_BONUS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT = libs/libft/libft.a
PRINTF = libs/ft_printf/ft_printf.a

LIBS = $(PRINTF) $(LIBFT)

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -Ilibs/libft -Ilibs/ft_printf -I.

all: $(SERVER) $(CLIENT)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(SERVER): $(OBJ_SERVER) $(LIBFT) $(PRINTF)
	@$(CC) $(CFLAGS) $(OBJ_SERVER) $(LIBS) -o $(SERVER)
	@echo "✅ Server pronto!"

$(CLIENT): $(OBJ_CLIENT) $(LIBFT) $(PRINTF)
	@$(CC) $(CFLAGS) $(OBJ_CLIENT) $(LIBS) -o $(CLIENT)
	@echo "✅ Client pronto!"

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER_BONUS): $(OBJ_SERVER_BONUS) $(LIBFT) $(PRINTF)
	@$(CC) $(CFLAGS) $(OBJ_SERVER_BONUS) $(LIBS) -o $(SERVER_BONUS)
	@echo "✨ Server Bonus pronto!"

$(CLIENT_BONUS): $(OBJ_CLIENT_BONUS) $(LIBFT) $(PRINTF)
	@$(CC) $(CFLAGS) $(OBJ_CLIENT_BONUS) $(LIBS) -o $(CLIENT_BONUS)
	@echo "✨ Client Bonus pronto!"

$(LIBFT):
	@make -C libs/libft --no-print-directory

$(PRINTF):
	@make -C libs/ft_printf --no-print-directory

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@make -C libs/libft clean --no-print-directory
	@make -C libs/ft_printf clean --no-print-directory
	@echo "🧹 Objetos removidos."

fclean: clean
	@rm -f $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)
	@make -C libs/libft fclean --no-print-directory
	@make -C libs/ft_printf fclean --no-print-directory
	@echo "🗑️  Tudo limpo!"

re: fclean all

.PHONY: all bonus clean fclean re