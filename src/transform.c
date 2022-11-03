/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 01:10:29 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/04 01:53:31 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "mlx_init.h"
#include "object.h"

/*
* return 값에 아무 의미 없음
*/
int	transform_pos(void	*content, t_object_type type, t_mat view)
{
	t_light_spot	*light;
	t_sphere		*sphere;

	if (type == TYPE_LIGHT_SPOT)
	{
		light = content;
		light->pos = mmulvec(view, light->pos);
	}
	else if (type == TYPE_SPHERE)
	{
		sphere = content;
		sphere->pos = mmulvec(view, sphere->pos);
	}
	return (0);
}

/*
* return 값에 아무 의미 없음
*/
int	transform_pos_ori(void	*content, t_object_type type, t_mat view)
{
	t_plane			*plane;
	t_cylinder		*cylinder;

	if (type == TYPE_PLANE)
	{
		plane = content;
		plane->pos = mmulvec(view, plane->pos);
		plane->ori = mmulvec(view, plane->ori);
	}
	else if (type == TYPE_CYLINDER)
	{
		cylinder = content;
		cylinder->pos = mmulvec(view, cylinder->pos);
		cylinder->ori = mmulvec(view, cylinder->ori);
	}
	return (0);
}

/*
* return 값에 아무 의미 없음
*/
int	transform_list(t_list *list, t_mat view)
{
	t_node			*node;

	node = list->head.next;
	while (node != &list->tail)
	{
		if (node->type == TYPE_LIGHT_SPOT)
			return (transform_pos(node->content, node->type, view));
		else if (node->type == TYPE_SPHERE)
			return (transform_pos(node->content, node->type, view));
		else if (node->type == TYPE_PLANE)
			return (transform_pos_ori(node->content, node->type, view));
		else if (node->type == TYPE_CYLINDER)
			return (transform_pos_ori(node->content, node->type, view));
		node = node->next;
	}
	return (0);
}

void	copy_transform(t_mlx *mlx)
{
	if (copy_list(&mlx->lights_cpy, &mlx->lights)
		&& copy_list(&mlx->objects_cpy, &mlx->objects))
	{
		clear_list(&mlx->lights);
		clear_list(&mlx->objects);
		clear_list(&mlx->lights_cpy);
		clear_list(&mlx->objects_cpy);
		perror_exit("Error: while malloc lights list copy");
	}
	transform_list(&mlx->lights_cpy, mlx->camera);
	transform_list(&mlx->objects_cpy, mlx->camera);
}
