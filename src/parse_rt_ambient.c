/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rt_ambient.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 22:42:41 by min-jo            #+#    #+#             */
/*   Updated: 2022/10/30 23:49:06 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_init.h"
#include "parse.h"
#include "object.h"

t_parse	parse_rt_ambient_space(t_mlx *mlx, char c)
{
	if (c == ' ')
		return (PARSE_RT_AMBIENT_SPACE);
	else if ('0' <= c && c <= '9')
	{
		mlx->light_ambient.bright = c - '0';
		return (PARSE_RT_AMBIENT_NUM);
	}
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_ambient_num(t_mlx *mlx, char c)
{
	if ('0' <= c && c <= '9')
	{
		mlx->light_ambient.bright = 10 * mlx->light_ambient.bright + c - '0';
		return (PARSE_RT_AMBIENT_NUM);
	}
	else if (c == '.')
		return (PARSE_RT_AMBIENT_FLOAT);
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_ambient_float(t_mlx *mlx, char c, int *div)
{
	if ('0' <= c && c <= '9')
	{
		*div *= 10;
		mlx->light_ambient.bright += (double)(c - '0') / *div;
		return (PARSE_RT_AMBIENT_FLOAT);
	}
	else if (c == ' ')
		return (PARSE_RT_AMBIENT_COLOR);
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_ambient(t_mlx *mlx, char c, t_parse state)
{
	static int	div = 1;

	if (state == PARSE_RT_AMBIENT_SPACE)
		return (parse_rt_ambient_space(mlx, c));
	else if (state == PARSE_RT_AMBIENT_NUM)
		return (parse_rt_ambient_num(mlx, c));
	else if (state == PARSE_RT_AMBIENT_FLOAT)
		return (parse_rt_ambient_float(mlx, c, &div));
	else if (state == PARSE_RT_AMBIENT_COLOR)
		return (parse_rt_ambient_color(mlx, c));
	else if (state == PARSE_RT_AMBIENT_R)
		return (parse_rt_ambient_r(mlx, c));
	else if (state == PARSE_RT_AMBIENT_G)
		return (parse_rt_ambient_g(mlx, c));
	else if (state == PARSE_RT_AMBIENT_B)
		return (parse_rt_ambient_b(mlx, c));
}
