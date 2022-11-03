/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rt_amb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 22:42:41 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/03 17:22:28 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_init.h"
#include "parse.h"

t_parse	parse_rt_amb_space(t_mlx *mlx, char c)
{
	if (c == ' ')
		return (PARSE_RT_AMB_SPACE);
	else if ('0' <= c && c <= '9')
	{
		mlx->light_ambient.bri = c - '0';
		return (PARSE_RT_AMB_NUM);
	}
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_amb_num(t_mlx *mlx, char c)
{
	if ('0' <= c && c <= '9')
	{
		mlx->light_ambient.bri = 10 * mlx->light_ambient.bri + c - '0';
		return (PARSE_RT_AMB_NUM);
	}
	else if (c == '.')
	{
		mlx->parse.div = 1;
		return (PARSE_RT_AMB_FLOAT);
	}
	else if (c == ' ')
		return (PARSE_RT_AMB_COLOR);
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_amb_float(t_mlx *mlx, char c)
{
	if ('0' <= c && c <= '9')
	{
		mlx->parse.div *= 10;
		mlx->light_ambient.bri += (double)(c - '0') / mlx->parse.div;
		return (PARSE_RT_AMB_FLOAT);
	}
	else if (c == ' ')
		return (PARSE_RT_AMB_COLOR);
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_amb(t_mlx *mlx, char c, t_parse state)
{
	if (state == PARSE_RT_AMB_SPACE)
		return (parse_rt_amb_space(mlx, c));
	else if (state == PARSE_RT_AMB_NUM)
		return (parse_rt_amb_num(mlx, c));
	else if (state == PARSE_RT_AMB_FLOAT)
		return (parse_rt_amb_float(mlx, c));
	else if (state == PARSE_RT_AMB_COLOR)
		return (parse_rt_amb_color(mlx, c));
	else if (state == PARSE_RT_AMB_R)
		return (parse_rt_amb_r(mlx, c));
	else if (state == PARSE_RT_AMB_G)
		return (parse_rt_amb_g(mlx, c));
	else if (state == PARSE_RT_AMB_B)
		return (parse_rt_amb_b(mlx, c));
	else
		return (PARSE_RT_ERROR);
}
