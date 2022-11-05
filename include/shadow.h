/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 23:23:19 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/05 15:41:14 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHADOW_H
# define SHADOW_H

# include "mlx_init.h"
# include "vector.h"
# include "object.h"
# include "vector.h"

t_vec	vec_to_light(t_vec p, t_node *node);
int		is_hit_anything(t_list *objects, t_vec vlight);
int		check_shadow(t_mlx *mlx, t_vec p);

#endif
