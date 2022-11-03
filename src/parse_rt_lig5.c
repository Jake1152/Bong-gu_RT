/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rt_lig5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 22:42:41 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/03 21:49:49 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_init.h"
#include "parse.h"
#include "light.h"

t_parse	parse_rt_lig_color(t_mlx *mlx, char c)
{
	t_light_spot	*light;

	light = mlx->lights.tail.pre->content;
	if (c == ' ')
		return (PARSE_RT_LIG_COLOR);
	else if ('0' <= c && c <= '9')
	{
		light->col.t = 1;
		light->col.r = c - '0';
		return (PARSE_RT_LIG_R);
	}
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_lig_r(t_mlx *mlx, char c)
{
	unsigned char	tmp;
	t_light_spot	*light;

	light = mlx->lights.tail.pre->content;
	if ('0' <= c && c <= '9')
	{
		tmp = 10 * light->col.r + c - '0';
		if (tmp < light->col.r)
			return (PARSE_RT_ERROR);
		light->col.r = tmp;
		return (PARSE_RT_LIG_R);
	}
	else if (c == ',')
	{
		light->col.g = 0;
		return (PARSE_RT_LIG_G);
	}
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_lig_g(t_mlx *mlx, char c)
{
	unsigned char	tmp;
	t_light_spot	*light;

	light = mlx->lights.tail.pre->content;
	if ('0' <= c && c <= '9')
	{
		tmp = 10 * light->col.g + c - '0';
		if (tmp < light->col.g)
			return (PARSE_RT_ERROR);
		light->col.g = tmp;
		return (PARSE_RT_LIG_G);
	}
	else if (c == ',')
	{
		light->col.b = 0;
		return (PARSE_RT_LIG_B);
	}
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_lig_b(t_mlx *mlx, char c)
{
	unsigned char	tmp;
	t_light_spot	*light;

	light = mlx->lights.tail.pre->content;
	if ('0' <= c && c <= '9')
	{
		tmp = 10 * light->col.b + c - '0';
		if (tmp < light->col.b)
			return (PARSE_RT_ERROR);
		light->col.b = tmp;
		return (PARSE_RT_LIG_B);
	}
	else if (c == '\n')
		return (PARSE_RT_LINE);
	else
		return (PARSE_RT_ERROR);
}
