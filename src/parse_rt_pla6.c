/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rt_pla6.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 22:42:41 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/04 00:01:20 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_init.h"
#include "parse.h"
#include "object.h"

t_parse	parse_rt_pla_color(t_mlx *mlx, char c)
{
	t_plane	*plane;

	plane = mlx->objects.tail.pre->content;
	if (c == ' ')
		return (PARSE_RT_PLA_COLOR);
	else if ('0' <= c && c <= '9')
	{
		plane->col.t = 1;
		plane->col.r = c - '0';
		return (PARSE_RT_PLA_R);
	}
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_pla_r(t_mlx *mlx, char c)
{
	unsigned char	tmp;
	t_plane			*plane;

	plane = mlx->objects.tail.pre->content;
	if ('0' <= c && c <= '9')
	{
		tmp = 10 * plane->col.r + c - '0';
		if (tmp < plane->col.r)
			return (PARSE_RT_ERROR);
		plane->col.r = tmp;
		return (PARSE_RT_PLA_R);
	}
	else if (c == ',')
	{
		plane->col.g = 0;
		return (PARSE_RT_PLA_G);
	}
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_pla_g(t_mlx *mlx, char c)
{
	unsigned char	tmp;
	t_plane			*plane;

	plane = mlx->objects.tail.pre->content;
	if ('0' <= c && c <= '9')
	{
		tmp = 10 * plane->col.g + c - '0';
		if (tmp < plane->col.g)
			return (PARSE_RT_ERROR);
		plane->col.g = tmp;
		return (PARSE_RT_PLA_G);
	}
	else if (c == ',')
	{
		plane->col.b = 0;
		return (PARSE_RT_PLA_B);
	}
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_pla_b(t_mlx *mlx, char c)
{
	unsigned char	tmp;
	t_plane			*plane;

	plane = mlx->objects.tail.pre->content;
	if ('0' <= c && c <= '9')
	{
		tmp = 10 * plane->col.b + c - '0';
		if (tmp < plane->col.b)
			return (PARSE_RT_ERROR);
		plane->col.b = tmp;
		return (PARSE_RT_PLA_B);
	}
	else if (c == '\n')
		return (PARSE_RT_LINE);
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_pla6(t_mlx *mlx, char c, t_parse state)
{
	if (state == PARSE_RT_PLA_COLOR)
		return (parse_rt_pla_color(mlx, c));
	else if (state == PARSE_RT_PLA_R)
		return (parse_rt_pla_r(mlx, c));
	else if (state == PARSE_RT_PLA_G)
		return (parse_rt_pla_g(mlx, c));
	else if (state == PARSE_RT_PLA_B)
		return (parse_rt_pla_b(mlx, c));
	else
		return (PARSE_RT_ERROR);
}
