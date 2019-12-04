SRCS = $(wildcard *.c libft/*.c)

OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a

CC   = gcc
CFLAGS = -Wall -Wextra -Werror


${NAME}: printf
printf: ${OBJS}
	ar rcs ${NAME} ${OBJS}

all: printf

clean:
	rm -f ${OBJS}
	rm -f *.gch

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re printf
