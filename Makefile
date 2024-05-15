# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mariocos <mariocos@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/15 15:13:23 by mariocos          #+#    #+#              #
#    Updated: 2024/05/15 15:34:26 by mariocos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	ft_printf.c \
		printf_utils.c \
		printf_d_i_utils.c \
		printf_p_u_utils.c \
		printf_x_X_utils.c


OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a

HEAD = includes

CC = cc

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


		