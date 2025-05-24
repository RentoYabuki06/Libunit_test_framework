/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalnum_other_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enkwak <enkwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 16:03:25 by enkwak            #+#    #+#             */
/*   Updated: 2025/05/24 16:04:30 by enkwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "libft.h"

int	isalnum_other_test(void)
{
	if (ft_isalnum('/') == 1)
		return (0);
	else
		return (-1);
}
