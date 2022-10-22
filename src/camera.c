/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:41:11 by min-jo            #+#    #+#             */
/*   Updated: 2022/10/22 18:33:18 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "camera.h"

/*
* camera struct는 orient를 x, y, z vector 3개를 가지고 있어
* 카메라가 어느 방향으로 기울었는지도 표현 가능하지만 (6DOF)
* 파싱 단계에서 .rt로 들어오는 정보는 카메라가 바라보는 시점 vector만 있고
* camera tilt를 표현하는 값이 없어서 계산해줘야 함 (5DOF)
*/
t_camera	newCamera(t_point position, t_vec orient, int fov)
{
	return (lookAt(position, vadd(position, orient), (t_vec){0, 1, 0}, fov));
}

/*
* camera가 특정 시점을 바라볼 때, 카메라의 6DOF를 구함
* y: 이미 단위 길이이고 서로 수직인 z, x를 외적하므로 결과 벡터는 길이가 1인 단위 벡터여서, normalize 필요 없음
*/
t_camera	lookAt(t_point eye, t_point center, t_vec up, int fov)
{
	t_vec	x;
	t_vec	y;
	t_vec	z;

	z = vnorm(vminus(eye, center));
	x = vnorm(vcross(z, up));
	y = vcross(z, x);
	return ((t_camera){
		position: eye,
		orient_x: x,
		orient_y: y,
		orient_z: z,
		fov: fov,
		focal_length: 1.0,
	});
}
