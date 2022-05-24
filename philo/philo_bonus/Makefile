CC = GCC
CFLAGS = -Wall -Wextra -Werror
NAME = philo
SRC = init.c main.c utils.c dinner.c ft_atoi.c monitor.c

OBJECTS = $(SRC:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

clean :
	rm -rf $(OBJECTS)

fclean :
	rm -rf $(OBJECTS) $(NAME)

re : fclean all
