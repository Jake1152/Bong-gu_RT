/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:41:11 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/05 08:20:47 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "vector.h"
#include "camera.h"
#include "matrix.h"

/*
* M_PI 상수를 사용하기 위한 define
*/
#define _USE_MATH_DEFINES

/*
* near는 1로 고정해서 tan 결과에 아무 것도 안 곱함
* near는 1일고, far는 raytracing에서 고려사항이 아님
*/
t_frustum	newFrustumPerspect(float aspect, float fov)
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

/*
* camera가 특정 시점을 바라볼 때, 카메라의 6DOF를 구함
*
* camera struct는 orient를 x, y, z vector 3개를 가지고 있어
* 카메라가 어느 방향으로 기울었는지도 표현 가능하지만 (6DOF)
* 파싱 단계에서 .rt로 들어오는 정보는 카메라가 바라보는 시점 vector만 있고
* camera tilt를 표현하는 값이 없어서 계산해줘야 함 (5DOF)
*
* look 바라보는 시점의 point 임, vector 아님
* y: 이미 단위 길이이고 서로 수직인 z, x를 외적하므로 결과 벡터는 길이가 1인 단위 벡터여서,
* normalize 필요 없음
*
* Cxx Cxy Cxz 0 | 1 0 0 -dx
* Cyx Cyx Cyz 0 | 0 1 0 -dy
* Czx Czy Czz 0 | 0 0 1 -dz
*   0   0   0 1 | 0 0 0  1
*/
t_mat	cameraLookAt(t_vec position, t_vec look, t_vec up)
{
	t_mat	trans_inv;
	t_mat	rotae_inv;
	t_vec	x;
	t_vec	y;
	t_vec	z;

	z = vnorm(vsub(position, look));
	x = vnorm(vcross(z, up));
	y = vcross(z, x);
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

/*
* orient의 -를 붙이면 z를 구할 수 있지만
* 함수 재활용하기 위해 position에서 orient를 빼므로 미리 position을 더해줌
*/
t_mat	newCamera(t_vec position, t_vec orient)
{
	if (orient.x == 0 && orient.y == 0 && orient.z == 0)
		orient = vnorm((t_vec){1, 1, 1, 0});
	return (cameraLookAt(position, vadd(position, vnorm(orient)),
			(t_vec){0, 1, 0, 1}));
}
