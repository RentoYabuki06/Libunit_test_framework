/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_strlen_launcher.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoch <enoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 20:00:00 by yabukirento       #+#    #+#             */
/*   Updated: 2025/05/25 11:48:36 by enoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "strlen_tests.h"

int	strlen_launcher_te(void)
{
	t_unit_test	*testlist;

	testlist = NULL;
	load_test(&testlist, "STRLEN BASIC", &strlen_basic_test_te);
    load_test(&testlist, "STRLEN BASIC", &strlen_null_test_te);
	load_test(&testlist, "STRLEN SEGV", &strlen_segv_test_te);
	load_test(&testlist, "STRLEN WRONG VALUE", &strlen_wrong_value_test_te);
	return (launch_tests(&testlist));
}
