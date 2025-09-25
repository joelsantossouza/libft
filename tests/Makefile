# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/25 12:13:42 by joesanto          #+#    #+#              #
#    Updated: 2025/09/25 17:55:04 by joesanto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=
CC=cc
FLAGS=-Wall -Wextra -Werror -g
EXTRA=
HEADER=../libft.h
LIB=ft

all: $(NAME)

$(NAME): $(NAME).o $(LIB)
	$(CC) $< -latf-c -L.. -l$(LIB) -o $@

$(NAME).o: $(NAME).c $(HEADER)
	$(CC) $(FLAGS) $(EXTRA) -c $< -o $@ -I ..

$(LIB):
	make -C ..

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
