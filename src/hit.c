/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 21:52:43 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/06 05:17:48 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <float.h>
#include "object.h"
#include "hit.h"

int	hit_sphere(t_sphere *sphere, t_vec v, float *t)
{
	float	a;
	float	b;
	float	c;
	t_vec	tmp;
	float	d;

	a = vdot(v, v);
	b = vdot(vmul(v, 2), vsub(ZEROPOS, sphere->pos));
	tmp = vsub(ZEROPOS, sphere->pos);
	c = vdot(tmp, tmp) - sphere->dia * sphere->dia;
	d = b * b - 4 * a * c;
	if (d < 0)
		return (0);
	d = sqrt(d);
	c = (-b - d) / (2.0 * a);
	if (c < FLT_EPSILON || *t < c)
	{
		c = (-b + d) / (2.0 * a);
		if (c < FLT_EPSILON || *t < c)
			return (0);
	}
	*t = c;
	return (1);
}

int	hit_plane(t_plane *plane, t_vec v, float *t)
{
	float	a;
	float	b;

	a = vdot(v, plane->ori);
	b = vdot(vsub(ZEROPOS, plane->pos), plane->ori);
	if (a == 0)
		return (0);
	b = -b / a;
	if (b < FLT_EPSILON || *t < b)
		return (0);
	*t = b;
	return (1);
}

int	is_cylinder_in(float root, t_vec v, t_cylinder *cylinder)
{
	t_vec	tmp;
	float	height;

	tmp = vsub(vadd(vmul(v, root), ZEROPOS), cylinder->pos);
	height = vdot(tmp, cylinder->ori);
	if (height < 0 || height > cylinder->hei)
		return (0);
	else
		return (1);
}

int	hit_cylinder(t_cylinder *cylinder, t_vec v, float *t)
{
	float	a;
	float	b;
	float	c;
	float	d;
	t_vec	tmp;

	a = vdot(v, v) - vdot(v, cylinder->ori) * vdot(v, cylinder->ori);
	tmp = vsub(ZEROPOS, cylinder->pos);
	b = vdot(v, tmp)
		- vdot(v, cylinder->ori) * vdot(tmp, cylinder->ori);
	c = vdot(tmp, tmp) - vdot(tmp, cylinder->ori) * vdot(tmp, cylinder->ori)
		- cylinder->dia * cylinder->dia;
	d = b * b - a * c;
	if (d < 0)
		return (0);
	d = sqrt(d);
	c = (-b - d) / a;
	if (!is_cylinder_in(c, v, cylinder) || (c < FLT_EPSILON || *t < c))
	{
		c = (-b + d) / a;
		if (!is_cylinder_in(c, v, cylinder) || (c < FLT_EPSILON || *t < c))
			return (0);
	}
	*t = c;
	return (1);
}

int	hit(t_node *node, t_vec v, float *t)
{
	if (node->type == TYPE_SPHERE)
		return (hit_sphere((t_sphere *)node->content, v, t));
	else if (node->type == TYPE_PLANE)
		return (hit_plane((t_plane *)node->content, v, t));
	else if (node->type == TYPE_CYLINDER)
		return (hit_cylinder((t_cylinder *)node->content, v, t));
	else
		return (0);
}
