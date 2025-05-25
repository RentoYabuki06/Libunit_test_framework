/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_atoi_launcher.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 20:00:00 by yabukirento       #+#    #+#             */
/*   Updated: 2025/05/25 16:45:59 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "atoi_tests.h"

int	atoi_launcher_te(void)
{
	t_unit_test	*testlist;

	load_test(&testlist, "Positive test", &atoi_positive_test_te);
	load_test(&testlist, "Negative test", &atoi_negative_test_te);
	load_test(&testlist, "Zero test", &atoi_zero_test_te);
	load_test(&testlist, "Space test", &atoi_space_test_te);
	load_test(&testlist, "Plus sign test", &atoi_plus_sign_test_te);
	load_test(&testlist, "Segmentation fault test", &atoi_segv_test_te);
	load_test(&testlist, "Fail test", &atoi_fail_test_te);
	load_test(&testlist, "Minus sign test", &atoi_minus_sign_test_te);
	return (launch_tests(&testlist, "ATOI"));
}
