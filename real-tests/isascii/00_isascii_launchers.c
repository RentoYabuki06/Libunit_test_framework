/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_isascii_launchers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:49:54 by enkwak            #+#    #+#             */
/*   Updated: 2025/05/25 17:15:42 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "isascii_tests.h"

int	isascii_launcher(void)
{
	t_unit_test	*test_list;

	test_list = NULL;
	load_test(&test_list, "Number test", &isascii_number_test);
	load_test(&test_list, "No number test", &isascii_char_test);
	load_test(&test_list, "other test", &isascii_other_test);
	return (launch_tests(&test_list, "ISASCII"));
}
