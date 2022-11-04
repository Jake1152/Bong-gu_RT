/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 19:21:14 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/05 06:21:38 by min-jo           ###   ########.fr       */
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

int	append_node(t_list *list, void *content, t_object_type type)
{
	t_node	*node;
	t_node	*last;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		return (-1);
	last = list->tail.pre;
	node->pre = last;
	node->next = &list->tail;
	last->next = node;
	list->tail.pre = node;
	node->content = content;
	node->type = type;
	++list->size;
	return (0);
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
	init_list(list);
}

void	*copy_content(t_object_type type, void *content)
{
	if (type == TYPE_LIGHT_SPOT)
		return (content_light_spot(content));
	else if (type == TYPE_SPHERE)
		return (content_sphere(content));
	else if (type == TYPE_PLANE)
		return (content_plane(content));
	else if (type == TYPE_CYLINDER)
		return (content_cylinder(content));
	else
		return (NULL);
}

int	copy_list(t_list *dst, t_list *src)
{
	t_node	*node;
	void	*content;

	clear_list(dst);
	node = src->head.next;
	while (node != &src->tail)
	{
		content = copy_content(node->type, node->content);
		if (content == NULL)
		{
			clear_list(dst);
			return (-1);
		}
		append_node(dst, content, node->type);
		node = node->next;
	}
	return (0);
}
