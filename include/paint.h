/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:07:31 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/06 00:52:15 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAINT_H
# define PAINT_H

# include "mlx_init.h"
# include "vector.h"

t_node	*find_closest(t_mlx *mlx, t_vec v, t_vec *p);
t_color	get_color(t_node *node);
t_color	ray_color(t_mlx *mlx, t_vec v);
void	paint(t_mlx *mlx);

#endif
