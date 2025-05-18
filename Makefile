# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/18 18:28:55 by yabukirento       #+#    #+#              #
#    Updated: 2025/05/18 18:44:50 by yabukirento      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	main.c \
		srcs/launch_tests.c \
		srcs/load_test.c \
		srcs/utils.c \
		tests/strlen/00_strlen_basic.c \
		tests/strlen/01_strlen_null.c \

OBJS = $(SRCS:.c=.o)

NAME = libunit
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I./includes

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re