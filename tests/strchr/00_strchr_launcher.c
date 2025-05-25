/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_strchr_launcher.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoch <enoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 20:00:00 by yabukirento       #+#    #+#             */
/*   Updated: 2025/05/25 11:48:17 by enoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "strchr_tests.h"

int	strchr_launcher_te(void)
{
	t_unit_test *testlist = NULL;

	load_test(&testlist, "STRCHR BASIC", &strchr_basic_test_te);
	load_test(&testlist, "STRCHR NOT FOUND", &strchr_not_found_test_te);
	load_test(&testlist, "STRCHR SEGV", &strchr_segv_test_te);
	return (launch_tests(&testlist));
}
