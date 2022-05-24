CC = gcc
CFLAGS = -Wall -Wextra -Werror

SERVER = server
CLIENT = client

LIB_DIR = ./ft_printf
LIB = $(addprefix $(LIB_DIR)/, libftprintf.a)

NAME = minitalk

SERVER_SRC = server.c
CLIENT_SRC = client.c


SERVER_OBJ = $(SERVER_SRC:%.c=%.o)

CLIENT_OBJ = $(CLIENT_SRC:%.c=%.o)

$(LIB) :
	$(MAKE) -C $(LIB_DIR)

$(SERVER) : $(SERVER_OBJ)
	$(CC) $(SERVER_OBJ) $(LIB) -o $(SERVER)

$(CLIENT) : $(CLIENT_OBJ)
	$(CC) $(CLIENT_OBJ) $(LIB) -o $(CLIENT)

all : $(NAME)

$(NAME) : $(LIB) $(SERVER) $(CLIENT)

clean :
	$(MAKE) -C $(LIB_DIR) clean
	rm -rf $(SERVER_OBJ)
	rm -rf $(CLIENT_OBJ)

fclean :
	$(MAKE) -C $(LIB_DIR) fclean
	rm -rf $(NAME) $(SERVER_OBJ) $(CLIENT_OBJ) $(LIB) $(SERVER) $(CLIENT)

re : fclean all
