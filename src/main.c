/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 21:32:54 by min-jo            #+#    #+#             */
/*   Updated: 2022/10/23 21:39:38 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_init.h"
#include "camera.h"

int main(int argc, char *argv[])
{
	t_mlx	mlx;
	int		width = 1280;
	int		height = 720;

	// TODO use arg
	(void)argv;
	(void)argc;

	// TODO parse fill width, height
	// TODO mlx.camera = newCamera(pos, orient, fov);
	mlx_wrap_init_run(&mlx, width, height);
}
