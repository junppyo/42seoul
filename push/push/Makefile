CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIB_DIR = ./ft_printf
LIB = $(addprefix $(LIB_DIR)/, libftprintf.a)

NAME = push_swap
NAME_B = checker

SRCS = init.c operation.c swap.c utils.c utils2.c check.c
SRCS_M = main.c
SRCS_B = bonus.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJS = $(SRCS:%.c=%.o)
OBJS_M = $(SRCS_M:%.c=%.o)
OBJS_B = $(SRCS_B:%.c=%.o)

$(NAME) : $(OBJS) $(OBJS_M)
	$(MAKE) -C $(LIB_DIR)
	$(CC) $(OBJS) $(OBJS_M) $(LIB) -o $(NAME)

$(NAME_B) : $(OBJS) $(OBJS_B)
	$(MAKE) -C $(LIB_DIR)
	$(CC) $(OBJS) $(OBJS_B) $(LIB) -o $(NAME_B)

bonus : $(NAME) $(NAME_B)

all : $(NAME)

clean :
	$(MAKE) -C $(LIB_DIR) clean
	rm -rf $(OBJS) $(OBJS_M) $(OBJS_B)

fclean :
	$(MAKE) -C $(LIB_DIR) fclean
	rm -rf $(NAME) $(NAME_B) $(OBJS) $(OBJS_B) $(OBJS_M)

re : fclean all

.PHONY : all bonus clean fclean re
