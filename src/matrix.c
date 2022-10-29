/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 19:36:54 by min-jo            #+#    #+#             */
/*   Updated: 2022/10/29 17:53:13 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "vector.h"

t_mat	mtranspose(t_mat m)
{
	t_mat	ret;

	ret.vecs[0] = (t_vec){m.vecs[0].x, m.vecs[1].x, m.vecs[2].x, m.vecs[3].x};
	ret.vecs[1] = (t_vec){m.vecs[0].y, m.vecs[1].y, m.vecs[2].y, m.vecs[3].y};
	ret.vecs[2] = (t_vec){m.vecs[0].z, m.vecs[1].z, m.vecs[2].z, m.vecs[3].z};
	ret.vecs[3] = (t_vec){m.vecs[0].w, m.vecs[1].w, m.vecs[2].w, m.vecs[3].w};
	return (ret);
}

t_mat	mmul(t_mat m1, t_mat m2)
{
	t_mat	ret;
	t_mat	t;
	int		i;

	t = mtranspose(m2);
	i = -1;
	while (++i < 4)
	{
		ret.vecs[i] = (t_vec){
			.x = vdot(m1.vecs[i], t.vecs[0]),
			.y = vdot(m1.vecs[i], t.vecs[1]),
			.z = vdot(m1.vecs[i], t.vecs[2]),
			.w = vdot(m1.vecs[i], t.vecs[3]),
		};
	}
	return (ret);
}

t_vec	mmulvec(t_mat m, t_vec v)
{
	return ((t_vec){
		.x = vdot(m.vecs[0], v),
		.y = vdot(m.vecs[1], v),
		.z = vdot(m.vecs[2], v),
		.w = vdot(m.vecs[3], v),
	});
}

t_mat	mtranslate(t_vec v)
{
	t_mat	ret;

	ret.vecs[0] = (t_vec){1, 0, 0, v.x};
	ret.vecs[1] = (t_vec){0, 1, 0, v.y};
	ret.vecs[2] = (t_vec){0, 0, 1, v.z};
	ret.vecs[3] = (t_vec){0, 0, 0, 1};
	return (ret);
}
