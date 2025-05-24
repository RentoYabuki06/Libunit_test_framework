/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_sleep_timeout_test_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 22:16:00 by yabukirento       #+#    #+#             */
/*   Updated: 2025/05/24 17:28:04 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit_bonus.h"
#include <unistd.h>

int	sleep_timeout_test(void)
{
	sleep(TIMEOUT_SECONDS * 2);
	return (0);
}
