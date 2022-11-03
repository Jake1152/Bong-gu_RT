/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rt_sph3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 22:42:41 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/03 22:17:14 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_init.h"
#include "parse.h"
#include "object.h"

t_parse	parse_rt_sph_pos_y_sign(t_mlx *mlx, char c)
{
	t_sphere	*sphere;

	sphere = mlx->objects.tail.pre->content;
	if (c == '-' && mlx->parse.sign == 1)
	{
		mlx->parse.sign = -1;
		sphere->pos.y = 0;
		return (PARSE_RT_SPH_POS_Y_SIGN);
	}
	else if ('0' <= c && c <= '9' && mlx->parse.sign == -1)
	{
		sphere->pos.y = -(c - '0');
		return (PARSE_RT_SPH_POS_Y_NUM);
	}
	else if ('0' <= c && c <= '9' && mlx->parse.sign == 1)
	{
		mlx->parse.sign = 1;
		sphere->pos.y = c - '0';
		return (PARSE_RT_SPH_POS_Y_NUM);
	}
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_sph_pos_y_num(t_mlx *mlx, char c)
{
	t_sphere	*sphere;

	sphere = mlx->objects.tail.pre->content;
	if ('0' <= c && c <= '9')
	{
		sphere->pos.y = 10 * sphere->pos.y + mlx->parse.sign * (c - '0');
		return (PARSE_RT_SPH_POS_Y_NUM);
	}
	else if (c == '.')
	{
		mlx->parse.div = 1;
		return (PARSE_RT_SPH_POS_Y_FLOAT);
	}
	else if (c == ',')
	{
		mlx->parse.sign = 1;
		return (PARSE_RT_SPH_POS_Z_SIGN);
	}
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_sph_pos_y_float(t_mlx *mlx, char c)
{
	t_sphere	*sphere;

	sphere = mlx->objects.tail.pre->content;
	if ('0' <= c && c <= '9')
	{
		mlx->parse.div *= 10;
		sphere->pos.y += mlx->parse.sign * (double)(c - '0') / mlx->parse.div;
		return (PARSE_RT_SPH_POS_Y_FLOAT);
	}
	else if (c == ',')
	{
		mlx->parse.sign = 1;
		return (PARSE_RT_SPH_POS_Z_SIGN);
	}
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_sph_pos_z_sign(t_mlx *mlx, char c)
{
	t_sphere	*sphere;

	sphere = mlx->objects.tail.pre->content;
	if (c == '-' && mlx->parse.sign == 1)
	{
		mlx->parse.sign = -1;
		sphere->pos.z = 0;
		return (PARSE_RT_SPH_POS_Z_SIGN);
	}
	else if ('0' <= c && c <= '9' && mlx->parse.sign == -1)
	{
		sphere->pos.z = -(c - '0');
		return (PARSE_RT_SPH_POS_Z_NUM);
	}
	else if ('0' <= c && c <= '9' && mlx->parse.sign == 1)
	{
		mlx->parse.sign = 1;
		sphere->pos.z = c - '0';
		return (PARSE_RT_SPH_POS_Z_NUM);
	}
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_sph_pos_z_num(t_mlx *mlx, char c)
{
	t_sphere	*sphere;

	sphere = mlx->objects.tail.pre->content;
	if ('0' <= c && c <= '9')
	{
		sphere->pos.z = 10 * sphere->pos.z + mlx->parse.sign * (c - '0');
		return (PARSE_RT_SPH_POS_Z_NUM);
	}
	else if (c == '.')
	{
		mlx->parse.div = 1;
		return (PARSE_RT_SPH_POS_Z_FLOAT);
	}
	else if (c == ' ')
		return (PARSE_RT_SPH_DIA);
	else
		return (PARSE_RT_ERROR);
}
