/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:03:24 by min-jo            #+#    #+#             */
/*   Updated: 2022/10/23 19:28:00 by min-jo           ###   ########.fr       */
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

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

t_vec	vadd(t_vec v1, t_vec v2);
t_vec	vsub(t_vec v1, t_vec v2);
float	vdot(t_vec v1, t_vec v2);
t_vec	vcross(t_vec v1, t_vec v2);
t_vec	vnorm(t_vec v);

#endif
