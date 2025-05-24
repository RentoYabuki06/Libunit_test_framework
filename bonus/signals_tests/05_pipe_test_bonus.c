/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_pipe_test_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 16:01:35 by yabukirento       #+#    #+#             */
/*   Updated: 2025/05/24 17:27:50 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit_bonus.h"
#include <unistd.h>
#include <signal.h>

int	pipe_test(void)
{
	int	pipefd[2];

	if (pipe(pipefd) < 0)
		return (-1);
	close(pipefd[0]);
	signal(SIGPIPE, SIG_DFL);
	write(pipefd[1], "test", 4);
	close(pipefd[1]);
	write(pipefd[0], "more data", 9);
	return (0);
}
