/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 18:28:54 by yabukirento       #+#    #+#             */
/*   Updated: 2025/05/24 16:09:10 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "../tests/test_launchers.h"
#include "../real-tests/real_test_launchers.h"

int	main(void)
{
    int	result;

    result = 0;
    ft_printf("==== LIBUNIT TESTS ====\n\n");
    result |= strlen_launcher();
    result |= strchr_launcher();
    result |= atoi_launcher();
    
    if (result == 0)
        ft_printf("\nAll tests passed!\n");
    else
        ft_printf("\nSome tests failed!\n");
        
    return (result);
}

