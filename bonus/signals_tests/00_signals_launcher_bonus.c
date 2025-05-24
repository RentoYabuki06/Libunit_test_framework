/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_signals_launcher_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 16:01:18 by yabukirento       #+#    #+#             */
/*   Updated: 2025/05/24 17:25:58 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit_bonus.h"
#include "signals_tests_bonus.h"

int	signals_launcher(void)
{
	t_unit_test	*test_list;

	test_list = NULL;
	ft_printf("SIGNAL TESTS:\n");
	load_test(&test_list, "Segmentation fault (SIGSEGV)", &segv_test);
	load_test(&test_list, "Bus error (SIGBUS)", &bus_test);
	load_test(&test_list, "Abort (SIGABRT)", &abrt_test);
	load_test(&test_list, "Floating point exception (SIGFPE)", &fpe_test);
	load_test(&test_list, "Broken pipe (SIGPIPE)", &pipe_test);
	load_test(&test_list, "Illegal instruction (SIGILL)", &ill_test);
	load_test(&test_list, "Infinite loop (TIMEOUT)", &timeout_test);
	load_test(&test_list, "Sleep timeout (TIMEOUT)", &sleep_timeout_test);
	return (launch_tests(test_list));
}
