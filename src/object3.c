/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 19:21:14 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/04 19:40:55 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx_init.h"
#include "parse.h"
#include "object.h"
#include "light.h"

int	add_list_lig_ret_space(void *ptr)
{
	t_light_spot	*light;
	t_mlx			*mlx;

	mlx = ptr;
	light = malloc(sizeof(t_light_spot));
	if (light == NULL)
		return (PARSE_RT_ERROR);
	if (append_node(&mlx->lights, light, TYPE_LIGHT_SPOT))
		return (PARSE_RT_ERROR);
	return (PARSE_RT_LIG_SPACE);
}

int	add_list_shp_ret_char(void *ptr)
{
	t_sphere	*sphere;
	t_mlx		*mlx;

	mlx = ptr;
	sphere = malloc(sizeof(t_sphere));
	if (sphere == NULL)
		return (PARSE_RT_ERROR);
	if (append_node(&mlx->objects, sphere, TYPE_SPHERE))
		return (PARSE_RT_ERROR);
	return (PARSE_RT_SPH_CHAR);
}

int	add_list_pla_ret_char(void *ptr)
{
	t_plane	*plane;
	t_mlx	*mlx;

	mlx = ptr;
	plane = malloc(sizeof(t_plane));
	if (plane == NULL)
		return (PARSE_RT_ERROR);
	if (append_node(&mlx->objects, plane, TYPE_PLANE))
		return (PARSE_RT_ERROR);
	return (PARSE_RT_PLA_CHAR);
}

int	add_list_cyl_ret_char(void *ptr)
{
	t_cylinder	*cylinder;
	t_mlx		*mlx;

	mlx = ptr;
	cylinder = malloc(sizeof(t_cylinder));
	if (cylinder == NULL)
		return (PARSE_RT_ERROR);
	if (append_node(&mlx->objects, cylinder, TYPE_CYLINDER))
		return (PARSE_RT_ERROR);
	return (PARSE_RT_CYL_CHAR);
}
