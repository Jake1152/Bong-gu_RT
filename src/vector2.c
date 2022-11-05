/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 16:23:57 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/05 16:34:49 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec	vmul(t_vec v, float c)
{
	return ((t_vec){
		.x = v.x * c,
		.y = v.y * c,
		.z = v.z * c,
		.w = v.w * c,
	});
}

t_vec	vmag(t_vec v, t_vec m)
{
	return ((t_vec){
		.x = v.x * m.x,
		.y = v.y * m.y,
		.z = v.z * m.z,
		.w = v.w * m.w,
	});
}

static unsigned char	min(unsigned char c1, unsigned char c2)
{
	if (c1 > c2)
		return (c2);
	else
		return (c1);
}

t_color	cadd(t_color c1, t_color c2)
{
	return ((t_color){
		.r = min(c1.r + c2.r, 255),
		.g = min(c1.g + c2.g, 255),
		.b = min(c1.b + c2.b, 255),
		.t = min(c1.t + c2.t, 255),
	});
}

t_color	cmul(t_color c, float t)
{
	return ((t_color){
		.r = c.r * t,
		.g = c.g * t,
		.b = c.b * t,
		.t = c.t * t,
	});
}
