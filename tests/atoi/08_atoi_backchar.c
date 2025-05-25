/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_atoi_backchar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 11:12:01 by enoch             #+#    #+#             */
/*   Updated: 2025/05/25 16:49:19 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "libft.h"

int	atoi_minus_sign_test_te(void)
{
	if (ft_atoi("42abc") == 42)
		return (0);
	else
		return (-1);
}
