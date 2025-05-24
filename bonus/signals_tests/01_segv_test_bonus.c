/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_segv_test_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 16:01:22 by yabukirento       #+#    #+#             */
/*   Updated: 2025/05/24 16:01:23 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit_bonus.h"

int segv_test(void)
{
    char *ptr;
    
    ptr = NULL;
    *ptr = 'a';
    return (0);
}