/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 21:32:54 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/05 10:26:03 by min-jo           ###   ########.fr       */
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

/*
* TODO 이함수 지워야 함
*/
void	print_lights(t_list *list)
{
	t_node			*tmp;
	int				cnt;
	t_light_spot	*lig;

	cnt = 0;
	tmp = list->head.next;
	printf("lise size: %d\n", list->size);
	while (tmp != &list->tail)
	{
		lig = (t_light_spot *)tmp->content;
		printf("l %d:\t", cnt);
		printf("pos %f,%f,%f,%f\t", lig->pos.x, lig->pos.y, lig->pos.z, lig->pos.w);
		printf("bri %f\t", lig->bri);
		printf("col %d,%d,%d,%d\n", lig->col.r, lig->col.g, lig->col.b, lig->col.t);
		tmp = tmp->next;
		++cnt;
	}
}

/*
* TODO 이함수 지워야 함
*/
void	print_objects(t_list *list)
{
	t_node	*tmp;
	int		cnt;

	cnt = 0;
	tmp = list->head.next;
	printf("lise size: %d\n", list->size);
	while (tmp != &list->tail)
	{
		if (tmp->type == TYPE_SPHERE)
		{
			t_sphere	*sph;
			sph = (t_sphere *)tmp->content;
			printf("sph %d:\t", cnt);
			printf("pos %f,%f,%f,%f\t", sph->pos.x, sph->pos.y, sph->pos.z, sph->pos.w);
			printf("dia %f\t", sph->dia);
			printf("col %d,%d,%d,%d\n", sph->col.r, sph->col.g, sph->col.b, sph->col.t);
		}
		else if (tmp->type == TYPE_PLANE)
		{
			t_plane	*pla;
			pla = (t_plane *)tmp->content;
			printf("pla %d:\t", cnt);
			printf("pos %f,%f,%f,%f\t", pla->pos.x, pla->pos.y, pla->pos.z, pla->pos.w);
			printf("ori %f,%f,%f,%f\t", pla->ori.x, pla->ori.y, pla->ori.z, pla->ori.w);
			printf("col %d,%d,%d,%d\n", pla->col.r, pla->col.g, pla->col.b, pla->col.t);
		}
		else if (tmp->type == TYPE_CYLINDER)
		{
			t_cylinder	*cyl;
			cyl = (t_cylinder *)tmp->content;
			printf("cyl %d:\t", cnt);
			printf("pos %f,%f,%f,%f\t", cyl->pos.x, cyl->pos.y, cyl->pos.z, cyl->pos.w);
			printf("ori %f,%f,%f,%f\t", cyl->ori.x, cyl->ori.y, cyl->ori.z, cyl->ori.w);
			printf("dia %f\t", cyl->dia);
			printf("hei %f\t", cyl->hei);
			printf("col %d,%d,%d,%d\n", cyl->col.r, cyl->col.g, cyl->col.b, cyl->col.t);
		}
		tmp = tmp->next;
		++cnt;
	}
}

static void	arg_check(int argc, char *argv[], t_mlx *mlx)
{
	(void)argv;//# TODO
	if (argc != 2)
		perror_exit_arg("Error: arg count is not 3");
	if (parse_arg("800", &mlx->viewport.width))
		perror_exit_arg("Error: while parse arg [width]");
	if (parse_arg("600", &mlx->viewport.height))
		perror_exit_arg("Error: while parse arg [height]");
	mlx->viewport.aspect = (double)mlx->viewport.width / mlx->viewport.height;
	printf("w%d h%d\n", mlx->viewport.width, mlx->viewport.height); //# TODO
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
	if (str[len-1] != 't')
		return (0);
	if (str[len-2] != 'r')
		return (0);
	if (str[len-3] != '.')
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

	//
	printf("viewport: w%d h%d a%f\n", mlx.viewport.width, mlx.viewport.height, mlx.viewport.aspect); //# TODO
	printf("frustum: w%f h%f bl%f,%f,%f,%f\n", mlx.frustum.width, mlx.frustum.height, mlx.frustum.bottom_left.x, mlx.frustum.bottom_left.y, mlx.frustum.bottom_left.z, mlx.frustum.bottom_left.w);
	printf("camera parse: pos%f,%f,%f ori%f,%f,%f fov%f\n", mlx.parse_cam.pos.x, mlx.parse_cam.pos.y, mlx.parse_cam.pos.z, mlx.parse_cam.ori.x, mlx.parse_cam.ori.y, mlx.parse_cam.ori.z, mlx.parse_cam.fov);
	printf("camera\n");
	for (int i=0; i<4; i++)
		printf("%f,%f,%f,%f\n", mlx.camera.vecs[i].x, mlx.camera.vecs[i].y, mlx.camera.vecs[i].z, mlx.camera.vecs[i].w);
	printf("ambient\t");
	printf("bri %f\t", mlx.light_ambient.bri);
	printf("col %d,%d,%d\n", mlx.light_ambient.col.r, mlx.light_ambient.col.g, mlx.light_ambient.col.b);
	print_lights(&mlx.lights);
	print_objects(&mlx.objects);
	//

	copy_transform(&mlx);
	mlx_wrap_init_run(&mlx, mlx.viewport.width, mlx.viewport.height);
}
