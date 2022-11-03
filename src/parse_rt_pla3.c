/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rt_pla3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 22:42:41 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/03 22:20:27 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_init.h"
#include "parse.h"
#include "object.h"

t_parse	parse_rt_pla_pos_y_num(t_mlx *mlx, char c)
{
	t_plane	*plane;

	plane = mlx->objects.tail.pre->content;
	if ('0' <= c && c <= '9')
	{
		plane->pos.y = 10 * plane->pos.y + mlx->parse.sign * (c - '0');
		return (PARSE_RT_PLA_POS_Y_NUM);
	}
	else if (c == '.')
	{
		mlx->parse.div = 1;
		return (PARSE_RT_PLA_POS_Y_FLOAT);
	}
	else if (c == ',')
	{
		mlx->parse.sign = 1;
		return (PARSE_RT_PLA_POS_Z_SIGN);
	}
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_pla_pos_y_float(t_mlx *mlx, char c)
{
	t_plane	*plane;

	plane = mlx->objects.tail.pre->content;
	if ('0' <= c && c <= '9')
	{
		mlx->parse.div *= 10;
		plane->pos.y += mlx->parse.sign * (double)(c - '0') / mlx->parse.div;
		return (PARSE_RT_PLA_POS_Y_FLOAT);
	}
	else if (c == ',')
	{
		mlx->parse.sign = 1;
		return (PARSE_RT_PLA_POS_Z_SIGN);
	}
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_pla_pos_z_sign(t_mlx *mlx, char c)
{
	t_plane	*plane;

	plane = mlx->objects.tail.pre->content;
	if (c == '-' && mlx->parse.sign == 1)
	{
		mlx->parse.sign = -1;
		plane->pos.z = 0;
		return (PARSE_RT_PLA_POS_Z_SIGN);
	}
	else if ('0' <= c && c <= '9' && mlx->parse.sign == -1)
	{
		plane->pos.z = -(c - '0');
		return (PARSE_RT_PLA_POS_Z_NUM);
	}
	else if ('0' <= c && c <= '9' && mlx->parse.sign == 1)
	{
		mlx->parse.sign = 1;
		plane->pos.z = c - '0';
		return (PARSE_RT_PLA_POS_Z_NUM);
	}
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_pla_pos_z_num(t_mlx *mlx, char c)
{
	t_plane	*plane;

	plane = mlx->objects.tail.pre->content;
	if ('0' <= c && c <= '9')
	{
		plane->pos.z = 10 * plane->pos.z + mlx->parse.sign * (c - '0');
		return (PARSE_RT_PLA_POS_Z_NUM);
	}
	else if (c == '.')
	{
		mlx->parse.div = 1;
		return (PARSE_RT_PLA_POS_Z_FLOAT);
	}
	else if (c == ' ')
		return (PARSE_RT_PLA_ORI);
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_pla_pos_z_float(t_mlx *mlx, char c)
{
	t_plane	*plane;

	plane = mlx->objects.tail.pre->content;
	if ('0' <= c && c <= '9')
	{
		mlx->parse.div *= 10;
		plane->pos.z += mlx->parse.sign * (double)(c - '0') / mlx->parse.div;
		return (PARSE_RT_PLA_POS_Z_FLOAT);
	}
	else if (c == ' ')
		return (PARSE_RT_PLA_ORI);
	else
		return (PARSE_RT_ERROR);
}
