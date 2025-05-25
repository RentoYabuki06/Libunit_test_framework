/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_strlen_launcher.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoch <enoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 20:00:00 by yabukirento       #+#    #+#             */
/*   Updated: 2025/05/25 11:42:29 by enoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "strlen_tests.h"

int	strlen_launcher(void)
{
    t_unit_test	*test_list;

    test_list = NULL;
    ft_printf("STRLEN:\n");
    load_test(&test_list, "Basic test", &strlen_basic_test);
    load_test(&test_list, "Empty string test", &strlen_null_test);
    return (launch_tests(&test_list));
}