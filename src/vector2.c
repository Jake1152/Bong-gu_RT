/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 16:23:57 by min-jo            #+#    #+#             */
/*   Updated: 2022/10/22 18:28:42 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector2.h"

t_vec	vadd(t_vec v1, t_vec v2)
{
	return (t_vec){
		v1.x + v2.x,
		v1.y + v2.y,
		v1.z + v2.z,
	};
}

t_vec	vminus(t_vec v1, t_vec v2)
{
	return (t_vec){
		v1.x - v2.x,
		v1.y - v2.y,
		v1.z - v2.z,
	};
}

t_vec	vmul(t_vec v, float m)
{
	return (t_vec){
		v.x * m,
		v.y * m,
		v.z * m,
	};
}
