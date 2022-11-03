/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rt_cyl6.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 22:04:27 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/03 23:44:37 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_init.h"
#include "parse.h"
#include "object.h"

t_parse	parse_rt_cyl_dia(t_mlx *mlx, char c)
{
	t_cylinder	*cylinder;

	cylinder = mlx->objects.tail.pre->content;
	if (c == ' ')
		return (PARSE_RT_CYL_DIA);
	else if ('0' <= c && c <= '9')
	{
		cylinder->dia = c - '0';
		return (PARSE_RT_CYL_DIA_NUM);
	}
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_cyl_dia_num(t_mlx *mlx, char c)
{
	t_cylinder	*cylinder;

	cylinder = mlx->objects.tail.pre->content;
	if ('0' <= c && c <= '9')
	{
		cylinder->dia = 10 * cylinder->dia + c - '0';
		return (PARSE_RT_CYL_DIA_NUM);
	}
	else if (c == '.')
	{
		mlx->parse.div = 1;
		return (PARSE_RT_CYL_DIA_FLOAT);
	}
	else if (c == ' ')
		return (PARSE_RT_CYL_HEI);
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_cyl_dia_float(t_mlx *mlx, char c)
{
	t_cylinder	*cylinder;

	cylinder = mlx->objects.tail.pre->content;
	if ('0' <= c && c <= '9')
	{
		mlx->parse.div *= 10;
		cylinder->dia += (double)(c - '0') / mlx->parse.div;
		return (PARSE_RT_CYL_DIA_FLOAT);
	}
	else if (c == ' ')
		return (PARSE_RT_CYL_HEI);
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_cyl_char(char c)
{
	if (c == 'y')
		return (PARSE_RT_CYL_SPACE);
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_cyl6(t_mlx *mlx, char c, t_parse state)
{
	if (state == PARSE_RT_CYL_DIA)
		return (parse_rt_cyl_dia(mlx, c));
	else if (state == PARSE_RT_CYL_DIA_NUM)
		return (parse_rt_cyl_dia_num(mlx, c));
	else if (state == PARSE_RT_CYL_DIA_FLOAT)
		return (parse_rt_cyl_dia_float(mlx, c));
	else
		return (PARSE_RT_ERROR);
}
