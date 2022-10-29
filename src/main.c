/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 21:32:54 by min-jo            #+#    #+#             */
/*   Updated: 2022/10/29 16:24:52 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_init.h"
#include "camera.h"

int main(int argc, char *argv[])
{
	t_mlx	mlx;

	// TODO use arg
	(void)argv;
	(void)argc;

	// TODO width, height arg에서 파싱해야 함
	int	width = 1280;
	int	height = 960;
	mlx.viewport = (t_viewport){width, height, width / height};

	// TODO fov는 .rt 파일에서 파싱해야 함
	float	fov = 70;
	mlx.frustum = newFrustumPerspect(mlx.viewport.aspect, fov);

	// TODO camera의 position, orient .rt 파일에서 파싱해야 함
	// 현재는 카메라가 (0,0,0)에서 -z 방향 바라보게 설정
	mlx.camera = newCamera((t_vec){0, 0, 0, 1}, (t_vec){0, 0, -1, 0});

	mlx_wrap_init_run(&mlx, mlx.viewport.width, mlx.viewport.height);
}
