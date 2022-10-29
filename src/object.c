/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 19:21:14 by min-jo            #+#    #+#             */
/*   Updated: 2022/10/29 20:30:43 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "object.h"

void	init_list(t_list *list)
{
	list->size = 0;
	list->head.next = &list->tail;
	list->head.pre = NULL;
	list->head.content = NULL;
	list->tail.next = NULL;
	list->tail.pre = &list->head;
	list->tail.content = NULL;
}

int	append_node(t_list *list, void *content)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		return (-1);
	list->head.next = node;
	list->tail.pre = node;
	node->pre = &list->head;
	node->next = &list->tail;
	node->content = content;
	return (1);
}

void	clear_list(t_list *list)
{
	t_node	*node;
	t_node	*tmp;

	node = list->head.next;
	while (node != &list->tail)
	{
		tmp = node;
		node = node->next;
		free(tmp->content);
		free(tmp);
	}
}
