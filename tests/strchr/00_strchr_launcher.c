/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_strchr_launcher.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 20:00:00 by yabukirento       #+#    #+#             */
/*   Updated: 2025/05/25 13:49:14 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "strchr_tests.h"

int	strchr_launcher_te(void)
{
	t_unit_test *testlist = NULL;

	load_test(&testlist, "Basic test", &strchr_basic_test_te);
	load_test(&testlist, "Not found test", &strchr_not_found_test_te);
	load_test(&testlist, "Segmentation fault test", &strchr_segv_test_te);
	return (launch_tests(&testlist, "STRCHR"));
}
