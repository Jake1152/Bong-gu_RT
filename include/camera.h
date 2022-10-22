/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:39:48 by min-jo            #+#    #+#             */
/*   Updated: 2022/10/22 18:46:50 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "vector.h"

typedef struct s_camera
{
	t_point	position;
	t_vec	orient_x;
	t_vec	orient_y;
	t_vec	orient_z;
	int		fov;
	float	focal_length;
}	t_camera;

t_camera	newCamera(t_point position, t_vec orient, int fov);
t_camera	cameraLookAt(t_point position, t_point look, t_vec up, int fov);

#endif
