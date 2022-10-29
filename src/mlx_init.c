/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:35:28 by min-jo            #+#    #+#             */
/*   Updated: 2022/10/29 16:26:18 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx_init.h"
#include "paint.h"

int	destroy(t_mlx *mlx)
{
	mlx_destroy_window(mlx->ptr, mlx->win);
	exit(0);
	return (0);
}

int	mlx_wrap_key_hook(int keycode, t_mlx *mlx)
{
	if (KEY_ESC == keycode)
		destroy(mlx);
	// TODO key hook
	mlx->painted = 0;
	return (0);
}

int	mlx_wrap_mouse_hook(int button, int x, int y, t_mlx *mlx)
{
	if (MOUSE_UP == button)
		return (0);
	// TODO mouse hook
	(void)x;
	(void)y;
	mlx->painted = 0;
	return (0);
}

int	mlx_wrap_loop_hook(t_mlx *mlx)
{
	int	x;
	int	y;

	// painted 됐으면 이미지 그려서 window로 보내는 거 안 함
	if (mlx->painted)
		return (0);
	paint(mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.ptr, 0, 0);
	(void)x;
	(void)y;
	// mlx_mouse_get_pos(mlx->win, &x, &y); // TODO
	mlx->painted = 1;
	return (0);
}

void	mlx_wrap_init_run(t_mlx *mlx, int width, int height)
{
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, width, height, "Bong-gu_RT");
	if (NULL == mlx->win)
		exit(1); // TODO perror
	mlx->img.ptr = mlx_new_image(mlx->ptr, width, height);
	if (NULL == mlx->img.ptr)
		exit(1); // TODO perror
	mlx->img.addr = mlx_get_data_addr(
		mlx->img.ptr,
		&mlx->img.bpp,
		&mlx->img.len,
		&mlx->img.endian);
	mlx->painted = 0;
	mlx_hook(mlx->win, 17, 0L, destroy, mlx);
	mlx_key_hook(mlx->win, mlx_wrap_key_hook, mlx);
	mlx_mouse_hook(mlx->win, mlx_wrap_mouse_hook, mlx);
	mlx_loop_hook(mlx->ptr, mlx_wrap_loop_hook, mlx);
	mlx_loop(mlx->ptr);
}
