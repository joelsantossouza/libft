# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/25 11:06:07 by joesanto          #+#    #+#              #
#    Updated: 2025/09/28 10:21:32 by joesanto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
SRCS=ft_strlen.c ft_strcmp.c ft_mempcpy.c ft_memcpy.c ft_stpcpy.c ft_strcpy.c

AR=ar crs
CC=cc
FLAGS=-Wall -Wextra -Werror
OBJS=$(SRCS:.c=.o)
HEADER=libft.h

all: $(NAME)

$(NAME): $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@
	$(AR) $(NAME) $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
