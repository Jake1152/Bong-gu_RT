/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 18:24:45 by min-jo            #+#    #+#             */
/*   Updated: 2022/10/22 18:29:14 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "vector2.h"

float	vdot(t_vec v1, t_vec v2);
t_vec	vcross(t_vec v1, t_vec v2);
t_vec	vnorm(t_vec v);

#endif
