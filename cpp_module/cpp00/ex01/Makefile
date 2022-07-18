CC = clang++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g
SRCS = phonebook.cpp contact.cpp main.cpp
OBJS = $(SRCS:%.cpp=%.o)
NAME = phonebook

all : $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean :
	rm -f $(OBJS)

fclean :
	rm -f $(OBJS) $(NAME)

re : fclean all

.PHONY: all clean fclean re
