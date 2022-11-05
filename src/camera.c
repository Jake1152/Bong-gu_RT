/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:41:11 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/06 05:37:32 by jim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "vector.h"
#include "camera.h"
#include "matrix.h"
#define _USE_MATH_DEFINES

t_frustum	new_frustum_perspect(float aspect, float fov)
{
	t_frustum	ret;

	ret.height = tan(fov / 2 * M_PI / 180.0) * 2;
	ret.width = ret.height * aspect;
	ret.bottom_left = (t_vec){
		.x = -(float)ret.width / 2.0,
		.y = -(float)ret.height / 2.0,
		.z = -1,
		.w = 1,
	};
	return (ret);
}

t_mat	camera_look_at(t_vec position, t_vec look, t_vec up, int look_is_orient)
{
	t_mat	trans_inv;
	t_mat	rotae_inv;
	t_vec	x;
	t_vec	y;
	t_vec	z;

	if (look_is_orient)
		z = vsub((t_vec){0, 0, 0, 0}, vnorm(look));
	else
		z = vnorm(vsub(position, look));
	x = vnorm(vcross(z, up));
	y = vnorm(vcross(z, x));
	rotae_inv.vecs[0] = x;
	rotae_inv.vecs[1] = y;
	rotae_inv.vecs[2] = z;
	rotae_inv.vecs[3] = (t_vec){0, 0, 0, 1};
	trans_inv.vecs[0] = (t_vec){1, 0, 0, -position.x};
	trans_inv.vecs[1] = (t_vec){0, 1, 0, -position.y};
	trans_inv.vecs[2] = (t_vec){0, 0, 1, -position.z};
	trans_inv.vecs[3] = (t_vec){0, 0, 0, 1};
	return (mmul(rotae_inv, trans_inv));
}

t_mat	new_camera(t_vec position, t_vec orient)
{
	t_vec	up;
	t_vec	tmp;

	up = (t_vec){0, 1, 0, 0};
	if (orient.x == 0 && orient.y == 0 && orient.z == 0)
		orient = (t_vec){1, 1, 1, 0};
	tmp = vcross(orient, up);
	if (vdot(tmp, tmp) < 0.000001)
		up = vnorm((t_vec){1, 0, 0, 0});
	return (camera_look_at(position, orient, up, 1));
}
