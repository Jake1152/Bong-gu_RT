/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:07:31 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/04 12:32:22 by jim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAINT_H
# define PAINT_H

# include "mlx_init.h"
# include "vector.h"

// t_color	ray_color(t_vec ray);
t_color	ray_color(t_mlx *mlx, double x, double y);
void	paint(t_mlx *mlx);

/*
struct  s_ray
{
    t_vec    orig;
    t_vec      dir;
};
*/

#endif
