# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/18 18:28:55 by yabukirento       #+#    #+#              #
#    Updated: 2025/05/25 14:31:35 by ryabuki          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libunit.a
BONUS_NAME = libunit_bonus.a
SRC_DIR = srcs

MANDATORY_SRCS =	srcs/launch_tests.c \
					srcs/load_test.c \
					srcs/free_tests.c \

BONUS_SRCS =	bonus/srcs/launch_tests_bonus.c \
				bonus/srcs/load_test_bonus.c \

MANDATORY_OBJS = $(MANDATORY_SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

MANDATORY_INCLUDES = -I./includes -I../libft/includes -I../printf/includes
BONUS_INCLUDES = -I./bonus/includes -I../libft/includes -I../printf/includes

CC = cc
AR = ar
ARFLAGS = rcs
MANDATORY_CFLAGS = -Wall -Wextra -Werror -g $(MANDATORY_INCLUDES)
BONUS_CFLAGS = -Wall -Wextra -Werror -g $(BONUS_INCLUDES)

LIBFT_DIR = ../libft
LIBFT = $(LIBFT_DIR)/libft.a

PRINTF_DIR = ../printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

LIB = -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf

all: $(NAME)

bonus: $(BONUS_NAME)

$(LIBFT):
	@echo "Building libft..."
	@$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	@echo "Building printf..."
	@$(MAKE) -C $(PRINTF_DIR)

$(NAME): $(LIBFT) $(PRINTF) $(MANDATORY_OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(MANDATORY_OBJS)

$(BONUS_NAME): $(LIBFT) $(PRINTF) $(BONUS_OBJS)
	$(AR) $(ARFLAGS) $(BONUS_NAME) $(BONUS_OBJS)

srcs/%.o: srcs/%.c
	@mkdir -p $(dir $@)
	$(CC) $(MANDATORY_CFLAGS) -c $< -o $@

bonus/srcs/%.o: bonus/srcs/%.c
	@mkdir -p $(dir $@)
	$(CC) $(BONUS_CFLAGS) -c $< -o $@

clean:
	rm -f $(MANDATORY_OBJS) $(BONUS_OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

re_bonus: fclean bonus

.PHONY: all bonus clean fclean re re_bonus