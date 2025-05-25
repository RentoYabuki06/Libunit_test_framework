/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isdigit.launchers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enkwak <enkwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:49:54 by enkwak            #+#    #+#             */
/*   Updated: 2025/05/24 20:02:00 by enkwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "isdigit_test.h"

int	isdigit_launcher(void)
{
    t_unit_test	*test_list;

    test_list = NULL;
    ft_printf("ISASCII:\n");
    load_test(&test_list, "Number test", &isdigit_number_test);
    load_test(&test_list, "No number test", &isdigit_char_test);
	load_test(&test_list, "other test", &isdigit_other_test);
    return (launch_tests(&test_list));
}
