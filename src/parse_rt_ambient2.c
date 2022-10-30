/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rt_ambient2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 22:42:41 by min-jo            #+#    #+#             */
/*   Updated: 2022/10/31 00:04:06 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_init.h"
#include "parse.h"
#include "object.h"

t_parse	parse_rt_ambient_color(t_mlx *mlx, char c)
{
	if (c == ' ')
		return (PARSE_RT_AMBIENT_COLOR);
	else if ('0' <= c && c <= '9')
	{
		mlx->light_ambient.color.t = 1;
		mlx->light_ambient.color.r = c - '0';
		return (PARSE_RT_AMBIENT_R);
	}
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_ambient_r(t_mlx *mlx, char c)
{
	char	tmp;

	if ('0' <= c && c <= '9')
	{
		tmp = 10 * mlx->light_ambient.color.r + c - '0';
		if (tmp < mlx->light_ambient.color.r)
			return (PARSE_RT_ERROR);
		mlx->light_ambient.color.r = tmp;
		return (PARSE_RT_AMBIENT_R);
	}
	else if (c == ',')
		return (PARSE_RT_AMBIENT_G);
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_ambient_g(t_mlx *mlx, char c)
{
	char	tmp;

	if ('0' <= c && c <= '9')
	{
		tmp = 10 * mlx->light_ambient.color.g + c - '0';
		if (tmp < mlx->light_ambient.color.g)
			return (PARSE_RT_ERROR);
		mlx->light_ambient.color.g = tmp;
		return (PARSE_RT_AMBIENT_G);
	}
	else if (c == ',')
		return (PARSE_RT_AMBIENT_B);
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_ambient_b(t_mlx *mlx, char c)
{
	char	tmp;

	if ('0' <= c && c <= '9')
	{
		tmp = 10 * mlx->light_ambient.color.b + c - '0';
		if (tmp < mlx->light_ambient.color.b)
			return (PARSE_RT_ERROR);
		mlx->light_ambient.color.b = tmp;
		return (PARSE_RT_AMBIENT_B);
	}
	else if (c == '\n')
		return (PARSE_RT_LINE);
	else
		return (PARSE_RT_ERROR);
}
