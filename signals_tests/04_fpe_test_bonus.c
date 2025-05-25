/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_fpe_test_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 16:01:31 by yabukirento       #+#    #+#             */
/*   Updated: 2025/05/24 17:27:38 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit_bonus.h"
#include <signal.h>

int	fpe_test(void)
{
	int	result;
	int	zero;

	result = 0;
	zero = 0;
	result = 42 / zero;
	return (result);
}
