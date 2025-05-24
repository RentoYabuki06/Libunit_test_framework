/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_tests_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 18:28:45 by yabukirento       #+#    #+#             */
/*   Updated: 2025/05/24 16:01:56 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit_bonus.h"

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
        else if (sig == SIGTERM)
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

static void	print_final_result(int count_success, int count_tests)
{
    if (count_success == count_tests)
        ft_printf("\n%s%d/%d tests passed.%s\n", COLOR_OK, count_success, count_tests, RESET);
    else
        ft_printf("\n%s%d/%d tests passed.%s\n", COLOR_KO, count_success, count_tests, RESET);
}

static int wait_with_timeout(pid_t pid, int *status, int timeout)
{
    pid_t result;
    time_t start_time;
    time_t current_time;
    int time_elapsed;

    start_time = time(NULL);
    while (1)
    {
        result = waitpid(pid, status, WNOHANG);
        if (result != 0)
            return result;
        current_time = time(NULL);
        time_elapsed = (int)(current_time - start_time);
        
        if (time_elapsed >= timeout)
        {
            kill(pid, SIGTERM);
            usleep(10000);
            if (waitpid(pid, status, WNOHANG) == 0)
                kill(pid, SIGKILL);
            waitpid(pid, status, 0);
            return -1;
        }
        usleep(10000);
    }
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
        if (wait_with_timeout(pid, &status, TIMEOUT_SECONDS) == -1)
            ft_printf("%s[TIME]%s :%s (exceeded %d seconds)\n", COLOR_SIG, RESET, list->name, TIMEOUT_SECONDS);
        else
            print_result(list->name, status);
        if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
            count_success++;
        list = list->next;
        count_tests++;
    }
    print_final_result(count_success, count_tests);
    if (count_success == count_tests)
        return (0);
    return (-1);
}
