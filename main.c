/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 18:28:54 by yabukirento       #+#    #+#             */
/*   Updated: 2025/05/23 20:29:36 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "tests/test_launchers.h"

int	main(void)
{
    int	result;

    result = 0;
    ft_printf("%s==== LIBUNIT TESTS ====%s\n\n", BOLD_CYAN, RESET);
    result |= strlen_launcher();
    result |= strchr_launcher();
    result |= signals_launcher();
    
    if (result == 0)
        ft_printf("\n%sAll tests passed!%s\n", COLOR_OK, RESET);
    else
        ft_printf("\n%sSome tests failed!%s\n", COLOR_KO, RESET);
        
    return (result);
}

