/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_atoi_launcher.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 20:00:00 by yabukirento       #+#    #+#             */
/*   Updated: 2025/05/25 16:55:25 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "atoi_tests.h"

int	atoi_launcher(void)
{
	t_unit_test	*test_list;

	test_list = NULL;
	load_test(&test_list, "Positive number test", &atoi_positive_test);
	load_test(&test_list, "Negative number test", &atoi_negative_test);
	load_test(&test_list, "Zero test", &atoi_zero_test);
	load_test(&test_list, "Space test", &atoi_space_test);
	load_test(&test_list, "Plus sign test", &atoi_plus_sign_test);
	return (launch_tests(&test_list, "ATOI"));
}
