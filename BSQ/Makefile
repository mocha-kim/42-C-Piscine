# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sunhkim <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/01 19:26:08 by sunhkim           #+#    #+#              #
#    Updated: 2020/11/03 21:18:18 by yoahn            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
TEMP = test
CC = gcc
CFLAGS = -Werror -Wall -Wextra
SRCS = check_map.c fileio.c main.c print.c solve.c string.c
OBJS = check_map.o fileio.o main.o print.o solve.o string.o

all: $(OBJS)
	gcc $(CFLAGS) -o $(NAME) $(OBJS)

.c.o:
	gcc $(CFLAGS) -c $(SRCS)

clean:
	rm $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: $(OBJS)
	gcc $(CFALGS) -o $(TEMP) $(OBJS)
