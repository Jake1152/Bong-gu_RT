/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 21:52:43 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/05 14:52:49 by jim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "object.h"
#include "hit.h"

float	hit_sphere(t_sphere *sphere, t_vec v)
{
	float	a;
	float	b;
	float	c;
	t_vec	tmp;
	float	d;

	a = vdot(v, v);
	b = vdot(vmul(v ,2), vsub(ZEROPOS, sphere->pos));
	tmp = vsub(ZEROPOS, sphere->pos);
	c = vdot(tmp, tmp) - sphere->dia * sphere->dia;
	d = b * b - 4 * a * c;
	if (d < 0)
		return (-1);
	d = (-b - sqrt(d)) / (2.0 * a);
	if (d < 0)
		return (-1);
	return (d);
}

float	hit_plane(t_plane *plane, t_vec v)
{
	float	a;
	float	b;

	a = vdot(v, plane->ori);
	b = vdot(vsub(ZEROPOS, plane->pos), plane->ori);
	if (a == 0)
		return (-1);
	b = -b / a;
	if (b < 0)
		return (-1);
	return (b);
}

float	hit_cylinder(t_cylinder *cylinder, t_vec v)
{
	float	a;
	float	b;
	float	c;
	t_vec	tmp;
	float	d;

	a = vdot(v, cylinder->ori);
	a = vdot(v, v) - a * a;
	tmp = vsub(ZEROPOS, cylinder->pos);
	b = vdot(v, tmp)
		- vdot(v, cylinder->ori) * vdot(tmp, cylinder->ori);
	c = vdot(tmp, tmp) - vdot(tmp, cylinder->ori)
		- cylinder->dia * cylinder->dia;
	d = b * b - a * c;
	if (d < 0)
		return (-1);
	d = (-b - sqrt(d)) / a;
	tmp = vsub(vadd(vmul(v, d), ZEROPOS), cylinder->pos);
	c = vdot(tmp, cylinder->ori);
	if (0 < c && c < cylinder->hei && d > 0)
		return (d);
	else
		return (-1);
}

float	hit(t_node *node, t_vec v)
{
	if (node->type == TYPE_SPHERE)
		return (hit_sphere((t_sphere *)node->content, v));
	else if (node->type == TYPE_PLANE)
		return (hit_plane((t_plane *)node->content, v));
	else if (node->type == TYPE_CYLINDER)
		return (hit_cylinder((t_cylinder *)node->content, v));
	else
		return (-1);
}
