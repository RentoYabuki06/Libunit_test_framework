/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_fpe_test_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 16:01:31 by yabukirento       #+#    #+#             */
/*   Updated: 2025/05/24 16:01:32 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit_bonus.h"
#include <signal.h>

int fpe_test(void)
{
    int result = 0;
    int zero = 0;
    
    result = 42 / zero;  // ここでSIGFPEが発生
    return (result);
}