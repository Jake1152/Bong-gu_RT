/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 23:29:21 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/06 05:21:20 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stddef.h>
#include "phong.h"
#include "vector.h"
#include "light.h"
#include "shadow.h"
#include "paint.h"

t_vec	get_normal(t_node *node, t_vec p)
{
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cylinder;
	t_vec		tmp;

	if (node == NULL)
		return ((t_vec){0, 0, 0, 0});
	if (node->type == TYPE_SPHERE)
	{
		sphere = node->content;
		return (vnorm(vsub(p, sphere->pos)));
	}
	else if (node->type == TYPE_PLANE)
	{
		plane = node->content;
		return (vnorm(plane->ori));
	}
	else if (node->type == TYPE_CYLINDER)
	{
		cylinder = node->content;
		tmp = vnorm(vcross(vnorm(cylinder->ori), \
			vnorm(vsub(p, cylinder->pos))));
		return (vnorm(vcross(tmp, cylinder->ori)));
	}
	return ((t_vec){0, 0, 0, 0});
}

t_color	phong(t_list *lights_cpy, t_vec norm, t_vec p)
{
	t_color			ret;
	t_node			*node;
	t_light_spot	*light;
	t_vec			vlight;

	ret = (t_color){0, 0, 0, 0};
	node = lights_cpy->head.next;
	while (node != &lights_cpy->tail)
	{
		vlight = vec_to_light(p, node);
		if (node->type == TYPE_LIGHT_SPOT)
		{
			light = node->content;
			ret = cadd(ret, cmul(light->col, fmaxf(vdot(norm, vlight), 0.0) \
				* light->bri));
		}
		node = node->next;
	}
	return (ret);
}
