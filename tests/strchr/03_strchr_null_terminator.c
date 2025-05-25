/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_strchr_null_terminator.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoch <enoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 20:00:00 by yabukirento       #+#    #+#             */
/*   Updated: 2025/05/25 11:40:18 by enoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "libft.h"

int	strchr_segv_test_te(void)
{
	char *str = NULL;
	char *ptr = ft_strchr(str, 'a');

	(void)ptr;
	return (0);
}
