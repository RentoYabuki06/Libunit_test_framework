/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_atoi_segv_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 10:59:35 by enoch             #+#    #+#             */
/*   Updated: 2025/05/25 16:50:00 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "libft.h"

int	atoi_segv_test_te(void)
{
	char	*str;
	int		res;

	str = NULL;
	res = ft_atoi(str);
	(void)res;
	return (0);
}
