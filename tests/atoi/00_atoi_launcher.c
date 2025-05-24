/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_atoi_launcher.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 20:00:00 by yabukirento       #+#    #+#             */
/*   Updated: 2025/05/24 18:03:11 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "atoi_tests.h"

int	atoi_launcher(void)
{
    t_unit_test	*test_list;
    int			result;

    test_list = NULL;
    ft_printf("ATOI:\n");
    load_test(&test_list, "Positive number test", &atoi_positive_test);
    load_test(&test_list, "Negative number test", &atoi_negative_test);
    load_test(&test_list, "Zero test", &atoi_zero_test);
    load_test(&test_list, "Space test", &atoi_space_test);
    load_test(&test_list, "Plus sign test", &atoi_plus_sign_test);
    result = launch_tests(&test_list);
    free_tests(&test_list);
    return (result);
}