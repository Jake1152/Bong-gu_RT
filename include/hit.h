/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 21:52:46 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/05 15:04:21 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIT_H
# define HIT_H

#include "vector.h"
#include "object.h"

float	hit_sphere(t_sphere *sphere, t_vec v);
float	hit_plane(t_plane *plane, t_vec v);
float	hit_cylinder(t_cylinder *cylinder, t_vec v);
float	hit(t_node *node, t_vec v);

#endif
