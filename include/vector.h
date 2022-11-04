/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:03:24 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/04 14:17:53 by jim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef unsigned char t_rgb_color;

typedef struct s_vec
{
	float	x;
	float	y;
	float	z;
	float	w;
}	t_vec;

# define ZEROVEC (t_vec){0, 0, 0, 0}

typedef struct s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	t;
}	t_color;

typedef unsigned char t_rgb_color;

t_vec	vadd(t_vec v1, t_vec v2);
t_vec	vsub(t_vec v1, t_vec v2);
float	vdot(t_vec v1, t_vec v2);
t_vec	vcross(t_vec v1, t_vec v2);
t_vec	vnorm(t_vec v);

#endif
