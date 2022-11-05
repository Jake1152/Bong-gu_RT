/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 21:32:54 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/06 05:38:14 by jim              ###   ########.fr       */
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
#include "transform.h"

static void	arg_check(int argc, char *argv[], t_mlx *mlx)
{
	if (argc != 4)
		perror_exit_arg("Error: arg count is not 3");
	if (parse_arg(argv[2], &mlx->viewport.width))
		perror_exit_arg("Error: while parse arg [width]");
	if (parse_arg(argv[3], &mlx->viewport.height))
		perror_exit_arg("Error: while parse arg [height]");
	mlx->viewport.aspect = (double)mlx->viewport.width / mlx->viewport.height;
}

static int	str_len(char *str)
{
	int	cnt;

	cnt = 0;
	while (*str)
	{
		++cnt;
		++str;
	}
	return (cnt);
}

static int	is_end_rt(char *str)
{
	int	len;

	len = str_len(str);
	if (str[len - 1] != 't')
		return (0);
	if (str[len - 2] != 'r')
		return (0);
	if (str[len - 3] != '.')
		return (0);
	return (1);
}

static void	rt_check(char *file_str, t_mlx *mlx)
{
	int	fd;

	if (!is_end_rt(file_str))
		perror_exit_arg("Error: file is not end with .rt");
	fd = open(file_str, O_RDONLY);
	if (fd == -1)
		perror_exit_arg("Error: .rt file not opened");
	init_list(&mlx->lights);
	init_list(&mlx->objects);
	init_list(&mlx->lights_cpy);
	init_list(&mlx->objects_cpy);
	if (parse_rt(mlx, fd))
	{
		close(fd);
		clear_list(&mlx->lights);
		clear_list(&mlx->lights);
		clear_list(&mlx->lights_cpy);
		clear_list(&mlx->objects_cpy);
		perror_exit_arg("Error: while parse .rt file");
	}
	close(fd);
}

int	main(int argc, char *argv[])
{
	t_mlx	mlx;

	arg_check(argc, argv, &mlx);
	rt_check(argv[1], &mlx);
	copy_transform(&mlx);
	mlx_wrap_init_run(&mlx, mlx.viewport.width, mlx.viewport.height);
}
