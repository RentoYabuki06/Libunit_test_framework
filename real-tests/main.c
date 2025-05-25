/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 18:28:54 by yabukirento       #+#    #+#             */
/*   Updated: 2025/05/25 16:55:50 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "test_launchers.h"

int	main(void)
{
	int	result;

	result = 0;
	ft_printf("==== REAL TESTS ====\n\n");
	result |= strlen_launcher();
	result |= strchr_launcher();
	result |= atoi_launcher();
	result |= isalnum_launcher();
	result |= isalpha_launcher();
	result |= isascii_launcher();
	result |= isdigit_launcher();
	result |= isprint_launcher();
	if (result == 0)
		ft_printf("\nAll tests passed!\n");
	else
		ft_printf("\nSome tests failed!\n");
	return (result);
}
