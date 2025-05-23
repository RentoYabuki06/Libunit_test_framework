/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_sleep_timeout_test.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 22:16:00 by yabukirento       #+#    #+#             */
/*   Updated: 2025/05/23 20:45:12 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include <unistd.h> // sleep関数のため

int sleep_timeout_test(void)
{
    // TIMEOUTよりも長い時間スリープする
    sleep(TIMEOUT_SECONDS * 2); // 20秒スリープ
    return (0);
}