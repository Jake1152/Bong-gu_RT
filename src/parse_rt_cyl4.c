/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rt_cyl4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 22:42:41 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/04 00:04:58 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_init.h"
#include "parse.h"
#include "object.h"

t_parse	parse_rt_cyl_ori(t_mlx *mlx, char c)
{
	t_cylinder	*cylinder;

	cylinder = mlx->objects.tail.pre->content;
	if (c == ' ')
		return (PARSE_RT_CYL_ORI);
	else if (c == '-')
	{
		mlx->parse.sign = -1;
		cylinder->ori.x = 0;
		return (PARSE_RT_CYL_ORI_X_SIGN);
	}
	else if ('0' <= c && c <= '9')
	{
		mlx->parse.sign = 1;
		cylinder->ori.x = c - '0';
		return (PARSE_RT_CYL_ORI_X_NUM);
	}
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_cyl_ori_x_sign(t_mlx *mlx, char c)
{
	t_cylinder	*cylinder;

	cylinder = mlx->objects.tail.pre->content;
	if ('0' <= c && c <= '9')
	{
		cylinder->ori.x = -(c - '0');
		return (PARSE_RT_CYL_ORI_X_NUM);
	}
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_cyl_ori_x_num(t_mlx *mlx, char c)
{
	float		tmp;
	t_cylinder	*cylinder;

	cylinder = mlx->objects.tail.pre->content;
	if ('0' <= c && c <= '9')
	{
		tmp = 10 * cylinder->ori.x + mlx->parse.sign * (c - '0');
		if (tmp * mlx->parse.sign > 1.0)
			return (PARSE_RT_ERROR);
		cylinder->ori.x = tmp;
		return (PARSE_RT_CYL_ORI_X_NUM);
	}
	else if (c == '.')
	{
		mlx->parse.div = 1;
		return (PARSE_RT_CYL_ORI_X_FLOAT);
	}
	else if (c == ',')
	{
		mlx->parse.sign = 1;
		return (PARSE_RT_CYL_ORI_Y_SIGN);
	}
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_cyl_ori_x_float(t_mlx *mlx, char c)
{
	t_cylinder	*cylinder;

	cylinder = mlx->objects.tail.pre->content;
	if ('0' <= c && c <= '9')
	{
		mlx->parse.div *= 10;
		cylinder->ori.x += mlx->parse.sign * (double)(c - '0') / mlx->parse.div;
		return (PARSE_RT_CYL_ORI_X_FLOAT);
	}
	else if (c == ',')
	{
		mlx->parse.sign = 1;
		return (PARSE_RT_CYL_ORI_Y_SIGN);
	}
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_cyl_ori_y_sign(t_mlx *mlx, char c)
{
	t_cylinder	*cylinder;

	cylinder = mlx->objects.tail.pre->content;
	if (c == '-' && mlx->parse.sign == 1)
	{
		mlx->parse.sign = -1;
		cylinder->ori.y = 0;
		return (PARSE_RT_CYL_ORI_Y_SIGN);
	}
	else if ('0' <= c && c <= '9' && mlx->parse.sign == -1)
	{
		cylinder->ori.y = -(c - '0');
		return (PARSE_RT_CYL_ORI_Y_NUM);
	}
	else if ('0' <= c && c <= '9' && mlx->parse.sign == 1)
	{
		mlx->parse.sign = 1;
		cylinder->ori.y = c - '0';
		return (PARSE_RT_CYL_ORI_Y_NUM);
	}
	else
		return (PARSE_RT_ERROR);
}
