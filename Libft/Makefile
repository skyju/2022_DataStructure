NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = *.c
OBJS = $(SRCS:.c=.o)
INC = includes

.c.o :
	${CC} ${CFLAGS} -c $^ -I ${INC}

$(NAME) : $(OBJS)
	ar rc $@ $(OBJS)

bonus : $(OBJS)
	ar rc $(NAME) $^

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : bonus all clean fclean re