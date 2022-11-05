/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:03:24 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/05 18:05:52 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vec
{
	float	x;
	float	y;
	float	z;
	float	w;
}	t_vec;

# define ZEROVEC (t_vec){0, 0, 0, 0}
# define ZEROPOS (t_vec){0, 0, 0, 1}

typedef struct s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	t;
}	t_color;

/*
* vector.c
*/
t_vec	vadd(t_vec v1, t_vec v2);
t_vec	vsub(t_vec v1, t_vec v2);
float	vdot(t_vec v1, t_vec v2);
t_vec	vcross(t_vec v1, t_vec v2);
t_vec	vnorm(t_vec v);

/*
* vector2.c
*/
float	vlen(t_vec v);
t_vec	vmul(t_vec v, float c);
t_vec	vmag(t_vec v, t_vec m);
t_color	cadd(t_color c1, t_color c2);
t_color	cmul(t_color c, float t);

#endif
