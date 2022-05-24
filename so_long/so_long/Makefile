CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB_DIR = ./ft_printf
LIB = $(addprefix $(LIB_DIR)/, libftprintf.a)

MLX_DIR = ./mlx
MLX = $(addprefix $(MLX_DIR)/, libmlx.dylib)

NAME = so_long

SRC = check.c draw.c main.c collision.c init.c utils.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJ = $(SRC:%.c=%.o)

all : $(NAME)

$(LIB) :
	$(MAKE) -C $(LIB_DIR)

$(MLX) :
	$(MAKE) -C $(MLX_DIR)
	cp $(MLX) .

$(NAME) : $(LIB) $(MLX) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -L$(MLX_DIR) -lmlx -framework OpenGL -framework Appkit -o $(NAME)

clean :
	$(MAKE) -C $(LIB_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -rf $(OBJ)

fclean :
	$(MAKE) -C $(LIB_DIR) fclean
	$(MAKE) -C $(MLX_DIR) clean
	rm -rf $(OBJ) $(NAME) libmlx.dylib

re : fclean all
