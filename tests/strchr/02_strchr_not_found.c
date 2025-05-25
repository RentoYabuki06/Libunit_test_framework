/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_strchr_not_found.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoch <enoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 20:00:00 by yabukirento       #+#    #+#             */
/*   Updated: 2025/05/25 11:40:14 by enoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "libft.h"

int	strchr_not_found_test_te(void)
{
    char	*str;

    str = "Hello, World!";
    if (ft_strchr(str, 'Z') == NULL)
        return (0);
    else
        return (-1);
}