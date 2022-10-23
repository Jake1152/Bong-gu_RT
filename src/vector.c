/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 16:23:57 by min-jo            #+#    #+#             */
/*   Updated: 2022/10/23 19:28:10 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h> // TODO 3fast agorithm
#include "vector.h"

t_vec	vadd(t_vec v1, t_vec v2)
{
	return (t_vec){
		v1.x + v2.x,
		v1.y + v2.y,
		v1.z + v2.z,
		v1.w + v2.w,
	};
}

t_vec	vsub(t_vec v1, t_vec v2)
{
	return (t_vec){
		v1.x - v2.x,
		v1.y - v2.y,
		v1.z - v2.z,
		v1.w - v2.w,
	};
}

/*
* 내적증명
* https://playground10.tistory.com/74
*/
float	vdot(t_vec v1, t_vec v2)
{
	return (
		v1.x * v2.x +
		v1.y * v2.y +
		v1.z * v2.z +
		v1.w * v2.w
	);
}

/*
* 외적증명
* https://assortrock.com/24
*/
t_vec	vcross(t_vec v1, t_vec v2)
{
	return (t_vec){
		v1.y * v2.z - v1.z * v2.y,
		v1.z * v2.x - v1.x * v2.z,
		v1.x * v2.y - v1.y * v2.x,
		1,
	};
}

/*
* 3fast inverse sqare root
* https://www.youtube.com/watch?v=p8u_k2LIZyo
* intuitive explanation
* https://www.youtube.com/watch?v=NCuf2tjUsAY
*/
t_vec	vnorm(t_vec v)
{
	// TODO 3fast agorithm
	float	length;

	length = sqrtf(v.x*v.x + v.y*v.y + v.z*v.z);
	return (t_vec){
		v.x / length,
		v.y / length,
		v.z / length,
	};
}
