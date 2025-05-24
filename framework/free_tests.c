/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 17:33:56 by ryabuki           #+#    #+#             */
/*   Updated: 2025/05/24 17:36:02 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

void	free_tests(t_unit_test *list)
{
	t_unit_test	*tmp;

	if (!list || !*list)
		return;
	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp->name);
		free(tmp);
	}
}
