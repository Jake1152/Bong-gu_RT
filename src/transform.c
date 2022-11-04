/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 01:10:29 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/05 08:08:40 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "mlx_init.h"
#include "object.h"

void	transform_pos(void	*content, t_object_type type, t_mat view)
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
}

void	transform_pos_ori(void	*content, t_object_type type, t_mat view)
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
}

void	transform_list(t_list *list, t_mat view)
{
	t_node	*node;

	node = list->head.next;
	while (node != &list->tail)
	{
		if (node->type == TYPE_LIGHT_SPOT)
			transform_pos(node->content, node->type, view);
		else if (node->type == TYPE_SPHERE)
			transform_pos(node->content, node->type, view);
		else if (node->type == TYPE_PLANE)
			transform_pos_ori(node->content, node->type, view);
		else if (node->type == TYPE_CYLINDER)
			transform_pos_ori(node->content, node->type, view);
		node = node->next;
	}
}

void	copy_transform(t_mlx *mlx)
{
	if (copy_list(&mlx->lights_cpy, &mlx->lights)
		|| copy_list(&mlx->objects_cpy, &mlx->objects))
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
