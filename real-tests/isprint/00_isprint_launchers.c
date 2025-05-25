/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_isprint_launchers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:49:54 by enkwak            #+#    #+#             */
/*   Updated: 2025/05/25 17:15:58 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "isprint_tests.h"

int	isprint_launcher(void)
{
	t_unit_test	*test_list;

	test_list = NULL;
	load_test(&test_list, "Number test", &isprint_number_test);
	load_test(&test_list, "No number test", &isprint_char_test);
	load_test(&test_list, "other test", &isprint_other_test);
	return (launch_tests(&test_list, "ISPRINT"));
}
