/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 19:35:35 by min-jo            #+#    #+#             */
/*   Updated: 2022/10/29 14:36:15 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAT_H
# define MAT_H

# include "vector.h"

typedef struct s_mat
{
	t_vec	vecs[4];
}	t_mat;

t_mat	mtranspose(t_mat m);
t_mat	mmul(t_mat m1, t_mat m2);
t_vec	mmulvec(t_mat m, t_vec v);
t_mat	mtranslate(t_vec v);

#endif
