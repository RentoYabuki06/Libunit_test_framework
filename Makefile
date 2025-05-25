# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enoch <enoch@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/18 18:28:55 by yabukirento       #+#    #+#              #
#    Updated: 2025/05/25 11:56:49 by enoch            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMMON_TESTS =	real-tests/strlen/00_strlen_launcher.c \
		real-tests/isalnum/isalnum_char_test.c \
		real-tests/isalnum/isalnum_launchers.c \
		real-tests/isalnum/isalnum_number_test.c \
		real-tests/isalnum/isalnum_other_test.c \
		real-tests/isalpha/isalpha_char_test.c \
		real-tests/isalpha/isalpha_launchers.c \
		real-tests/isalpha/isalpha_number_test.c \
		real-tests/isalpha/isalpha_other_test.c \
		real-tests/isascii/isascii_char_test.c \
		real-tests/isascii/isascii_launchers.c \
		real-tests/isascii/isascii_number_test.c \
		real-tests/isascii/isascii_other_test.c \
		real-tests/isdigit/isdigit_char_test.c \
		real-tests/isdigit/isdigit.launchers.c \
		real-tests/isdigit/isdigit_number_test.c \
		real-tests/isdigit/isdigit_other_test.c \
		real-tests/isprint/isprint_char_test.c \
		real-tests/isprint/isprint_launchers.c \
		real-tests/isprint/isprint_number_test.c \
		real-tests/isprint/isprint_other_test.c \
		real-tests/strlen/00_strlen_basic.c \
		real-tests/strlen/01_strlen_null.c \
		real-tests/strchr/00_strchr_launcher.c \
		real-tests/strchr/01_strchr_basic.c \
		real-tests/strchr/02_strchr_not_found.c \
		real-tests/strchr/03_strchr_null_terminator.c \
		real-tests/atoi/00_atoi_launcher.c \
		real-tests/atoi/01_atoi_positive.c \
		real-tests/atoi/02_atoi_negative.c \
		real-tests/atoi/03_atoi_zero.c \
		real-tests/atoi/04_atoi_space.c \
		real-tests/atoi/05_atoi_plus_sign.c \
		tests/atoi/00_atoi_launcher.c \
		tests/atoi/02_atoi_negative.c \
		tests/atoi/04_atoi_space.c \
		tests/atoi/01_atoi_positive.c \
		tests/atoi/03_atoi_zero.c \
		tests/atoi/05_atoi_plus_sign.c \
		tests/atoi/06_atoi_segv_test.c \
		tests/atoi/07_atoi_fail_test.c \
		tests/atoi/08_atoi_backchar.c \
		tests/strchr/00_strchr_launcher.c \
		tests/strchr/01_strchr_basic.c \
		tests/strchr/02_strchr_not_found.c \
		tests/strchr/03_strchr_null_terminator.c \
		tests/strlen/00_strlen_basic.c \
		tests/strlen/01_strlen_null.c \
		tests/strlen/02_strlen_segv.c \
		tests/strlen/03_strlen_wrong_value.c \

MANDATORY_SRCS =	framework/main.c \
		framework/launch_tests.c \
		framework/load_test.c \
		framework/free_tests.c \
		$(COMMON_TESTS)

BONUS_SRCS =	bonus/main_bonus.c \
		bonus/srcs/launch_tests_bonus.c \
		bonus/srcs/load_test_bonus.c \
		$(COMMON_TESTS) \
		bonus/signals_tests/00_signals_launcher_bonus.c \
		bonus/signals_tests/01_segv_test_bonus.c \
		bonus/signals_tests/02_bus_test_bonus.c \
		bonus/signals_tests/03_abrt_test_bonus.c \
		bonus/signals_tests/04_fpe_test_bonus.c \
		bonus/signals_tests/05_pipe_test_bonus.c \
		bonus/signals_tests/06_ill_test_bonus.c \
		bonus/signals_tests/07_timeout_test_bonus.c \
		bonus/signals_tests/08_sleep_timeout_test_bonus.c

MANDATORY_OBJS = $(MANDATORY_SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

NAME = libunit
BONUS_NAME = libunit_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

PRINTF_DIR = ./printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

INCLUDES = -I./framework -I./libft/includes -I./printf/includes -I./tests -I./real-tests
BONUS_INCLUDES = -I./bonus/includes -I./libft/includes -I./printf/includes -I./tests -I./real-tests -I./bonus/signals_tests


all: $(NAME)

bonus: $(BONUS_NAME)

$(LIBFT):
	@echo "Building libft..."
	@$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	@echo "Building printf..."
	@$(MAKE) -C $(PRINTF_DIR)

$(NAME): $(LIBFT) $(PRINTF) $(MANDATORY_OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $(MANDATORY_OBJS) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf

$(BONUS_NAME): $(LIBFT) $(PRINTF) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_INCLUDES) -o $@ $(BONUS_OBJS) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf

framework/%.o: framework/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

bonus/%.o: bonus/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(BONUS_INCLUDES) -c $< -o $@

tests/%.o: tests/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

real-tests/%.o: real-tests/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# tests/%.o real-tests/%.o: tests/%.c real-tests/%.c
# 	@mkdir -p $(dir $@)
# 	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

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

.PHONY: all bonus clean fclean re re_bonus test

# COMMON_TESTS =	tests/strlen/00_strlen_launcher.c \
# 		tests/strlen/00_strlen_basic.c \
# 		tests/strlen/01_strlen_null.c \
# 		tests/strchr/00_strchr_launcher.c \
# 		tests/strchr/01_strchr_basic.c \
# 		tests/strchr/02_strchr_not_found.c \
# 		tests/strchr/03_strchr_null_terminator.c \
# 		tests/atoi/00_atoi_launcher.c \
# 		tests/atoi/01_atoi_positive.c \
# 		tests/atoi/02_atoi_negative.c \
# 		tests/atoi/03_atoi_zero.c \
# 		tests/atoi/04_atoi_space.c \
# 		tests/atoi/05_atoi_plus_sign.c

# MANDATORY_SRCS =	framework/main.c \
# 		framework/launch_tests.c \
# 		framework/load_test.c \
# 		framework/free_tests.c \
# 		$(COMMON_TESTS)

# BONUS_SRCS =	bonus/main_bonus.c \
# 		bonus/srcs/launch_tests_bonus.c \
# 		bonus/srcs/load_test_bonus.c \
# 		$(COMMON_TESTS) \
# 		bonus/signals_tests/00_signals_launcher_bonus.c \
# 		bonus/signals_tests/01_segv_test_bonus.c \
# 		bonus/signals_tests/02_bus_test_bonus.c \
# 		bonus/signals_tests/03_abrt_test_bonus.c \
# 		bonus/signals_tests/04_fpe_test_bonus.c \
# 		bonus/signals_tests/05_pipe_test_bonus.c \
# 		bonus/signals_tests/06_ill_test_bonus.c \
# 		bonus/signals_tests/07_timeout_test_bonus.c \
# 		bonus/signals_tests/08_sleep_timeout_test_bonus.c

# MANDATORY_OBJS = $(MANDATORY_SRCS:.c=.o)
# BONUS_OBJS = $(BONUS_SRCS:.c=.o)

# NAME = libunit
# BONUS_NAME = libunit_bonus
# CC = cc
# CFLAGS = -Wall -Wextra -Werror -g

# LIBFT_DIR = ./libft
# LIBFT = $(LIBFT_DIR)/libft.a

# PRINTF_DIR = ./printf
# PRINTF = $(PRINTF_DIR)/libftprintf.a

# INCLUDES = -I./framework -I./libft/includes -I./printf/includes -I./tests -I./real-tests
# BONUS_INCLUDES = -I./bonus/includes -I./libft/includes -I./printf/includes -I./tests -I./real-tests -I./bonus/signals_tests


# all: $(NAME)

# bonus: $(BONUS_NAME)

# $(LIBFT):
# 	@echo "Building libft..."
# 	@$(MAKE) -C $(LIBFT_DIR)

# $(PRINTF):
# 	@echo "Building printf..."
# 	@$(MAKE) -C $(PRINTF_DIR)

# $(NAME): $(LIBFT) $(PRINTF) $(MANDATORY_OBJS)
# 	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $(MANDATORY_OBJS) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf

# $(BONUS_NAME): $(LIBFT) $(PRINTF) $(BONUS_OBJS)
# 	$(CC) $(CFLAGS) $(BONUS_INCLUDES) -o $@ $(BONUS_OBJS) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf

# framework/%.o: framework/%.c
# 	@mkdir -p $(dir $@)
# 	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# bonus/%.o: bonus/%.c
# 	@mkdir -p $(dir $@)
# 	$(CC) $(CFLAGS) $(BONUS_INCLUDES) -c $< -o $@

# tests/%.o real-tests/%.o: tests/%.c real-tests/%.c
# 	@mkdir -p $(dir $@)
# 	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# %.o: %.c
# 	@mkdir -p $(dir $@)
# 	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# clean:
# 	rm -f $(MANDATORY_OBJS) $(BONUS_OBJS)
# 	@$(MAKE) -C $(LIBFT_DIR) clean
# 	@$(MAKE) -C $(PRINTF_DIR) clean

# fclean: clean
# 	rm -f $(NAME) $(BONUS_NAME)
# 	@$(MAKE) -C $(LIBFT_DIR) fclean
# 	@$(MAKE) -C $(PRINTF_DIR) fclean

# re: fclean all

# re_bonus: fclean bonus

# .PHONY: all bonus clean fclean re re_bonus