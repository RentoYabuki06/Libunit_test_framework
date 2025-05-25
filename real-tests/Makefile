# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/25 16:15:30 by ryabuki           #+#    #+#              #
#    Updated: 2025/05/25 15:37:30 by ryabuki          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = real_tests

SRCS =	main.c \
		strlen/00_strlen_launcher.c \
		strlen/01_strlen_basic.c \
		strlen/02_strlen_null.c \
		strchr/00_strchr_launcher.c \
		strchr/01_strchr_basic.c \
		strchr/02_strchr_not_found.c \
		strchr/03_strchr_null_terminator.c \
		atoi/00_atoi_launcher.c \
		atoi/01_atoi_positive.c \
		atoi/02_atoi_negative.c \
		atoi/03_atoi_zero.c \
		atoi/04_atoi_space.c \
		atoi/05_atoi_plus_sign.c \
		isalnum/00_isalnum_launchers.c \
		isalnum/01_isalnum_char_test.c \
		isalnum/02_isalnum_number_test.c \
		isalnum/03_isalnum_other_test.c \
		isalpha/00_isalpha_launchers.c \
		isalpha/01_isalpha_char_test.c \
		isalpha/02_isalpha_number_test.c \
		isalpha/03_isalpha_other_test.c \
		isascii/00_isascii_launchers.c \
		isascii/01_isascii_char_test.c \
		isascii/02_isascii_number_test.c \
		isascii/03_isascii_other_test.c \
		isdigit/00_isdigit_launchers.c \
		isdigit/01_isdigit_char_test.c \
		isdigit/02_isdigit_number_test.c \
		isdigit/03_isdigit_other_test.c \
		isprint/00_isprint_launchers.c \
		isprint/01_isprint_char_test.c \
		isprint/02_isprint_number_test.c \
		isprint/03_isprint_other_test.c

OBJS = $(SRCS:.c=.o)

FRAMEWORK_DIR = ../framework
FRAMEWORK = $(FRAMEWORK_DIR)/libunit.a
LIBFT_DIR = ../libft
PRINTF_DIR = ../printf

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I. -I$(FRAMEWORK_DIR)/includes -I$(LIBFT_DIR)/includes -I$(PRINTF_DIR)/includes
LIBS = -L$(FRAMEWORK_DIR) -lunit -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf

.PHONY: all clean fclean re test

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