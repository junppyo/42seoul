CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
NAME = libft.a
HEADER = libft.h
SRCS = ft_isdigit.c ft_isalpha.c ft_memchr.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_strncmp.c ft_strchr.c ft_strrchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_striteri.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_split.c
SRCS_B = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJECTS = $(SRCS:%.c=%.o)

OBJECTS_B = $(SRCS_B:%.c=%.o)
ifdef WITH_BONUS
	OBJ_FILES = $(OBJECTS) $(OBJECTS_B)
else
	OBJ_FILES = $(OBJECTS)
endif

all : $(NAME)

$(NAME) : $(OBJ_FILES)
		ar rcs $(NAME) $(OBJ_FILES)

bonus :
	make WITH_BONUS=1 all
clean :
	rm -f $(OBJECTS) $(OBJECTS_B)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all bonus clean fclean re
