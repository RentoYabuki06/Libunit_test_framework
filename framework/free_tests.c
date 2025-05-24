/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 17:33:56 by ryabuki           #+#    #+#             */
/*   Updated: 2025/05/24 17:41:48 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

void	free_tests(t_unit_test **list)
{
	t_unit_test	*tmp;

	if (!list || !*list)
		return;
	while (*list)
	{
		tmp = *list;
		*list = (*list)->next;
		free(tmp->name);
		free(tmp);
	}
}
