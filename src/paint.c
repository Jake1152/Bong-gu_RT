/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:10:22 by min-jo            #+#    #+#             */
/*   Updated: 2022/10/22 18:49:18 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_init.h"

void	paint(t_mlx *mlx)
{
	// TODO paint
	int	x;
	int	y;
	int	*tmp;

	y = -1;
	while (++y < mlx->height)
	{
		x = -1;
		while (++x < mlx->width)
		{
			// TODO x++ 로만 동작하게 효율적으로 바꿔야 함
			tmp = (int *)(mlx->img.addr + y * mlx->img.len + x * mlx->img.bpp / 8);
			*tmp = *(int *)(char [4]){1, 1, 1, 1}; // TODO 색깔 칠하기
		}
	}
}
