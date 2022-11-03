/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rt_sph4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 22:42:41 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/03 22:42:03 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_init.h"
#include "parse.h"
#include "object.h"

t_parse	parse_rt_sph_pos_z_float(t_mlx *mlx, char c)
{
	t_sphere	*sphere;

	sphere = mlx->objects.tail.pre->content;
	if ('0' <= c && c <= '9')
	{
		mlx->parse.div *= 10;
		sphere->pos.z += mlx->parse.sign * (double)(c - '0') / mlx->parse.div;
		return (PARSE_RT_SPH_POS_Z_FLOAT);
	}
	else if (c == ' ')
		return (PARSE_RT_SPH_DIA);
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_sph_dia(t_mlx *mlx, char c)
{
	t_sphere	*sphere;

	sphere = mlx->objects.tail.pre->content;
	if (c == ' ')
		return (PARSE_RT_SPH_DIA);
	else if ('0' <= c && c <= '9')
	{
		sphere->dia = c - '0';
		return (PARSE_RT_SPH_DIA_NUM);
	}
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_sph_dia_num(t_mlx *mlx, char c)
{
	t_sphere	*sphere;

	sphere = mlx->objects.tail.pre->content;
	if ('0' <= c && c <= '9')
	{
		sphere->dia = 10 * sphere->dia + c - '0';
		return (PARSE_RT_SPH_DIA_NUM);
	}
	else if (c == '.')
	{
		mlx->parse.div = 1;
		return (PARSE_RT_SPH_DIA_FLOAT);
	}
	else if (c == ' ')
		return (PARSE_RT_SPH_COLOR);
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_sph_dia_float(t_mlx *mlx, char c)
{
	t_sphere	*sphere;

	sphere = mlx->objects.tail.pre->content;
	if ('0' <= c && c <= '9')
	{
		mlx->parse.div *= 10;
		sphere->dia += (double)(c - '0') / mlx->parse.div;
		return (PARSE_RT_SPH_DIA_FLOAT);
	}
	else if (c == ' ')
		return (PARSE_RT_SPH_COLOR);
	else
		return (PARSE_RT_ERROR);
}
