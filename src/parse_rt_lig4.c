/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rt_lig4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 22:42:41 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/03 21:32:11 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_init.h"
#include "parse.h"
#include "light.h"

t_parse	parse_rt_lig_bri(t_mlx *mlx, char c)
{
	t_light_spot	*light;

	light = mlx->lights.tail.pre->content;
	if (c == ' ')
		return (PARSE_RT_LIG_BRI);
	else if ('0' <= c && c <= '9')
	{
		light->bri = c - '0';
		return (PARSE_RT_LIG_BRI_NUM);
	}
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_lig_bri_num(t_mlx *mlx, char c)
{
	t_light_spot	*light;

	light = mlx->lights.tail.pre->content;
	if ('0' <= c && c <= '9')
	{
		light->bri = 10 * light->bri + c - '0';
		return (PARSE_RT_LIG_BRI_NUM);
	}
	else if (c == '.')
	{
		mlx->parse.div = 1;
		return (PARSE_RT_LIG_BRI_FLOAT);
	}
	else if (c == ' ')
		return (PARSE_RT_LIG_COLOR);
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_lig_bri_float(t_mlx *mlx, char c)
{
	t_light_spot	*light;

	light = mlx->lights.tail.pre->content;
	if ('0' <= c && c <= '9')
	{
		mlx->parse.div *= 10;
		light->bri += (double)(c - '0') / mlx->parse.div;
		return (PARSE_RT_LIG_BRI_FLOAT);
	}
	else if (c == ' ')
		return (PARSE_RT_LIG_COLOR);
	else
		return (PARSE_RT_ERROR);
}
