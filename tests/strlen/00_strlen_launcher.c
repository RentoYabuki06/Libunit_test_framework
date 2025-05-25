/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_strlen_launcher.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 13:44:25 by ryabuki           #+#    #+#             */
/*   Updated: 2025/05/25 16:48:11 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "strlen_tests.h"

int	strlen_launcher_te(void)
{
	t_unit_test	*testlist;

	testlist = NULL;
	load_test(&testlist, "Basic test", &strlen_basic_test_te);
	load_test(&testlist, "Null test", &strlen_null_test_te);
	load_test(&testlist, "Segmantation fault test", &strlen_segv_test_te);
	load_test(&testlist, "Wrong value test", &strlen_wrong_value_test_te);
	return (launch_tests(&testlist, "STRLEN"));
}
