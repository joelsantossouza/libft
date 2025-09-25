# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/25 11:06:07 by joesanto          #+#    #+#              #
#    Updated: 2025/09/25 12:07:04 by joesanto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
SRCS=ft_strlen.c

AR=ar crs
CC=cc
FLAGS=-Wall -Wextra -Werror
EXTRA=
OBJS=$(SRCS:.c=.o)
HEADER=libft.h

all: $(NAME)

$(NAME): $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) $(EXTRA) -c $< -o $@
	$(AR) $(NAME) $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

norm:
	@norminette -R checkForbidenSourceHeader .
