/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 16:23:57 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/06 01:40:26 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "vector.h"

float	vlen(t_vec v)
{
	return (sqrtf(v.x * v.x + v.y * v.y + v.z * v.z));
}

t_vec	vmul(t_vec v, float c)
{
	return ((t_vec){
		.x = v.x * c,
		.y = v.y * c,
		.z = v.z * c,
		.w = v.w * c,
	});
}

t_color	cadd(t_color c1, t_color c2)
{
	return ((t_color){
		.r = c1.r + c2.r,
		.g = c1.g + c2.g,
		.b = c1.b + c2.b,
		.t = 0,
	});
}

t_color	cmul(t_color c, float t)
{
	return ((t_color){
		.r = c.r * t,
		.g = c.g * t,
		.b = c.b * t,
		.t = 0,
	});
}

t_color	cdot(t_color object, t_color light)
{
	return ((t_color){
		.r = (float)light.r * object.r / 255,
		.g = (float)light.g * object.g / 255,
		.b = (float)light.b * object.b / 255,
		.t = 0,
	});
}
