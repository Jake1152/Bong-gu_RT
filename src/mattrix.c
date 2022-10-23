/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mattrix.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 19:36:54 by min-jo            #+#    #+#             */
/*   Updated: 2022/10/23 21:43:16 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mattrix.h"
#include "vector.h"

void	mtranspose(t_vec m[4], t_vec *ret)
{
	ret[0] = (t_vec){ret[0].x, ret[1].x, ret[2].x, ret[3].x};
	ret[1] = (t_vec){ret[0].y, ret[1].y, ret[2].y, ret[3].y};
	ret[2] = (t_vec){ret[0].z, ret[1].z, ret[2].z, ret[3].z};
	ret[3] = (t_vec){ret[0].w, ret[1].w, ret[2].w, ret[3].w};
}

void	mmul(t_vec m1[4], t_vec m2[4], t_vec *ret)
{
	t_vec	m1_t[4];
	int		i;

	mtranspose(m1, m1_t);
	i = -1;
	while (++i < 4)
	{
		ret[i] = (t_vec){
			vdot(m1_t[i], m2[0]),
			vdot(m1_t[i], m2[1]),
			vdot(m1_t[i], m2[2]),
			vdot(m1_t[i], m2[3]),
		};
	}
}

t_vec	mmulvec(t_vec m[4], t_vec v)
{
	t_vec	m_t[4];

	mtranspose(m, m_t);
	return ((t_vec){
		vdot(m_t[0], v),
		vdot(m_t[1], v),
		vdot(m_t[2], v),
		vdot(m_t[3], v),
	});
}

void	mtranslate(t_vec v, t_vec *ret)
{
	ret[0] = (t_vec){1, 0, 0, 0};
	ret[1] = (t_vec){0, 1, 0, 0};
	ret[2] = (t_vec){0, 0, 1, 0};
	ret[3] = (t_vec){v.x, v.y, v.z, 1};
}
