/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_abrt_test_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 16:01:28 by yabukirento       #+#    #+#             */
/*   Updated: 2025/05/24 16:01:29 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit_bonus.h"
#include <stdlib.h>
#include <assert.h>

int abrt_test(void)
{
    abort();  // SIGABRTを発生させる
    return (0);
}