/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mattrix.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 19:35:35 by min-jo            #+#    #+#             */
/*   Updated: 2022/10/23 20:29:03 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAT_H
# define MAT

# define _USE_MATH_DEFINES
# include <math.h>
# include "vector.h"

void	mtranspose(t_vec m[4], t_vec *ret);
void	mmul(t_vec m1[4], t_vec m2[4], t_vec *ret);
t_vec	mmulvec(t_vec m[4], t_vec v);
void	mtranslate(t_vec v, t_vec *ret);

#endif
