/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:10:22 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/06 05:43:09 by jim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <math.h>
#include <float.h>
#include "mlx_init.h"
#include "vector.h"
#include "paint.h"
#include "camera.h"
#include "object.h"
#include "hit.h"
#include "shadow.h"
#include "phong.h"

t_color	get_color(t_node *node)
{
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cylinder;

	if (node == NULL)
		return ((t_color){0, 0, 0, 0});
	if (node->type == TYPE_SPHERE)
	{
		sphere = node->content;
		return (sphere->col);
	}
	else if (node->type == TYPE_PLANE)
	{
		plane = node->content;
		return (plane->col);
	}
	else if (node->type == TYPE_CYLINDER)
	{
		cylinder = node->content;
		return (cylinder->col);
	}
	else
		return ((t_color){0, 0, 0, 0});
}

t_node	*find_closest(t_mlx *mlx, t_vec v, t_vec *p)
{
	float	t;
	t_node	*node;
	t_node	*ret_node;

	t = FLT_MAX;
	ret_node = NULL;
	node = mlx->objects_cpy.head.next;
	while (node != &mlx->objects_cpy.tail)
	{
		if (hit(node, v, &t))
			ret_node = node;
		node = node->next;
	}
	*p = vadd(vmul(v, t), (t_vec){0, 0, 0, 1});
	return (ret_node);
}

t_color	ray_color(t_mlx *mlx, t_vec v)
{
	t_node	*min_node;
	t_color	ret;
	t_vec	p;

	min_node = find_closest(mlx, v, &p);
	if (min_node == NULL)
		return ((t_color){0, 0, 0, 0});
	else if (min_node != NULL && check_shadow(mlx, p))
		return ((t_color){0, 0, 0, 0});
	ret = (t_color){0, 0, 0, 0};
	if (min_node)
	{
		ret = cadd(ret, cmul(mlx->light_ambient.col, mlx->light_ambient.bri));
		ret = cadd(ret, phong(&mlx->lights_cpy, get_normal(min_node, p), p));
	}
	return (cdot(get_color(min_node), ret));
}

void	paint(t_mlx *mlx)
{
	int		x;
	int		y;
	int		*tmp;
	t_color	color;
	t_vec	v;

	y = -1;
	while (++y < mlx->viewport.height)
	{
		x = -1;
		while (++x < mlx->viewport.width)
		{
			tmp = (int *)(mlx->img.addr + y * mlx->img.len \
					+ x * mlx->img.bpp / 8);
			v = vnorm((t_vec){\
				(x - (double)mlx->viewport.width / 2) / mlx->viewport.width \
					* mlx->frustum.width, \
				(y - (double)mlx->viewport.height / 2) / mlx->viewport.height \
					* mlx->frustum.height, \
				-1, 0, \
			});
			color = ray_color(mlx, v);
			*tmp = *(int *)(char [4]){color.b, color.g, color.r, color.t};
		}
	}
}
