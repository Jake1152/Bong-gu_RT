/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:57:09 by min-jo            #+#    #+#             */
/*   Updated: 2022/10/22 17:37:07 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "vector.h"
# include "light.h"

typedef struct s_sphere
{
	t_point	position;
	float	diameter;
	t_color	color;
}	t_sphere;

typedef struct s_plane
{
	t_point	position;
	t_vec	orient;
	t_color	color;
}	t_plane;

typedef struct s_cylinder
{
	t_point	position;
	t_vec	orient;
	float	diameter;
	float	height;
	t_color	color;
}	t_cylinder;

#endif
