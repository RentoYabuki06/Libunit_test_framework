/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 18:28:54 by yabukirento       #+#    #+#             */
/*   Updated: 2025/05/25 15:13:52 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "test_launchers.h"

int	main(void)
{
	int	result;

	result = 0;
	ft_printf("==== LIBUNIT TESTS ====\n\n");
	result |= strlen_launcher_te();
	result |= strchr_launcher_te();
	result |= atoi_launcher_te();
	if (result == 0)
		ft_printf("\nAll tests passed!\n");
	else
		ft_printf("\nSome tests failed!\n");
	return (result);
}
