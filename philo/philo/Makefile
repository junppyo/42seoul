CC = GCC
FLAGS = -Wall -Wextra -Werror
NAME = philo
SRCS = init.c main.c utils.c utils2.c dinner.c ft_atoi.c
OBJECTS = $(SRCS:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) -o $(NAME)

clean :
	rm -rf $(OBJECTS)

fclean :
	rm -rf $(OBJECTS) $(NAME)

re : fclean all
