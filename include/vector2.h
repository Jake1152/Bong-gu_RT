/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:03:24 by min-jo            #+#    #+#             */
/*   Updated: 2022/10/22 18:26:29 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR2_H
# define VECTOR2_H

typedef struct s_vec
{
	float	x;
	float	y;
	float	z;
}	t_vec;

typedef t_vec	t_point;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

t_vec	vadd(t_vec v1, t_vec v2);
t_vec	vminus(t_vec v1, t_vec v2);
t_vec	vmul(t_vec v, float m);

#endif
