/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 23:23:02 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/05 16:38:00 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shadow.h"
#include "mlx_init.h"
#include "vector.h"
#include "object.h"
#include "hit.h"

t_vec	vec_to_light(t_vec p, t_node *node)
{
	t_vec			pos;
	t_light_spot	*light_spot;

	if (node->type == TYPE_LIGHT_SPOT)
	{
		light_spot = node->content;
		pos = light_spot->pos;
	}
	else
		pos = p;
	return (vnorm(vsub(pos, p)));
}

int	is_hit_anything(t_list *objects, t_vec vlight)
{
	t_node	*node;

	node = objects->head.next;
	while (node != &objects->tail)
	{
		if (hit(node, vlight) != -1)
			return (1);
		node = node->next;
	}
	return (0);
}

int check_shadow(t_mlx *mlx, t_vec p)
{
	t_node			*node;

	node = mlx->lights.head.next;
	while (node != &mlx->lights.tail)
	{
		if (is_hit_anything(&mlx->objects, vec_to_light(p, node)))
			return (1);
		node = node->next;
	}
	return (0);
}
