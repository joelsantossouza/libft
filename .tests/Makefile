# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/25 12:13:42 by joesanto          #+#    #+#              #
#    Updated: 2025/10/01 16:43:22 by joesanto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TEST=$(patsubst %.c, %, $(wildcard ft_*_test.c))

OBJS=$(addsuffix .o, $(TEST))
CC=cc
FLAGS=-Wall -Wextra -Werror -g
EXTRA=
LIB=ft

all: $(TEST)

ft_%_test: ft_%_test.o ../lib$(LIB).a
	$(CC) $< -latf-c -L.. -l$(LIB) -o $@

%.o: %.c
	$(CC) $(FLAGS) $(EXTRA) -c $< -o $@ -I..

../lib$(LIB).a:
	make -C ..

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TEST)

re: fclean all
