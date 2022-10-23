/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:39:48 by min-jo            #+#    #+#             */
/*   Updated: 2022/10/23 22:03:21 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "vector.h"

/*
* aspect: width / height
*/
typedef struct s_frustum
{
	int		width;
	float	fov;
	float	aspect;
	t_vec	bottom_left;
}	t_frustum;

typedef struct s_camera
{
	t_vec		position;
	t_vec		orient_x;
	t_vec		orient_y;
	t_vec		orient_z;
}	t_camera;

//# TODO frustum이 mat 리턴하게 해야 함
t_frustum	newFrustumPerspect(int width, float fov, float aspect);
t_camera	newCamera(t_vec position, t_vec orient);
t_camera	cameraLookAt(t_vec position, t_vec look, t_vec up);

#endif
