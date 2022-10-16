/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vetctor.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:03:24 by min-jo            #+#    #+#             */
/*   Updated: 2022/10/16 19:21:15 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct	s_vector
{
	float	x;
	float	y;
	float	z;
	float	w;
}	t_vector;

typedef t_vector	t_point;

t_vector	new_vector(float x, float y, float z, float w);
t_point		new_point(float x, float y, float z, float w);

#endif
