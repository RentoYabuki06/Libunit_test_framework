/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_isalpha_launchers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:49:54 by enkwak            #+#    #+#             */
/*   Updated: 2025/05/25 17:15:35 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "isalpha_tests.h"

int	isalpha_launcher(void)
{
	t_unit_test	*test_list;

	test_list = NULL;
	load_test(&test_list, "Number test", &isalpha_number_test);
	load_test(&test_list, "No number test", &isalpha_char_test);
	load_test(&test_list, "other test", &isalpha_other_test);
	return (launch_tests(&test_list, "ISALPHA"));
}
