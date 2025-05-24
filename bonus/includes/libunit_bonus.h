/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 18:28:43 by yabukirento       #+#    #+#             */
/*   Updated: 2025/05/24 15:54:50 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_BONUS_H
# define LIBUNIT_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <signal.h>
# include "libft.h"
# include "ft_printf.h"
# include "colors_bonus.h"

#define TIMEOUT_SECONDS 10

typedef struct s_unit_test
{
    char				*name;
    int					(*test_func)(void);
    struct s_unit_test	*next;
}	t_unit_test;

void	load_test(t_unit_test **list, char *name, int (*test_func)(void));
int		launch_tests(t_unit_test *list);

#endif
