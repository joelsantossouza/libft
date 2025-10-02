# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/25 12:13:42 by joesanto          #+#    #+#              #
#    Updated: 2025/10/02 09:41:47 by joesanto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TEST=$(patsubst %.c, %, $(SRCS))

SRCS=$(wildcard ft_*_test.c)
OBJS=$(SRCS:.c=.o)
CC=cc
FLAGS=-Wall -Wextra -Werror -g
EXTRA=
LIB=ft

all: $(TEST)

ft_%_test: ft_%_test.o $(LIB)
	$(CC) $< -latf-c -L.. -l$(LIB) -o $@

%.o: %.c
	$(CC) $(FLAGS) $(EXTRA) -c $< -o $@ -I..

$(LIB):
	make -C ..

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TEST)

re: fclean all

FIND=$(shell find .. -maxdepth 1 -name "ft_*.c" -exec basename {} .c \;)
missing:
	@echo "---> TESTS MISSING <---\n"
	@for file in $(FIND); do \
		if echo "$(SRCS)" | grep -qv "$${file}_test.c"; then \
		echo "> $${file}_test.c"; \
		fi; \
	done
	@echo "\nTotal of Tests: $(words $(TEST))/$(words $(FIND))"
