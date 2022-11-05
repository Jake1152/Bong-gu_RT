/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:03:24 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/06 05:20:10 by jim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct	s_vec t_vec;
# define ZEROVEC (t_vec){0, 0, 0, 0}
# define ZEROPOS (t_vec){0, 0, 0, 1}

struct s_vec
{
	float	x;
	float	y;
	float	z;
	float	w;
};

typedef struct s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	t;
}	t_color;

t_vec			vadd(t_vec v1, t_vec v2);
t_vec			vsub(t_vec v1, t_vec v2);
float			vdot(t_vec v1, t_vec v2);
t_vec			vcross(t_vec v1, t_vec v2);
t_vec			vnorm(t_vec v);
t_vec			vadd_scala(t_vec v1, float float_num);
float			vlen(t_vec v);
t_vec			vmul(t_vec v, float c);
t_color			cadd(t_color c1, t_color c2);
t_color			cmul(t_color c, float t);
t_color			cdot(t_color object, t_color light);
unsigned char	ovfadd(unsigned char c1, unsigned char c2);

#endif
