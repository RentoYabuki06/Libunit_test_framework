# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/25 16:46:30 by ryabuki           #+#    #+#              #
#    Updated: 2025/05/25 15:55:17 by ryabuki          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = signals_test_bonus

SRCS =	main_bonus.c \
		00_signals_launcher_bonus.c \
		01_segv_test_bonus.c \
		02_bus_test_bonus.c \
		03_abrt_test_bonus.c \
		04_fpe_test_bonus.c \
		05_pipe_test_bonus.c \
		06_ill_test_bonus.c \
		07_timeout_test_bonus.c \
		08_sleep_timeout_test_bonus.c

OBJS = $(SRCS:.c=.o)

FRAMEWORK_DIR = ../framework
FRAMEWORK = $(FRAMEWORK_DIR)/libunit.a
LIBFT_DIR = ../libft
PRINTF_DIR = ../printf

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I. -I$(FRAMEWORK_DIR)/bonus/includes -I$(LIBFT_DIR)/includes -I$(PRINTF_DIR)/includes
LIBS = -L$(FRAMEWORK_DIR) -lunit -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf

.PHONY: all clean fclean re test

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C $(FRAMEWORK_DIR) bonus
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)


%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(FRAMEWORK):
	@echo "Building framework..."
	@$(MAKE) -C $(FRAMEWORK_DIR) bonus

test: $(NAME)
	@echo "Running signal tests..."
	@./$(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all