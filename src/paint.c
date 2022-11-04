/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:10:22 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/05 07:32:32 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <math.h>
#include <float.h>
#include "mlx_init.h"
#include "vector.h"
#include "camera.h"
#include "object.h"
#include "hit.h"

t_color	get_color(t_node *node)
{
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cylinder;

	if (node == NULL)
		return ((t_color){0, 0, 0, 1});
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
		return ((t_color){0, 0, 0, 1});
}

/*
* 물체들 반복문을 돌면서 z값이 가장 카메라와 가까운 좌표를 얻음
* 그 위치에 그림자가 만들어지는지 확인하고
* 안 만들어지면 phong 적용
*/
t_color	ray_color(t_mlx *mlx, t_vec v)
{
	float	min;
	float	t;
	t_node	*node;
	t_node	*min_node;

	min_node = NULL;
	min = FLT_MAX;
	node = mlx->objects_cpy.head.next;
	while (node != &mlx->objects_cpy.tail)
	{
		t = hit(node, v);
		if (t > 0 && t < min)
		{
			min = t;
			min_node = node;
		}
		node = node->next;
	}
	return (get_color(min_node));
	// 그림자 먼저 되는지 확인 TODO
	// phong TODO 255 넘는지 0보다 작은지 체크
}

/*
* TODO x++ 로만 동작하게 효율적으로 바꿔야 함
*/
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
			tmp = (int *)(mlx->img.addr + y * mlx->img.len
					+ x * mlx->img.bpp / 8);
			v = vnorm((t_vec){
				(x - (double)mlx->viewport.width / 2) / mlx->viewport.width
					* mlx->frustum.width,
				(y - (double)mlx->viewport.height / 2) / mlx->viewport.height
					* mlx->frustum.height,
				-1,
				0,
			});
			color = ray_color(mlx, v);
			*tmp = *(int *)(char [4]){color.b, color.g, color.r, color.t};
		}
	}
}
