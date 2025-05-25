/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 18:28:54 by yabukirento       #+#    #+#             */
/*   Updated: 2025/05/25 15:34:44 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "test_launchers.h"

int	main(void)
{
    int	result;

    result = 0;
    ft_printf("==== REAL TESTS ====\n\n");
    
    // String functions
    result |= strlen_launcher();
    result |= strchr_launcher();
    
    // Conversion functions
    result |= atoi_launcher();
    
    // Character classification functions
    result |= isalnum_launcher();
    result |= isalpha_launcher();
    result |= isascii_launcher();
    result |= isdigit_launcher();
    result |= isprint_launcher();
    
    // Print summary
    if (result == 0)
        ft_printf("\nAll tests passed!\n");
    else
        ft_printf("\nSome tests failed!\n");
    
    return (result);
}
