/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_atoi_launcher.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoch <enoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 20:00:00 by yabukirento       #+#    #+#             */
/*   Updated: 2025/05/25 11:48:02 by enoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "atoi_tests.h"

int	atoi_launcher_te(void)
{
	t_unit_test *testlist = NULL;

	load_test(&testlist, "ATOI BASIC", &atoi_minus_sign_test_te);
	load_test(&testlist, "ATOI FAIL", &atoi_fail_test_te);
	load_test(&testlist, "ATOI SEGV", &atoi_segv_test_te);
    load_test(&testlist, "ATOI SEGV", &atoi_positive_test_te);
    load_test(&testlist, "ATOI SEGV", &atoi_negative_test_te);
    load_test(&testlist, "ATOI SEGV", &atoi_zero_test_te);
    load_test(&testlist, "ATOI SEGV", &atoi_space_test_te);
    load_test(&testlist, "ATOI SEGV", &atoi_plus_sign_test_te);
	return (launch_tests(&testlist));
}
