# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/18 18:28:55 by yabukirento       #+#    #+#              #
#    Updated: 2025/05/18 19:57:20 by yabukirento      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	main.c \
        srcs/launch_tests.c \
        srcs/load_test.c \
        tests/strlen/00_strlen_launcher.c \
        tests/strlen/00_strlen_basic.c \
        tests/strlen/01_strlen_null.c \
        tests/strchr/00_strchr_launcher.c \
        tests/strchr/01_strchr_basic.c \
        tests/strchr/02_strchr_not_found.c \
        tests/strchr/03_strchr_null_terminator.c \
        tests/atoi/00_atoi_launcher.c \
        tests/atoi/01_atoi_positive.c \
        tests/atoi/02_atoi_negative.c \
        tests/atoi/03_atoi_zero.c \
        tests/atoi/04_atoi_space.c \
        tests/atoi/05_atoi_plus_sign.c

OBJS = $(SRCS:.c=.o)

NAME = libunit
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I./includes -I./tests/strlen -I./tests/strchr -I./tests/atoi -I./srcs/libft/includes -I./srcs/printf/includes 

LIBFT_DIR = srcs/libft
LIBFT = $(LIBFT_DIR)/libft.a

PRINTF_DIR = srcs/printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

all: $(NAME)

$(LIBFT):
	@echo "Building libft..."
	@$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	@echo "Building printf..."
	@$(MAKE) -C $(PRINTF_DIR)

$(NAME): $(LIBFT) $(PRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $(OBJS) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf

%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re