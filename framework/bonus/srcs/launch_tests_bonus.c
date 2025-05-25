/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_tests_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 18:28:45 by yabukirento       #+#    #+#             */
/*   Updated: 2025/05/25 13:12:54 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit_bonus.h"
#include <signal.h>
#include <errno.h>

static void	print_result(char *name, int status, int sig)
{
	if (WIFEXITED(status) == 0)
	{
		sig = WTERMSIG(status);
		if (sig == SIGSEGV)
			ft_printf("%s[SEGV]%s :", COLOR_SIG, RESET);
		else if (sig == SIGBUS)
			ft_printf("%s[BUSE]%s :", COLOR_SIG, RESET);
		else if (sig == SIGABRT)
			ft_printf("%s[ABRT]%s :", COLOR_SIG, RESET);
		else if (sig == SIGFPE)
			ft_printf("%s[FPE]%s :", COLOR_SIG, RESET);
		else if (sig == SIGPIPE)
			ft_printf("%s[PIPE]%s :", COLOR_SIG, RESET);
		else if (sig == SIGILL)
			ft_printf("%s[ILL]%s :", COLOR_SIG, RESET);
		else if (sig == SIGALRM)
			ft_printf("%s[TIME]%s :", COLOR_SIG, RESET);
		else
			ft_printf("%s[SIG %d]%s :", COLOR_SIG, sig, RESET);
	}
	else if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
		ft_printf("%s[OK]  %s :", COLOR_OK, RESET);
	else
		ft_printf("%s[KO]  %s :", COLOR_KO, RESET);
	ft_printf("%s\n", name);
}

static void	alarm_handler(int sig)
{
	(void)sig;
}

static int	wait_with_alarm(pid_t pid, int *status, int timeout_sec)
{
	struct sigaction	sa;
	struct sigaction	old_sa;
	pid_t				result;
	int					was_timeout;

	was_timeout = 0;
	sa.sa_handler = alarm_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGALRM, &sa, &old_sa);
	alarm(timeout_sec);
	result = waitpid(pid, status, 0);
	if (alarm(0) == 0 && result == -1 && errno == EINTR)
	{
		was_timeout = 1;
		usleep(10000);
		waitpid(pid, status, WNOHANG);
	}
	sigaction(SIGALRM, &old_sa, NULL);
	if (was_timeout)
		return (-1);
	return (result);
}

static void	loop(t_unit_test *list, int *count_success, int *count_tests)
{
	pid_t	pid;
	int		status;

	while (list)
	{
		pid = fork();
		if (pid == 0)
		{
			signal(SIGALRM, SIG_DFL);
			exit(list->test_func());
		}
		if (wait_with_alarm(pid, &status, TIMEOUT_SECONDS) == -1)
		{
			ft_printf("%s[TIME]%s :%s (exceeded %d seconds)\n",
				COLOR_SIG, RESET, list->name, TIMEOUT_SECONDS);
		}
		else
			print_result(list->name, status, 0);
		if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
			(*count_success)++;
		list = list->next;
		(*count_tests)++;
	}
}

int	launch_tests(t_unit_test *list)
{
	int		count_success;
	int		count_tests;

	count_success = 0;
	count_tests = 0;
	loop(list, &count_success, &count_tests);
	if (count_success == count_tests)
		ft_printf("\n%s%d/%d", COLOR_OK, count_success, count_tests);
	else
		ft_printf("\n%s%d/%d", COLOR_KO, count_success, count_tests);
	ft_printf("tests checked.%s\n", RESET);
	if (count_success == count_tests)
		return (0);
	return (-1);
}
