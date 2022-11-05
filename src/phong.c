/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 23:29:21 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/05 16:47:21 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stddef.h>
#include "phong.h"
#include "vector.h"
#include "light.h"
#include "shadow.h"

t_vec	get_normal(t_node *node, t_vec p)
{
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cylinder;

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
		return (vnorm(vsub(p, plane->pos)));
	}
	else if (node->type == TYPE_CYLINDER)
	{
		cylinder = node->content;
		return (vnorm(vsub(p, cylinder->pos)));
	}
	else
		return ((t_vec){0, 0, 0, 0});
}

t_color	phong_specular(t_color color, t_vec norm, t_vec v)
{
	const float	ksn = 64;
	const float	ks = 0.5;
	t_vec		reflect;
	float		spec;

	reflect = vsub(v, vmul(norm, vdot(v, norm) * 2));
	spec = powf(fmaxf(vdot(v, reflect), 0.0), ksn);
	return (cmul(cmul(color, ks), spec));
}

t_color	phong(t_list *lights, t_vec norm, t_vec v, t_vec p)
{
	t_color			ret;
	t_node			*node;
	t_light_spot	*light;
	t_vec			vlight;

	ret = (t_color){0, 0, 0, 0};
	node = lights->head.next;
	while (node != &lights->tail)
	{
		vlight = vec_to_light(p, node);
		if (node->type == TYPE_LIGHT_SPOT)
		{
			light = node->content;
			ret = cadd(ret, cmul(light->col, fmaxf(vdot(norm, vlight), 0.0)));
			ret = cadd(ret, phong_specular(light->col, norm, v));
		}
		node = node->next;
	}
	return (ret);
}
