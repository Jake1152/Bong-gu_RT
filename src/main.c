/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 21:32:54 by min-jo            #+#    #+#             */
/*   Updated: 2022/10/30 23:29:48 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "mlx_init.h"
#include "error.h"
#include "camera.h"
#include "parse.h"
#include "object.h"

int main(int argc, char *argv[])
{
	t_mlx	mlx;
	int		fd;

	if (argc != 4)
		perror_exit_arg("Error: arg count is not 3");
	if (parse_arg(argv[1], &mlx.viewport.width))
		perror_exit_arg("Error: while parse arg [width]");
	if (parse_arg(argv[2], &mlx.viewport.height))
		perror_exit_arg("Error: while parse arg [height]");
	mlx.viewport.aspect = mlx.viewport.width / mlx.viewport.height;
	fd = open(argv[3], O_RDONLY);
	if (fd == -1)
		perror_exit_arg("Error: .rt file not opened");
	init_list(&mlx.lights);
	init_list(&mlx.objects);
	if (parse_rt(&mlx, fd))
	{
		close(fd);
		perror_exit_arg("Error: while parse .rt file");
	}
	close(fd);

	// TODO fov는 .rt 파일에서 파싱해야 함
	float	fov = 70;
	mlx.frustum = newFrustumPerspect(mlx.viewport.aspect, fov);

	// TODO camera의 position, orient .rt 파일에서 파싱해야 함
	// 현재는 카메라가 (0,0,0)에서 -z 방향 바라보게 설정
	mlx.camera = newCamera((t_vec){0, 0, 0, 1}, (t_vec){0, 0, -1, 0});

	mlx_wrap_init_run(&mlx, mlx.viewport.width, mlx.viewport.height);
}
