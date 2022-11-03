/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rt_pla2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 22:42:41 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/03 22:19:36 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_init.h"
#include "parse.h"
#include "object.h"

t_parse	parse_rt_pla_space(t_mlx *mlx, char c)
{
	t_plane	*plane;

	plane = mlx->objects.tail.pre->content;
	if (c == ' ')
		return (PARSE_RT_PLA_SPACE);
	else if (c == '-')
	{
		mlx->parse.sign = -1;
		plane->pos.x = 0;
		return (PARSE_RT_PLA_POS_X_SIGN);
	}
	else if ('0' <= c && c <= '9')
	{
		mlx->parse.sign = 1;
		plane->pos.x = c - '0';
		return (PARSE_RT_PLA_POS_X_NUM);
	}
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_pla_pos_x_sign(t_mlx *mlx, char c)
{
	t_plane	*plane;

	plane = mlx->objects.tail.pre->content;
	if ('0' <= c && c <= '9')
	{
		plane->pos.x = -(c - '0');
		return (PARSE_RT_PLA_POS_X_NUM);
	}
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_pla_pos_x_num(t_mlx *mlx, char c)
{
	t_plane	*plane;

	plane = mlx->objects.tail.pre->content;
	if ('0' <= c && c <= '9')
	{
		plane->pos.x = 10 * plane->pos.x + mlx->parse.sign * (c - '0');
		return (PARSE_RT_PLA_POS_X_NUM);
	}
	else if (c == '.')
	{
		mlx->parse.div = 1;
		return (PARSE_RT_PLA_POS_X_FLOAT);
	}
	else if (c == ',')
	{
		mlx->parse.sign = 1;
		return (PARSE_RT_PLA_POS_Y_SIGN);
	}
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_pla_pos_x_float(t_mlx *mlx, char c)
{
	t_plane	*plane;

	plane = mlx->objects.tail.pre->content;
	if ('0' <= c && c <= '9')
	{
		mlx->parse.div *= 10;
		plane->pos.x += mlx->parse.sign * (double)(c - '0') / mlx->parse.div;
		return (PARSE_RT_PLA_POS_X_FLOAT);
	}
	else if (c == ',')
	{
		mlx->parse.sign = 1;
		return (PARSE_RT_PLA_POS_Y_SIGN);
	}
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_pla_pos_y_sign(t_mlx *mlx, char c)
{
	t_plane	*plane;

	plane = mlx->objects.tail.pre->content;
	if (c == '-' && mlx->parse.sign == 1)
	{
		mlx->parse.sign = -1;
		plane->pos.y = 0;
		return (PARSE_RT_PLA_POS_Y_SIGN);
	}
	else if ('0' <= c && c <= '9' && mlx->parse.sign == -1)
	{
		plane->pos.y = -(c - '0');
		return (PARSE_RT_PLA_POS_Y_NUM);
	}
	else if ('0' <= c && c <= '9' && mlx->parse.sign == 1)
	{
		mlx->parse.sign = 1;
		plane->pos.y = c - '0';
		return (PARSE_RT_PLA_POS_Y_NUM);
	}
	else
		return (PARSE_RT_ERROR);
}
