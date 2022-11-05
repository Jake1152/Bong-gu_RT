/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:39:48 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/06 05:37:31 by jim              ###   ########.fr       */
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

t_frustum	new_frustum_perspect(float aspect, float fov);
t_mat		camera_look_at(t_vec position, t_vec look, t_vec up, \
										int look_is_orient);
t_mat		new_camera(t_vec position, t_vec orient);

#endif
