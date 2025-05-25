/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_strchr_null_terminator.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 20:00:00 by yabukirento       #+#    #+#             */
/*   Updated: 2025/05/25 16:48:34 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "libft.h"

int	strchr_segv_test_te(void)
{
	char	*str;
	char	*ptr;

	str = NULL;
	ptr = ft_strchr(str, 'a');
	(void)ptr;
	return (0);
}
