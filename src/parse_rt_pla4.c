/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rt_pla4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 22:42:41 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/03 22:22:49 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_init.h"
#include "parse.h"
#include "object.h"

t_parse	parse_rt_pla_ori(t_mlx *mlx, char c)
{
	t_plane	*plane;

	plane = mlx->objects.tail.pre->content;
	if (c == ' ')
		return (PARSE_RT_PLA_ORI);
	else if (c == '-')
	{
		mlx->parse.sign = -1;
		plane->ori.x = 0;
		return (PARSE_RT_PLA_ORI_X_SIGN);
	}
	else if ('0' <= c && c <= '9')
	{
		mlx->parse.sign = 1;
		plane->ori.x = c - '0';
		return (PARSE_RT_PLA_ORI_X_NUM);
	}
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_pla_ori_x_sign(t_mlx *mlx, char c)
{
	t_plane	*plane;

	plane = mlx->objects.tail.pre->content;
	if ('0' <= c && c <= '9')
	{
		plane->ori.x = -(c - '0');
		return (PARSE_RT_PLA_ORI_X_NUM);
	}
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_pla_ori_x_num(t_mlx *mlx, char c)
{
	float	tmp;
	t_plane	*plane;

	plane = mlx->objects.tail.pre->content;
	if ('0' <= c && c <= '9')
	{
		tmp = 10 * plane->ori.x + mlx->parse.sign * (c - '0');
		if (tmp * mlx->parse.sign > 1.0)
			return (PARSE_RT_ERROR);
		plane->ori.x = tmp;
		return (PARSE_RT_PLA_ORI_X_NUM);
	}
	else if (c == '.')
	{
		mlx->parse.div = 1;
		return (PARSE_RT_PLA_ORI_X_FLOAT);
	}
	else if (c == ',')
	{
		mlx->parse.sign = 1;
		return (PARSE_RT_PLA_ORI_Y_SIGN);
	}
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_pla_ori_x_float(t_mlx *mlx, char c)
{
	t_plane	*plane;

	plane = mlx->objects.tail.pre->content;
	if ('0' <= c && c <= '9')
	{
		mlx->parse.div *= 10;
		plane->ori.x += mlx->parse.sign * (double)(c - '0') / mlx->parse.div;
		return (PARSE_RT_PLA_ORI_X_FLOAT);
	}
	else if (c == ',')
	{
		mlx->parse.sign = 1;
		return (PARSE_RT_PLA_ORI_Y_SIGN);
	}
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_pla_ori_y_sign(t_mlx *mlx, char c)
{
	t_plane	*plane;

	plane = mlx->objects.tail.pre->content;
	if (c == '-' && mlx->parse.sign == 1)
	{
		mlx->parse.sign = -1;
		plane->ori.y = 0;
		return (PARSE_RT_PLA_ORI_Y_SIGN);
	}
	else if ('0' <= c && c <= '9' && mlx->parse.sign == -1)
	{
		plane->ori.y = -(c - '0');
		return (PARSE_RT_PLA_ORI_Y_NUM);
	}
	else if ('0' <= c && c <= '9' && mlx->parse.sign == 1)
	{
		mlx->parse.sign = 1;
		plane->ori.y = c - '0';
		return (PARSE_RT_PLA_ORI_Y_NUM);
	}
	else
		return (PARSE_RT_ERROR);
}
