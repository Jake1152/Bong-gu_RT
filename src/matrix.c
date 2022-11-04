/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 19:36:54 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/05 01:30:14 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "matrix.h"
#include "vector.h"

/*
* M_PI 상수를 사용하기 위한 define
*/
#define _USE_MATH_DEFINES

t_mat	mtranspose(t_mat m)
{
	t_mat	ret;

	ret.vecs[0] = (t_vec){m.vecs[0].x, m.vecs[1].x, m.vecs[2].x, m.vecs[3].x};
	ret.vecs[1] = (t_vec){m.vecs[0].y, m.vecs[1].y, m.vecs[2].y, m.vecs[3].y};
	ret.vecs[2] = (t_vec){m.vecs[0].z, m.vecs[1].z, m.vecs[2].z, m.vecs[3].z};
	ret.vecs[3] = (t_vec){m.vecs[0].w, m.vecs[1].w, m.vecs[2].w, m.vecs[3].w};
	return (ret);
}

t_mat	mmul(t_mat m1, t_mat m2)
{
	t_mat	ret;
	t_mat	t;
	int		i;

	t = mtranspose(m2);
	i = -1;
	while (++i < 4)
	{
		ret.vecs[i] = (t_vec){
			.x = vdot(m1.vecs[i], t.vecs[0]),
			.y = vdot(m1.vecs[i], t.vecs[1]),
			.z = vdot(m1.vecs[i], t.vecs[2]),
			.w = vdot(m1.vecs[i], t.vecs[3]),
		};
	}
	return (ret);
}

t_vec	mmulvec(t_mat m, t_vec v)
{
	return ((t_vec){
		.x = vdot(m.vecs[0], v),
		.y = vdot(m.vecs[1], v),
		.z = vdot(m.vecs[2], v),
		.w = vdot(m.vecs[3], v),
	});
}

t_mat	mtranslate(t_vec v)
{
	t_mat	ret;

	ret.vecs[0] = (t_vec){1, 0, 0, v.x};
	ret.vecs[1] = (t_vec){0, 1, 0, v.y};
	ret.vecs[2] = (t_vec){0, 0, 1, v.z};
	ret.vecs[3] = (t_vec){0, 0, 0, 1};
	return (ret);
}

t_mat	mrotate(float angle, t_vec v)
{
	t_mat	ret;
	float	cos_ang;
	float	sin_ang;

	v = vnorm(v);
	cos_ang = cos(angle * M_PI / 180.0);
	sin_ang = sin(angle * M_PI / 180.0);
	ret.vecs[0] = (t_vec){
		cos_ang + v.x * v.x * (1 - cos_ang),
		v.x * v.y * (1 - cos_ang) - v.z * sin_ang,
		v.x * v.z * (1 - cos_ang) + v.y * sin_ang, 0};
	ret.vecs[1] = (t_vec){
		v.y * v.x * (1 - cos_ang) + v.z * sin_ang,
		cos_ang + v.y * v.y * (1 - cos_ang),
		v.y * v.z * (1 - cos_ang) - v.x * sin_ang, 0};
	ret.vecs[2] = (t_vec){
		v.z * v.x * (1 - cos_ang) - v.y * sin_ang,
		v.z * v.y * (1 - cos_ang) + v.x * sin_ang,
		cos_ang + v.z * v.z * (1 - cos_ang), 0};
	ret.vecs[3] = (t_vec){0, 0, 0, 1};
	return (ret);
}
