/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rt_cyl8.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 22:42:41 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/03 23:56:49 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_init.h"
#include "parse.h"
#include "object.h"

t_parse	parse_rt_cyl_color(t_mlx *mlx, char c)
{
	t_cylinder	*cylinder;

	cylinder = mlx->objects.tail.pre->content;
	if (c == ' ')
		return (PARSE_RT_CYL_COLOR);
	else if ('0' <= c && c <= '9')
	{
		cylinder->col.t = 1;
		cylinder->col.r = c - '0';
		return (PARSE_RT_CYL_R);
	}
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_cyl_r(t_mlx *mlx, char c)
{
	unsigned char	tmp;
	t_cylinder		*cylinder;

	cylinder = mlx->objects.tail.pre->content;
	if ('0' <= c && c <= '9')
	{
		tmp = 10 * cylinder->col.r + c - '0';
		if (tmp < cylinder->col.r)
			return (PARSE_RT_ERROR);
		cylinder->col.r = tmp;
		return (PARSE_RT_CYL_R);
	}
	else if (c == ',')
	{
		cylinder->col.g = 0;
		return (PARSE_RT_CYL_G);
	}
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_cyl_g(t_mlx *mlx, char c)
{
	unsigned char	tmp;
	t_cylinder		*cylinder;

	cylinder = mlx->objects.tail.pre->content;
	if ('0' <= c && c <= '9')
	{
		tmp = 10 * cylinder->col.g + c - '0';
		if (tmp < cylinder->col.g)
			return (PARSE_RT_ERROR);
		cylinder->col.g = tmp;
		return (PARSE_RT_CYL_G);
	}
	else if (c == ',')
	{
		cylinder->col.b = 0;
		return (PARSE_RT_CYL_B);
	}
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_cyl_b(t_mlx *mlx, char c)
{
	unsigned char	tmp;
	t_cylinder		*cylinder;

	cylinder = mlx->objects.tail.pre->content;
	if ('0' <= c && c <= '9')
	{
		tmp = 10 * cylinder->col.b + c - '0';
		if (tmp < cylinder->col.b)
			return (PARSE_RT_ERROR);
		cylinder->col.b = tmp;
		return (PARSE_RT_CYL_B);
	}
	else if (c == '\n')
		return (PARSE_RT_LINE);
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_cyl8(t_mlx *mlx, char c, t_parse state)
{
	if (state == PARSE_RT_CYL_COLOR)
		return (parse_rt_cyl_color(mlx, c));
	else if (state == PARSE_RT_CYL_R)
		return (parse_rt_cyl_r(mlx, c));
	else if (state == PARSE_RT_CYL_G)
		return (parse_rt_cyl_g(mlx, c));
	else if (state == PARSE_RT_CYL_B)
		return (parse_rt_cyl_b(mlx, c));
	else
		return (PARSE_RT_ERROR);
}
