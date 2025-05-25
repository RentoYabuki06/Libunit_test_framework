# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/18 18:28:55 by yabukirento       #+#    #+#              #
#    Updated: 2025/05/25 15:24:41 by ryabuki          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = unit_tests

SRCS =	main.c \
		strlen/00_strlen_launcher.c \
		strlen/01_strlen_basic.c \
		strlen/02_strlen_null.c \
		strlen/03_strlen_segv.c \
		strlen/04_strlen_wrong_value.c \
		atoi/00_atoi_launcher.c \
		atoi/01_atoi_positive.c \
		atoi/02_atoi_negative.c \
		atoi/03_atoi_zero.c \
		atoi/04_atoi_space.c \
		atoi/05_atoi_plus_sign.c \
		atoi/06_atoi_segv_test.c \
		atoi/07_atoi_fail_test.c \
		atoi/08_atoi_backchar.c \
		strchr/00_strchr_launcher.c \
		strchr/01_strchr_basic.c \
		strchr/02_strchr_not_found.c \
		strchr/03_strchr_null_terminator.c

OBJS = $(SRCS:.c=.o)

FRAMEWORK_DIR = ../framework
FRAMEWORK = $(FRAMEWORK_DIR)/libunit.a
LIBFT_DIR = ../libft
PRINTF_DIR = ../printf

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I. -I$(FRAMEWORK_DIR)/includes -I$(LIBFT_DIR)/includes -I$(PRINTF_DIR)/includes
LIBS = -L$(FRAMEWORK_DIR) -lunit -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(FRAMEWORK) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(FRAMEWORK):
	@echo "Building framework..."
	@$(MAKE) -C $(FRAMEWORK_DIR)

test: $(NAME)
	@echo "Running tests..."
	@./$(NAME)

clean:
	rm -f $(OBJS)
	@$(MAKE) -C $(FRAMEWORK_DIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(FRAMEWORK_DIR) fclean

re: fclean all

