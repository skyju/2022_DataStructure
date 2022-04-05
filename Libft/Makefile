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

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
