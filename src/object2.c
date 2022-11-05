/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 19:21:14 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/06 05:38:32 by jim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "object.h"

void	*content_light_spot(void *content)
{
	t_light_spot	*origin;
	t_light_spot	*ret;

	ret = malloc(sizeof(t_light_spot));
	if (ret == NULL)
		return (NULL);
	origin = content;
	ret->pos = (t_vec){
		origin->pos.x,
		origin->pos.y,
		origin->pos.z,
		origin->pos.w,
	};
	ret->bri = origin->bri;
	ret->col = (t_color){
		origin->col.r,
		origin->col.g,
		origin->col.b,
		origin->col.t,
	};
	return (ret);
}

void	*content_sphere(void *content)
{
	t_sphere	*origin;
	t_sphere	*ret;

	ret = malloc(sizeof(t_sphere));
	if (ret == NULL)
		return (NULL);
	origin = content;
	ret->pos = (t_vec){
		origin->pos.x,
		origin->pos.y,
		origin->pos.z,
		origin->pos.w,
	};
	ret->dia = origin->dia;
	ret->col = (t_color){
		origin->col.r,
		origin->col.g,
		origin->col.b,
		origin->col.t,
	};
	return (ret);
}

void	*content_plane(void *content)
{
	t_plane	*origin;
	t_plane	*ret;

	ret = malloc(sizeof(t_plane));
	if (ret == NULL)
		return (NULL);
	origin = content;
	ret->pos = (t_vec){
		origin->pos.x, origin->pos.y, origin->pos.z, origin->pos.w,
	};
	ret->ori = (t_vec){
		origin->ori.x, origin->ori.y, origin->ori.z, origin->ori.w,
	};
	ret->col = (t_color){
		origin->col.r, origin->col.g, origin->col.b, origin->col.t,
	};
	return (ret);
}

void	*content_cylinder(void *content)
{
	t_cylinder	*origin;
	t_cylinder	*ret;

	ret = malloc(sizeof(t_cylinder));
	if (ret == NULL)
		return (NULL);
	origin = content;
	ret->pos = (t_vec){
		origin->pos.x, origin->pos.y,
		origin->pos.z, origin->pos.w,
	};
	ret->ori = (t_vec){
		origin->ori.x, origin->ori.y,
		origin->ori.z, origin->ori.w,
	};
	ret->dia = origin->dia;
	ret->hei = origin->hei;
	ret->col = (t_color){
		origin->col.r, origin->col.g,
		origin->col.b, origin->col.t,
	};
	return (ret);
}
