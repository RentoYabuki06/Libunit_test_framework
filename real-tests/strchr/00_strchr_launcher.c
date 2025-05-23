/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_strchr_launcher.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoch <enoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 20:00:00 by yabukirento       #+#    #+#             */
/*   Updated: 2025/05/25 11:42:39 by enoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "strchr_tests.h"

int	strchr_launcher(void)
{
    t_unit_test	*test_list;

    test_list = NULL;
    ft_printf("STRCHR:\n");
    load_test(&test_list, "Basic test", &strchr_basic_test);
    load_test(&test_list, "Character not found test", &strchr_not_found_test);
    load_test(&test_list, "Null terminator test", &strchr_null_terminator_test);
    return (launch_tests(&test_list));
}