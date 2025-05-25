/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_atoi_negative.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 20:00:00 by yabukirento       #+#    #+#             */
/*   Updated: 2025/05/25 16:50:38 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "libft.h"

int	atoi_negative_test_te(void)
{
	if (ft_atoi("-42") == -42)
		return (0);
	else
		return (-1);
}
