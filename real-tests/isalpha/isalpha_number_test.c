/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalpha_number_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enkwak <enkwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:55:21 by enkwak            #+#    #+#             */
/*   Updated: 2025/05/24 20:02:21 by enkwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "libft.h"

int	isalpha_number_test(void)
{
	if (ft_isalpha('7') == 1)
		return (0);
	else
		return (-1);
}
