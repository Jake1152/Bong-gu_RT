/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 23:23:02 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/06 05:15:49 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <float.h>
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

int	is_hit_anything(t_list *objects_cpy, t_vec vlight_length)
{
	t_node	*node;
	float	t;
	float	len;

	t = FLT_MAX;
	len = vlen(vlight_length);
	node = objects_cpy->head.next;
	while (node != &objects_cpy->tail)
	{
		t = hit(node, vnorm(vlight_length), &t);
		if (0 < t && t < len)
			return (1);
		node = node->next;
	}
	return (0);
}

int	check_shadow(t_mlx *mlx, t_vec p)
{
	t_node			*node;

	node = mlx->lights_cpy.head.next;
	while (node != &mlx->lights_cpy.tail)
	{
		if (is_hit_anything(&mlx->objects_cpy, vec_to_light(p, node)))
			return (1);
		node = node->next;
	}
	return (0);
}
