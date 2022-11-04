/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:10:22 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/04 14:52:16 by jim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mlx_init.h"
#include "vector.h"
#include "camera.h"
#include "object.h"
#include "hit.h"
#include <stdio.h>

/*
t_color	ray_color(t_vec *ray)
{
	double	t;

	t = 0.5 * (ray.y + 1.0);
	return ((t_color){
		(1 - t) * 1 + t * 0.5 * 255,
		(1 - t) * 1 + t * 0.7 * 255,
		(1 - t) * 1 + t * 1.0 * 255,
		1,
	});
}
*/

static t_hit_record	record_init()
{
	t_hit_record	record;

	record.tmin = EPSILON;
	record.tmax = INFINITY;
	return (record);
}

// void set_color(color, t_rgb_color r, t_rgb_color g, t_rgb_color b, t_rgb_color t)
t_color	ray_color(t_mlx *mlx, double x, double y)
{
	double	t;
	t_vec	ray;
	t_color	color;

	ray = vnorm((t_vec){
						(double)x / (mlx->viewport.width - 1),
						(double)y / (mlx->viewport.height - 1),
						1,
						0,
					});
	t = 0.5 * (ray.y + 1.0);
	mlx->rec = record_init();
	// 이제 법선 벡터를 매핑해서 얻은 색이 아닌, 앞으로 작성할 phong_lighting 함수의 결과값을 반환한다!
	// return (phong_lighting(mlx)); // not yet
	if (hit(&(mlx->objects), &(mlx->ray), &(mlx->rec)))
	{
		// printf("hitted!!!!\n");
		color.r = 255;
		color.g = 0;
		color.b = 0;
		color.t = 1;
	}
	else
	{
		color.r = (1 - t) * 1 + t * 0.5 * 255;
		color.g = (1 - t) * 1 + t * 0.7 * 255;
		color.b = (1 - t) * 1 + t * 1.0 * 255;
		color.t = 1;
	};
	return (color); 
}

/*
* TODO x++ 로만 동작하게 효율적으로 바꿔야 함
*/
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
			tmp = (int *)(mlx->img.addr + y * mlx->img.len
					+ x * mlx->img.bpp / 8);
			// color = ray_color(vnorm((t_vec){
			// 			(double)x / (mlx->viewport.width - 1),
			// 			(double)y / (mlx->viewport.height - 1),
			// 			1,
			// 			0,
			// 		}));
			color = ray_color(mlx, x, y);
			*tmp = *(int *)(char [4]){color.b, color.g, color.r, color.t};
		}
	}
}
