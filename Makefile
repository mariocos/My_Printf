SRCS =	ft_printf.c \
		printfhelp.c \
		printfhelp1.c \
		printfhelp2.c \


OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a

HEAD = includes

CC = gcc

RM = rm -f

CFLAGS = -Wextra -Wall -Werror

AR = ar rcs

RANLIB = ranlib

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${HEAD}

${NAME}: ${OBJS}
	${AR} ${NAME} ${OBJS}
	${RANLIB} ${NAME}

all: ${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all fclean clean re


		