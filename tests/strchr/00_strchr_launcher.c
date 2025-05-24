/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_strchr_launcher.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 20:00:00 by yabukirento       #+#    #+#             */
/*   Updated: 2025/05/24 18:04:10 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "strchr_tests.h"

int	strchr_launcher(void)
{
    t_unit_test	*test_list;
    int			result;

    test_list = NULL;
    ft_printf("STRCHR:\n");
    load_test(&test_list, "Basic test", &strchr_basic_test);
    load_test(&test_list, "Character not found test", &strchr_not_found_test);
    load_test(&test_list, "Null terminator test", &strchr_null_terminator_test);
    result = launch_tests(&test_list);
    free_tests(&test_list);
    return (result);
}