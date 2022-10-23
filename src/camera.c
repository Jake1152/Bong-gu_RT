/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:41:11 by min-jo            #+#    #+#             */
/*   Updated: 2022/10/23 20:22:22 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _USE_MATH_DEFINES
#include <math.h>
#include "vector.h"
#include "camera.h"
#include "mattrix.h"

/*
* z: near는 1로 고정해서 아무 것도 안 곱함
*/
t_frustum	newFrustumPerspect(int width, float fov, float aspect)
{
	t_vec	bottom_left;

	bottom_left = (t_vec){
		x: -(float)width / 2.0,
		y: -(float)width * aspect / 2.0,
		z: tan(fov / 2 * M_PI / 180.0),
		w: 0,
	};
	return ((t_frustum){
		width: width,
		fov: fov,
		aspect: aspect,
		bottom_left: bottom_left,
	});
}

/*
* camera struct는 orient를 x, y, z vector 3개를 가지고 있어
* 카메라가 어느 방향으로 기울었는지도 표현 가능하지만 (6DOF)
* 파싱 단계에서 .rt로 들어오는 정보는 카메라가 바라보는 시점 vector만 있고
* camera tilt를 표현하는 값이 없어서 계산해줘야 함 (5DOF)
*/
t_camera	newCamera(t_vec position, t_vec orient)
{
	return (lookAt(position, vadd(position, orient), (t_vec){0, 1, 0}));
}

/*
* camera가 특정 시점을 바라볼 때, 카메라의 6DOF를 구함
* y: 이미 단위 길이이고 서로 수직인 z, x를 외적하므로 결과 벡터는 길이가 1인 단위 벡터여서, normalize 필요 없음
*/
t_camera	lookAt(t_vec eye, t_vec center, t_vec up)
{
	t_vec	x;
	t_vec	y;
	t_vec	z;

	z = vnorm(vsub(eye, center));
	x = vnorm(vcross(z, up));
	y = vcross(z, x);
	return ((t_camera){
		position: eye,
		orient_x: x,
		orient_y: y,
		orient_z: z,
	});
}
