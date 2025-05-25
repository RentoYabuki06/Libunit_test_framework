/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_strchr_basic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoch <enoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 20:00:00 by yabukirento       #+#    #+#             */
/*   Updated: 2025/05/25 11:49:30 by enoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "libft.h"

int	strchr_basic_test_te(void)
{
    char	*str;
    char	*result;

    str = "Hello, World!";
    result = ft_strchr(str, 'W');
    if (result == str + 7)
        return (0);
    else
        return (-1);
}