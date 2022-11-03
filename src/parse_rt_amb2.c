/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rt_amb2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 22:42:41 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/03 21:49:46 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_init.h"
#include "parse.h"
#include "object.h"

t_parse	parse_rt_amb_color(t_mlx *mlx, char c)
{
	if (c == ' ')
		return (PARSE_RT_AMB_COLOR);
	else if ('0' <= c && c <= '9')
	{
		mlx->light_ambient.col.t = 1;
		mlx->light_ambient.col.r = c - '0';
		return (PARSE_RT_AMB_R);
	}
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_amb_r(t_mlx *mlx, char c)
{
	unsigned char	tmp;

	if ('0' <= c && c <= '9')
	{
		tmp = 10 * mlx->light_ambient.col.r + c - '0';
		if (tmp < mlx->light_ambient.col.r)
			return (PARSE_RT_ERROR);
		mlx->light_ambient.col.r = tmp;
		return (PARSE_RT_AMB_R);
	}
	else if (c == ',')
	{
		mlx->light_ambient.col.g = 0;
		return (PARSE_RT_AMB_G);
	}
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_amb_g(t_mlx *mlx, char c)
{
	unsigned char	tmp;

	if ('0' <= c && c <= '9')
	{
		tmp = 10 * mlx->light_ambient.col.g + c - '0';
		if (tmp < mlx->light_ambient.col.g)
			return (PARSE_RT_ERROR);
		mlx->light_ambient.col.g = tmp;
		return (PARSE_RT_AMB_G);
	}
	else if (c == ',')
	{
		mlx->light_ambient.col.b = 0;
		return (PARSE_RT_AMB_B);
	}
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_amb_b(t_mlx *mlx, char c)
{
	unsigned char	tmp;

	if ('0' <= c && c <= '9')
	{
		tmp = 10 * mlx->light_ambient.col.b + c - '0';
		if (tmp < mlx->light_ambient.col.b)
			return (PARSE_RT_ERROR);
		mlx->light_ambient.col.b = tmp;
		return (PARSE_RT_AMB_B);
	}
	else if (c == '\n')
		return (PARSE_RT_LINE);
	else
		return (PARSE_RT_ERROR);
}
