CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIB_DIR = ./libft

NAME = libftprintf.a

SRCS = ft_printf.c put_hex.c put_unsignedn.c

OBJS = $(SRCS:%.c=%.o)

$(NAME) : $(OBJS)
	$(MAKE) -C $(LIB_DIR) bonus
	cp $(LIB_DIR)/libft.a $@
	ar rcs $@ $^


all : $(NAME)

clean :
	$(MAKE) -C ./libft clean
	rm -rf $(OBJS)

fclean :
	$(MAKE) -C ./libft fclean
	rm -rf $(NAME) $(OBJS)

re : fclean all

.PHONY : all clean fclean re
