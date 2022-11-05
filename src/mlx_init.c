/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:35:28 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/06 05:16:42 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_init.h"
#include "error.h"
#include "paint.h"
#include "object.h"
#include "transform.h"

void	print_objects(t_list *list);//#TODO
void	print_lights(t_list *list);//#TODO

int	destroy(t_mlx *mlx)
{
	mlx_destroy_window(mlx->ptr, mlx->win);
	clear_list(&mlx->lights);
	clear_list(&mlx->objects);
	clear_list(&mlx->lights_cpy);
	clear_list(&mlx->objects_cpy);
	exit(0);
	return (0);
}

int	mlx_wrap_key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_ESC)
		destroy(mlx);
	else if (keycode == KEY_UP)
		mlx->parse_cam.pos = vadd(mlx->parse_cam.pos,
				vmul(mlx->parse_cam.ori, 0.1));
	else if (keycode == KEY_DOWN)
		mlx->parse_cam.pos = vadd(mlx->parse_cam.pos,
				vmul(mlx->parse_cam.ori, -0.1));
	mlx->camera = newCamera(mlx->parse_cam.pos, mlx->parse_cam.ori);
	copy_transform(mlx);
	mlx->needpaint = 1;
	return (0);
}

int	mlx_wrap_mouse_hook(int button, int x, int y, t_mlx *mlx)
{
	if (button == MOUSE_LEFT)
		mlx->move = 1;
	else if (button == MOUSE_RIGHT)
	{
		mlx->move = 0;
		mlx->mouse = mlx->tmp_mouse;
	}
	(void)x;
	(void)y;
	return (0);
}

/*
* paint 하지 않아도 되고, 마우스 안 움직이면 다시 안 그림
*/
int	mlx_wrap_loop_hook(t_mlx *mlx)
{
	if (mlx->move)
		mlx_mouse_get_pos(mlx->win, &mlx->tmp_mouse.x, &mlx->tmp_mouse.y);
	if (!mlx->needpaint && !mlx->move)
		return (0);
	mlx->camera = newCamera(mlx->parse_cam.pos, mlx->parse_cam.ori);
	copy_transform(mlx);
	paint(mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.ptr, 0, 0);
	printf("in hook\n");
	print_lights(&mlx->lights_cpy);
	print_objects(&mlx->objects_cpy);
	mlx->needpaint = 0;
	return (0);
}

void	mlx_wrap_init_run(t_mlx *mlx, int width, int height)
{
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, width, height, "Bong-gu_RT");
	if (NULL == mlx->win)
		perror_exit("Error: mlx window create fail");
	mlx->img.ptr = mlx_new_image(mlx->ptr, width, height);
	if (NULL == mlx->img.ptr)
		perror_exit("Error: mlx window image fail");
	mlx->img.addr = mlx_get_data_addr(
			mlx->img.ptr,
			&mlx->img.bpp,
			&mlx->img.len,
			&mlx->img.endian);
	mlx->needpaint = 1;
	mlx->mouse = (t_mouse){width / 2, height / 2};
	mlx_hook(mlx->win, 17, 0L, destroy, mlx);
	mlx_key_hook(mlx->win, mlx_wrap_key_hook, mlx);
	mlx_mouse_hook(mlx->win, mlx_wrap_mouse_hook, mlx);
	mlx_loop_hook(mlx->ptr, mlx_wrap_loop_hook, mlx);
	mlx_loop(mlx->ptr);
}
