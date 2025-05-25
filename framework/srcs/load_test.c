/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 18:28:47 by yabukirento       #+#    #+#             */
/*   Updated: 2025/05/25 17:28:33 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

static t_unit_test	*create_unit_test_node(char *name, int (*test_func)(void))
{
	t_unit_test	*new;

	new = (t_unit_test *)malloc(sizeof(t_unit_test));
	if (new == NULL)
	{
		ft_putstr_fd("Error: malloc failed!\n", STDERR_FILENO);
		return (NULL);
	}
	new->name = ft_strdup(name);
	if (new->name == NULL)
	{
		free(new);
		new = NULL;
		ft_putstr_fd("Error: strdup failed!\n", STDERR_FILENO);
		return (NULL);
	}
	new->test_func = test_func;
	new->next = NULL;
	return (new);
}

void	load_test(t_unit_test **list, char *name, int (*test_func)(void))
{
	t_unit_test	*new;
	t_unit_test	*tmp;

	if (list == NULL)
	{
		ft_putstr_fd("Error: test list is NULL!\n", STDERR_FILENO);
		return ;
	}
	if (test_func == NULL)
	{
		ft_putstr_fd("Error: test_func is NULL!\n", STDERR_FILENO);
		return ;
	}
	new = create_unit_test_node(name, test_func);
	if (new == NULL)
		return ;
	if (*list == NULL)
		*list = new;
	else
	{
		tmp = *list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}
