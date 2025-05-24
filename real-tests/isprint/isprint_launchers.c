/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isprint_launchers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enkwak <enkwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:49:54 by enkwak            #+#    #+#             */
/*   Updated: 2025/05/24 20:02:09 by enkwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "isprint_test.h"

int	isprint_launcher(void)
{
    t_unit_test	*test_list;

    test_list = NULL;
    ft_printf("ISASCII:\n");
    load_test(&test_list, "Number test", &isprint_number_test);
    load_test(&test_list, "No number test", &isprint_char_test);
	load_test(&test_list, "other test", &isprint_other_test);
    return (launch_tests(&test_list));
}
