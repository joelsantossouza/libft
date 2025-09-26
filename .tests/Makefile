# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/25 12:13:42 by joesanto          #+#    #+#              #
#    Updated: 2025/09/26 11:41:30 by joesanto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TEST=
CC=cc
FLAGS=-Wall -Wextra -Werror -g
EXTRA=
HEADER=../libft.h
LIB=ft
ALL_TESTS=$(wildcard *_test.c)

all: $(TEST)

$(TEST): $(TEST).o $(LIB)
	$(CC) $< -latf-c -L.. -l$(LIB) -o $@

$(TEST).o: $(TEST).c $(HEADER)
	$(CC) $(FLAGS) $(EXTRA) -c $< -o $@ -I ..

$(LIB):
	make -C ..

clean:
	rm -f *.o

fclean: clean
	@if [ -z "$(findstring $(TEST), $(ALL_TESTS))" ]; then \
		echo "\nNot such tests: \"$(TEST)\". Availables:"; \
		echo " $(ALL_TESTS)" | sed 's/ /\n> /g'; \
		echo ""; \
		exit 1; \
	fi
	rm -f $(TEST)

re: fclean all
