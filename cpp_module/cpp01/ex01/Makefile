CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = Zombie.cpp Zombiehorde.cpp main.cpp
OBJS = $(SRCS:%.cpp=%.o)
NAME = zombie 

all : $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@
	
$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean :
	rm -f $(OBJS)

fclean :
	rm -f $(OBJS) $(NAME)

re : fclean all

.PHONY: all clean fclean re
