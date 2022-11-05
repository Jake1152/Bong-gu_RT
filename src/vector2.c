/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 16:23:57 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/05 20:40:44 by min-jo           ###   ########.fr       */
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

t_vec	vmag(t_vec v, t_vec m)
{
	return ((t_vec){
		.x = v.x * m.x,
		.y = v.y * m.y,
		.z = v.z * m.z,
		.w = v.w * m.w,
	});
}

static unsigned char	sumovf(unsigned char c1, unsigned char c2)
{
	unsigned char	sum;

	sum = c1 + c2;
	if (sum < c1 || sum < c2)
		return (255);
	else
		return (sum);
}

t_color	cadd(t_color c1, t_color c2)
{
	return ((t_color){
		.r = sumovf(c1.r , c2.r),
		.g = sumovf(c1.g , c2.g),
		.b = sumovf(c1.b , c2.b),
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
