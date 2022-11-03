/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rt_cyl2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 22:42:41 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/03 22:36:35 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_init.h"
#include "parse.h"
#include "object.h"

t_parse	parse_rt_cyl_space(t_mlx *mlx, char c)
{
	t_cylinder	*cylinder;

	cylinder = mlx->objects.tail.pre->content;
	if (c == ' ')
		return (PARSE_RT_CYL_SPACE);
	else if (c == '-')
	{
		mlx->parse.sign = -1;
		cylinder->pos.x = 0;
		return (PARSE_RT_CYL_POS_X_SIGN);
	}
	else if ('0' <= c && c <= '9')
	{
		mlx->parse.sign = 1;
		cylinder->pos.x = c - '0';
		return (PARSE_RT_CYL_POS_X_NUM);
	}
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_cyl_pos_x_sign(t_mlx *mlx, char c)
{
	t_cylinder	*cylinder;

	cylinder = mlx->objects.tail.pre->content;
	if ('0' <= c && c <= '9')
	{
		cylinder->pos.x = -(c - '0');
		return (PARSE_RT_CYL_POS_X_NUM);
	}
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_cyl_pos_x_num(t_mlx *mlx, char c)
{
	t_cylinder	*cylinder;

	cylinder = mlx->objects.tail.pre->content;
	if ('0' <= c && c <= '9')
	{
		cylinder->pos.x = 10 * cylinder->pos.x + mlx->parse.sign * (c - '0');
		return (PARSE_RT_CYL_POS_X_NUM);
	}
	else if (c == '.')
	{
		mlx->parse.div = 1;
		return (PARSE_RT_CYL_POS_X_FLOAT);
	}
	else if (c == ',')
	{
		mlx->parse.sign = 1;
		return (PARSE_RT_CYL_POS_Y_SIGN);
	}
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_cyl_pos_x_float(t_mlx *mlx, char c)
{
	t_cylinder	*cylinder;

	cylinder = mlx->objects.tail.pre->content;
	if ('0' <= c && c <= '9')
	{
		mlx->parse.div *= 10;
		cylinder->pos.x += mlx->parse.sign * (double)(c - '0') / mlx->parse.div;
		return (PARSE_RT_CYL_POS_X_FLOAT);
	}
	else if (c == ',')
	{
		mlx->parse.sign = 1;
		return (PARSE_RT_CYL_POS_Y_SIGN);
	}
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_cyl_pos_y_sign(t_mlx *mlx, char c)
{
	t_cylinder	*cylinder;

	cylinder = mlx->objects.tail.pre->content;
	if (c == '-' && mlx->parse.sign == 1)
	{
		mlx->parse.sign = -1;
		cylinder->pos.y = 0;
		return (PARSE_RT_CYL_POS_Y_SIGN);
	}
	else if ('0' <= c && c <= '9' && mlx->parse.sign == -1)
	{
		cylinder->pos.y = -(c - '0');
		return (PARSE_RT_CYL_POS_Y_NUM);
	}
	else if ('0' <= c && c <= '9' && mlx->parse.sign == 1)
	{
		mlx->parse.sign = 1;
		cylinder->pos.y = c - '0';
		return (PARSE_RT_CYL_POS_Y_NUM);
	}
	else
		return (PARSE_RT_ERROR);
}
