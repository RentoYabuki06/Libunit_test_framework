/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 18:28:54 by yabukirento       #+#    #+#             */
/*   Updated: 2025/05/24 16:15:03 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libunit_bonus.h"
#include "signals_tests/signals_tests_bonus.h"
#include "../../tests/test_launchers.h"

int	main(void)
{
    int	result;

    result = 0;
    ft_printf("%s==== LIBUNIT BONUS TESTS ====%s\n\n", BOLD_CYAN, RESET);
    
    // 標準テスト
    result |= strlen_launcher();
    result |= strchr_launcher();
    result |= atoi_launcher();
    
    // シグナルテスト（Bonusのみ）
    result |= signals_launcher();
    
    // // 実際のテスト
    // if (ft_strlen_launcher != NULL)
    //     result |= ft_strlen_launcher();
    
    if (result == 0)
        ft_printf("\n%sAll tests passed!%s\n", COLOR_OK, RESET);
    else
        ft_printf("\n%sSome tests failed!%s\n", COLOR_KO, RESET);
        
    return (result);
}

