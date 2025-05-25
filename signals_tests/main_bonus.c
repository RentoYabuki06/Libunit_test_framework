/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:45:10 by ryabuki           #+#    #+#             */
/*   Updated: 2025/05/25 16:44:56 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit_bonus.h"
#include "signals_tests_bonus.h"

int	main(void)
{
	int	result;

	result = 0;
	ft_printf("==== SIGNAL HANDLING BONUS TESTS ====\n\n");
	result |= signals_launcher();
	if (result == 0)
		ft_printf("\nAll signal tests passed!\n");
	else
		ft_printf("\nSome signal tests failed!\n");
	return (result);
}
