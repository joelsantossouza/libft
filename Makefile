# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/25 11:06:07 by joesanto          #+#    #+#              #
#    Updated: 2025/09/28 20:33:08 by joesanto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
SRCS=ft_strlen.c ft_strnlen.c ft_strcmp.c ft_mempcpy.c ft_memcpy.c ft_stpcpy.c ft_strcpy.c ft_strlcpy.c \
ft_strlcat.c ft_islower.c ft_isupper.c ft_isspace.c ft_isdigit.c

AR=ar crs
CC=cc
FLAGS=-Wall -Wextra -Werror -g
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
