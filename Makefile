# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/25 11:06:07 by joesanto          #+#    #+#              #
#    Updated: 2025/09/30 20:38:45 by joesanto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
SRCS=ft_strlen.c ft_strnlen.c ft_strcmp.c ft_strncmp.c ft_mempcpy.c ft_memcpy.c ft_memmove.c ft_mempset.c \
ft_memset.c ft_bzero.c ft_memchr.c ft_memcmp.c ft_stpcpy.c ft_strcpy.c ft_strlcpy.c ft_strlcat.c ft_islower.c \
ft_isupper.c ft_isspace.c ft_isdigit.c ft_isalpha.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c \
ft_tolower.c ft_strchr.c ft_strrchr.c ft_strchrnul.c ft_atoi_base.c ft_atoi.c ft_strnstr.c ft_calloc.c \
ft_strdup.c ft_strndup.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_striteri.c ft_strmapi.c \
ft_substr.c ft_strjoin.c ft_strtrim.c ft_freearray.c

AR=ar rcs
CC=cc
FLAGS=-Wall -Wextra -Werror -g
OBJS=$(SRCS:.c=.o)
HEADER=libft.h

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
