/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 18:28:45 by yabukirento       #+#    #+#             */
/*   Updated: 2025/05/25 16:43:09 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

static void	print_each_result(char *func_name, char *test_name, int status)
{
	int	sig;

	ft_printf("%s: %s : ", func_name, test_name);
	if (WIFEXITED(status) == 0)
	{
		sig = WTERMSIG(status);
		if (sig == SIGSEGV)
			ft_printf("[SEGV]");
		else if (sig == SIGBUS)
			ft_printf("[BUSE]");
		else if (sig == SIGABRT)
			ft_printf("[ABRT]");
		else
			ft_printf("[SIG %d]", sig);
	}
	else if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
		ft_printf("[OK]");
	else
		ft_printf("[KO]");
	ft_printf("\n");
}

static int	print_final_result(char count_success, int count_tests)
{
	if (count_tests < 1)
		return (-1);
	if (count_tests == 1)
		ft_printf("\n%d/1 test checked.\n", count_success);
	else
		ft_printf("\n%d/%d tests checked.\n", count_success, count_tests);
	if (count_success == count_tests)
		return (0);
	return (-1);
}

static int	loop(char *func_name, t_unit_test *list, int c_success, int c_tests)
{
	pid_t	pid;
	int		status;

	while (list)
	{
		pid = fork();
		if (pid < 0)
		{
			perror("fork failed");
			ft_printf("%s: %s: [Fork failed]\n", func_name, list->name);
			list = list->next;
			c_tests++;
			continue ;
		}
		else if (pid == 0)
			exit(list->test_func());
		waitpid(pid, &status, 0);
		print_each_result(func_name, list->name, status);
		if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
			c_success++;
		list = list->next;
		c_tests++;
	}
	return (print_final_result(c_success, c_tests));
}

int	launch_tests(t_unit_test **list, char *func_name)
{
	t_unit_test	*testlist;

	testlist = NULL;
	if (func_name == NULL)
		return (ft_printf("Error: function name is NULL.\n"), -1);
	if (list && *list)
		testlist = *list;
	if (testlist == NULL)
		return (ft_printf("No tests found for %s.\n", func_name), -1);
	ft_printf("\n------ [%s] test ------\n", func_name);
	return (loop(func_name, testlist, 0, 0));
}
