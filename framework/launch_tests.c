/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 18:28:45 by yabukirento       #+#    #+#             */
/*   Updated: 2025/05/24 16:07:00 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

static void	print_result(char *name, int status)
{
	int	sig;

	if (WIFEXITED(status) == 0)
	{
		sig = WTERMSIG(status);
		if (sig == SIGSEGV)
			ft_printf("[SEGV] :");
		else if (sig == SIGBUS)
			ft_printf("[BUSE] :");
		else if (sig == SIGABRT)
			ft_printf("[ABRT] :");
		else
			ft_printf("[SIG %d] :", sig);
	}
	else if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
		ft_printf("[OK]   :");
	else
		ft_printf("[KO]   :");
	ft_printf("%s\n", name);
}

int	launch_tests(t_unit_test *list)
{
	pid_t	pid;
	int		status;
	int		count_success;
	int		count_tests;

	count_success = 0;
	count_tests = 0;
	while (list)
	{
		pid = fork();
		if (pid == 0)
			exit(list->test_func());
		waitpid(pid, &status, 0);
		print_result(list->name, status);
		if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
			count_success++;
		list = list->next;
		count_tests++;
	}
	ft_printf("\n%d/%d tests passed.\n", count_success, count_tests);
	if (count_success == count_tests)
		return (0);
	return (-1);
}
