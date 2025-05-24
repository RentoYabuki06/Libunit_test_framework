/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 18:28:54 by yabukirento       #+#    #+#             */
/*   Updated: 2025/05/24 17:29:48 by ryabuki          ###   ########.fr       */
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
	result |= strlen_launcher();
	result |= strchr_launcher();
	result |= atoi_launcher();
	result |= signals_launcher();
	if (result == 0)
		ft_printf("\n%sAll tests passed!%s\n", COLOR_OK, RESET);
	else
		ft_printf("\n%sSome tests failed!%s\n", COLOR_KO, RESET);
	return (result);
}
