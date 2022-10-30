/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:29:14 by min-jo            #+#    #+#             */
/*   Updated: 2022/10/30 23:47:47 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "mlx_init.h"

typedef enum e_prase
{
	PARSE_ARG_ERROR,
	PARSE_ARG_FINISH,
	PARSE_ARG_SPACE,
	PARSE_ARG_NUM,

	PARSE_RT_ERROR,
	PARSE_RT_FINISH,
	PARSE_RT_LINE,
	PARSE_RT_SPACE,

	PARSE_RT_AMBIENT_SPACE,
	PARSE_RT_AMBIENT_NUM,
	PARSE_RT_AMBIENT_FLOAT,
	PARSE_RT_AMBIENT_COLOR,
	PARSE_RT_AMBIENT_R,
	PARSE_RT_AMBIENT_G,
	PARSE_RT_AMBIENT_B,
	PARSE_RT_CAMERA,
	PARSE_RT_LIGHT,
	PARSE_RT_SPHERE,
	PARSE_RT_PLANE,
	PARSE_RT_CYLINDER,
}	t_parse;

/*
* parse_arg.c
*/
t_parse	parse_arg_space(char c, int *num);
t_parse	parse_arg_num(char c, int *num);
int		parse_arg(char *str, int *num);

/*
* parse_rt.c
*/
t_parse	get_object_state(char c);
t_parse	parse_rt_space(char c);
t_parse	parse_rt_line(char c);
t_parse	parse_rt_default(t_mlx *mlx, char c, t_parse state);
int		parse_rt(t_mlx *mlx, int fd);

/*
* parse_rt_ambient.c
*/
t_parse	parse_rt_ambient_space(t_mlx *mlx, char c);
t_parse	parse_rt_ambient_num(t_mlx *mlx, char c);
t_parse	parse_rt_ambient_float(t_mlx *mlx, char c, int *div);
t_parse	parse_rt_ambient(t_mlx *mlx, char c, t_parse state);

/*
* parse_rt_ambient2.c
*/
t_parse	parse_rt_ambient_color(t_mlx *mlx, char c);
t_parse	parse_rt_ambient_r(t_mlx *mlx, char c);
t_parse	parse_rt_ambient_g(t_mlx *mlx, char c);
t_parse	parse_rt_ambient_b(t_mlx *mlx, char c);

/*
* parse_rt_camera.c
*/
t_parse	parse_rt_camera(t_mlx *mlx, char c, t_parse state);

/*
* parse_rt_light.c
*/
t_parse	parse_rt_light(t_mlx *mlx, char c, t_parse state);

/*
* parse_rt_sphere.c
*/
t_parse	parse_rt_sphere(t_mlx *mlx, char c, t_parse state);

/*
* parse_rt_plane.c
*/
t_parse	parse_rt_plane(t_mlx *mlx, char c, t_parse state);

/*
* parse_rt_cylinder.c
*/
t_parse	parse_rt_cylinder(t_mlx *mlx, char c, t_parse state);

#endif
