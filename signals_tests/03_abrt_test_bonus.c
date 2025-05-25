/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_abrt_test_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 16:01:28 by yabukirento       #+#    #+#             */
/*   Updated: 2025/05/24 17:26:54 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit_bonus.h"
#include <stdlib.h>
#include <assert.h>

int	abrt_test(void)
{
	abort();
	return (0);
}
