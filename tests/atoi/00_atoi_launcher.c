/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_atoi_launcher.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 20:00:00 by yabukirento       #+#    #+#             */
/*   Updated: 2025/05/25 13:49:05 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "atoi_tests.h"

int	atoi_launcher_te(void)
{
	t_unit_test *testlist = NULL;

	load_test(&testlist, "BASIC", &atoi_minus_sign_test_te);
	load_test(&testlist, "FAIL", &atoi_fail_test_te);
	load_test(&testlist, "SEGV", &atoi_segv_test_te);
    load_test(&testlist, "SEGV", &atoi_positive_test_te);
    load_test(&testlist, "SEGV", &atoi_negative_test_te);
    load_test(&testlist, "SEGV", &atoi_zero_test_te);
    load_test(&testlist, "SEGV", &atoi_space_test_te);
    load_test(&testlist, "SEGV", &atoi_plus_sign_test_te);
	return (launch_tests(&testlist, "ATOI"));
}
