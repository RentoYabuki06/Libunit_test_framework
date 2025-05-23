/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 18:28:45 by yabukirento       #+#    #+#             */
/*   Updated: 2025/05/23 20:18:48 by yabukirento      ###   ########.fr       */
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
        else
            ft_printf("%s[SIG %d]%s :", COLOR_SIG, sig, RESET);
    }
    else if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
        ft_printf("%s[OK]  %s :", COLOR_OK, RESET);
    else
        ft_printf("%s[KO]  %s :", COLOR_KO, RESET);
    ft_printf("%s\n", name);
}

static void	print_final_result(int count_success, int count_tests)
{
	if (count_success == count_tests)
        ft_printf("\n%s%d/%d tests passed.%s\n", COLOR_OK, count_success, count_tests, RESET);
    else
        ft_printf("\n%s%d/%d tests passed.%s\n", COLOR_KO, count_success, count_tests, RESET);
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
	print_final_result(count_success, count_tests);
    if (count_success == count_tests)
        return (0);
    else
        return (-1);
}
