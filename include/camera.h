/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:39:48 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/05 10:45:39 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "vector.h"
# include "matrix.h"

/*
* aspect: width / height
*/
typedef struct viewport
{
	int		width;
	int		height;
	float	aspect;
}	t_viewport;

/*
* right = bottom_left.x + width;
*/
typedef struct s_frustum
{
	float	width;
	float	height;
	t_vec	bottom_left;
}	t_frustum;

t_frustum	newFrustumPerspect(float aspect, float fov);

/*
* 카에라가 바라보는 방향의 역행렬을 구함
*
* 카메라가 월드 좌표계로 부터 틀어져 있는 모습
* V = TR
* 1 0 0 dx | Cxx Cyx Czx 0
* 0 1 0 dy | Cxy Cyy Czy 0
* 0 0 1 dz | Cxz Cyz Czz 0
* 0 0 0  1 |   0   0   0 1
*
* 카메라를 움직이는 게 아니라
* 대신 다른 모든 물체를 카메라 반대 방향으로 움직임
* V^(-1) = R^(-1) * T^(-1)
* Cxx Cxy Cxz 0 | 1 0 0 -dx
* Cyx Cyx Cyz 0 | 0 1 0 -dy
* Czx Czy Czz 0 | 0 0 1 -dz
*   0   0   0 1 | 0 0 0  1
*/
t_mat	cameraLookAt(t_vec position, t_vec look, t_vec up, int look_is_orient);
t_mat	newCamera(t_vec position, t_vec orient);

#endif
