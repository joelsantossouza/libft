# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/25 12:13:42 by joesanto          #+#    #+#              #
#    Updated: 2025/09/26 10:27:57 by joesanto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TEST=
CC=cc
FLAGS=-Wall -Wextra -Werror -g
EXTRA=
HEADER=../libft.h
LIB=ft

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
	rm -f $(TEST)

re: fclean all
