/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_strlen_segv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 10:54:04 by enoch             #+#    #+#             */
/*   Updated: 2025/05/25 16:47:30 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "libft.h"

int	strlen_segv_test_te(void)
{
	char	*str;
	size_t	len;

	str = NULL;
	len = ft_strlen(str);
	(void)len;
	return (0);
}
