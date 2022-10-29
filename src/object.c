/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 19:21:14 by min-jo            #+#    #+#             */
/*   Updated: 2022/10/29 19:43:38 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "object.h"

void	initList(t_list *list)
{
	list->size = 0;
	list->head.next = &list->tail;
	list->head.pre = NULL;
	list->head.content = NULL;
	list->tail.next = NULL;
	list->tail.pre = &list->head;
	list->tail.content = NULL;
}

int	appendNode(t_list *list, void *content)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		return (-1);
	list->head.next = node;
	list->tail.pre = node;
	node->pre = &list->head;
	node->next = &list->tail;
	return (1);
}

void	clearList(t_list *list)
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
