/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_strlen_wrong_value.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 10:54:20 by enoch             #+#    #+#             */
/*   Updated: 2025/05/25 15:22:57 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "libft.h"

int	strlen_wrong_value_test_te(void)
{
	if (ft_strlen("42Tokyo") == 100)
		return (0);
	else
		return (-1);
}
