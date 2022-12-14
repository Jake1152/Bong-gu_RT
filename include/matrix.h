/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 19:35:35 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/06 05:13:23 by jim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include "vector.h"

typedef struct s_mat
{
	t_vec	vecs[4];
}	t_mat;

t_mat	mtranspose(t_mat m);
t_mat	mmul(t_mat m1, t_mat m2);
t_vec	mmulvec(t_mat m, t_vec v);
t_mat	mtranslate(t_vec v);
t_mat	mrotate(float angle, t_vec v);

#endif
