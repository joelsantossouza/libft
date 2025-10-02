# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/25 12:13:42 by joesanto          #+#    #+#              #
#    Updated: 2025/10/02 10:52:20 by joesanto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TEST=$(patsubst %.c, %, $(SRCS))

SRCS=$(wildcard ft_*_test.c)
OBJS=$(SRCS:.c=.o)
HEADER_DIR=..
CC=cc
FLAGS=-Wall -Wextra -Werror -g
EXTRA=
LIB=ft
LIB_DIR=..

.SECONDARY: $(OBJS) $(LIB_DIR)/lib$(LIB).a

all: $(TEST)

ft_%_test: ft_%_test.o $(LIB_DIR)/lib$(LIB).a
	$(CC) $< -latf-c -L$(LIB_DIR) -l$(LIB) -o $@

ft_%_test.o: ft_%_test.c
	$(CC) $(FLAGS) $(EXTRA) -c $< -o $@ -I$(HEADER_DIR)

$(LIB_DIR)/lib%.a: $(wildcard $(LIB_DIR)/*.c)
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
