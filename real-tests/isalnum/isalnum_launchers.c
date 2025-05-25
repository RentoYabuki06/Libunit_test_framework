/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalnum_launchers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enkwak <enkwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:49:54 by enkwak            #+#    #+#             */
/*   Updated: 2025/05/24 19:33:31 by enkwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "isalnum_test.h"

int	isalnum_launcher(void)
{
    t_unit_test	*test_list;

    test_list = NULL;
    ft_printf("ISALNUM:\n");
    load_test(&test_list, "Number test", &isalnum_number_test);
    load_test(&test_list, "No number test", &isalnum_char_test);
	load_test(&test_list, "No number test", &isalnum_other_test);
    return (launch_tests(&test_list));
}