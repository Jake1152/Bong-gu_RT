/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:10:22 by min-jo            #+#    #+#             */
/*   Updated: 2022/10/29 17:56:14 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_init.h"
#include "vector.h"
#include "camera.h"

t_color	ray_color(t_vec	ray)
{
	double  t;

	t = 0.5 * (ray.y + 1.0);
	// (1-t) * 흰색 + t * 하늘색
	return (t_color){
		(1-t) * 1 + t * 0.5 * 255,
		(1-t) * 1 + t * 0.7 * 255,
		(1-t) * 1 + t * 1.0 * 255,
		1,
	};
}

void	paint(t_mlx *mlx)
{
	int		x;
	int		y;
	int		*tmp;
	t_color	color;

	y = -1;
	while (++y < mlx->viewport.height)
	{
		x = -1;
		while (++x < mlx->viewport.width)
		{
			// TODO x++ 로만 동작하게 효율적으로 바꿔야 함
			tmp = (int *)(mlx->img.addr + y * mlx->img.len + x * mlx->img.bpp / 8);
			color = ray_color(vnorm((t_vec){
				(double)x / (mlx->viewport.width - 1),
				(double)y / (mlx->viewport.height - 1),
				1,
				0,
			}));
			*tmp = *(int *)(char [4]){color.b, color.g, color.r, color.t};
		}
	}
}
