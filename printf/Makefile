# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/03 14:59:44 by yabukirento       #+#    #+#              #
#    Updated: 2025/05/18 19:25:50 by yabukirento      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./includes

SRCS =	srcs/ft_printf.c \
		srcs/print_functions/ft_print_hex.c \
		srcs/print_functions/ft_print_percent.c \
		srcs/print_functions/ft_print_unsigned.c \
		srcs/print_functions/ft_print_char.c \
		srcs/print_functions/ft_print_nbr.c \
		srcs/print_functions/ft_print_ptr.c \
		srcs/print_functions/ft_print_str.c

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

srcs/%.o: srcs/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
