/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rt_sph5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 22:42:41 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/03 23:56:28 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_init.h"
#include "parse.h"
#include "object.h"

t_parse	parse_rt_sph_color(t_mlx *mlx, char c)
{
	t_sphere	*sphere;

	sphere = mlx->objects.tail.pre->content;
	if (c == ' ')
		return (PARSE_RT_SPH_COLOR);
	else if ('0' <= c && c <= '9')
	{
		sphere->col.t = 1;
		sphere->col.r = c - '0';
		return (PARSE_RT_SPH_R);
	}
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_sph_r(t_mlx *mlx, char c)
{
	unsigned char	tmp;
	t_sphere		*sphere;

	sphere = mlx->objects.tail.pre->content;
	if ('0' <= c && c <= '9')
	{
		tmp = 10 * sphere->col.r + c - '0';
		if (tmp < sphere->col.r)
			return (PARSE_RT_ERROR);
		sphere->col.r = tmp;
		return (PARSE_RT_SPH_R);
	}
	else if (c == ',')
	{
		sphere->col.g = 0;
		return (PARSE_RT_SPH_G);
	}
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_sph_g(t_mlx *mlx, char c)
{
	unsigned char	tmp;
	t_sphere		*sphere;

	sphere = mlx->objects.tail.pre->content;
	if ('0' <= c && c <= '9')
	{
		tmp = 10 * sphere->col.g + c - '0';
		if (tmp < sphere->col.g)
			return (PARSE_RT_ERROR);
		sphere->col.g = tmp;
		return (PARSE_RT_SPH_G);
	}
	else if (c == ',')
	{
		sphere->col.b = 0;
		return (PARSE_RT_SPH_B);
	}
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_sph_b(t_mlx *mlx, char c)
{
	unsigned char	tmp;
	t_sphere		*sphere;

	sphere = mlx->objects.tail.pre->content;
	if ('0' <= c && c <= '9')
	{
		tmp = 10 * sphere->col.b + c - '0';
		if (tmp < sphere->col.b)
			return (PARSE_RT_ERROR);
		sphere->col.b = tmp;
		return (PARSE_RT_SPH_B);
	}
	else if (c == '\n')
		return (PARSE_RT_LINE);
	else
		return (PARSE_RT_ERROR);
}
