/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rt_cyl7.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 22:04:27 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/03 23:48:26 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_init.h"
#include "parse.h"
#include "object.h"

t_parse	parse_rt_cyl_hei(t_mlx *mlx, char c)
{
	t_cylinder	*cylinder;

	cylinder = mlx->objects.tail.pre->content;
	if (c == ' ')
		return (PARSE_RT_CYL_HEI);
	else if ('0' <= c && c <= '9')
	{
		cylinder->hei = c - '0';
		return (PARSE_RT_CYL_HEI_NUM);
	}
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_cyl_hei_num(t_mlx *mlx, char c)
{
	t_cylinder	*cylinder;

	cylinder = mlx->objects.tail.pre->content;
	if ('0' <= c && c <= '9')
	{
		cylinder->hei = 10 * cylinder->hei + c - '0';
		return (PARSE_RT_CYL_HEI_NUM);
	}
	else if (c == '.')
	{
		mlx->parse.div = 1;
		return (PARSE_RT_CYL_HEI_FLOAT);
	}
	else if (c == ' ')
		return (PARSE_RT_CYL_COLOR);
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_cyl_hei_float(t_mlx *mlx, char c)
{
	t_cylinder	*cylinder;

	cylinder = mlx->objects.tail.pre->content;
	if ('0' <= c && c <= '9')
	{
		mlx->parse.div *= 10;
		cylinder->hei += (double)(c - '0') / mlx->parse.div;
		return (PARSE_RT_CYL_HEI_FLOAT);
	}
	else if (c == ' ')
		return (PARSE_RT_CYL_COLOR);
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_cyl7(t_mlx *mlx, char c, t_parse state)
{
	if (state == PARSE_RT_CYL_HEI)
		return (parse_rt_cyl_hei(mlx, c));
	else if (state == PARSE_RT_CYL_HEI_NUM)
		return (parse_rt_cyl_hei_num(mlx, c));
	else if (state == PARSE_RT_CYL_HEI_FLOAT)
		return (parse_rt_cyl_hei_float(mlx, c));
	else
		return (PARSE_RT_ERROR);
}
