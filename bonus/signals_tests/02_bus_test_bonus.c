/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_bus_test_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 16:01:25 by yabukirento       #+#    #+#             */
/*   Updated: 2025/05/24 16:01:26 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit_bonus.h"
#include <string.h>
#include <unistd.h>

int bus_test(void)
{
    char buffer[sizeof(int)];
    int *ptr;
    
    ptr = (int *)(buffer + 1);
    *ptr = 42;
    
    return (0);
}