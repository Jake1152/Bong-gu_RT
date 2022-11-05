/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:39:48 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/06 05:12:46 by jim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "vector.h"
# include "matrix.h"

typedef struct viewport
{
	int		width;
	int		height;
	float	aspect;
}	t_viewport;

typedef struct s_frustum
{
	float	width;
	float	height;
	t_vec	bottom_left;
}	t_frustum;

t_frustum	newFrustumPerspect(float aspect, float fov);
t_mat		cameraLookAt(t_vec position, t_vec look, t_vec up, \
										int look_is_orient);
t_mat		newCamera(t_vec position, t_vec orient);

#endif
