/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 23:28:32 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/05 20:22:50 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONG_H
# define PHONG_H

# include "mlx_init.h"
# include "vector.h"
# include "object.h"
# include "light.h"

t_vec	get_normal(t_node *node, t_vec p);
t_color	phong(t_list *lights_cpy, t_node *object_node, t_vec v, t_vec p);

#endif
