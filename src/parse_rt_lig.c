/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rt_lig.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 22:42:41 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/03 23:54:10 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_init.h"
#include "parse.h"

t_parse	parse_rt_lig5(t_mlx *mlx, char c, t_parse state)
{
	if (state == PARSE_RT_LIG_COLOR)
		return (parse_rt_lig_color(mlx, c));
	else if (state == PARSE_RT_LIG_R)
		return (parse_rt_lig_r(mlx, c));
	else if (state == PARSE_RT_LIG_G)
		return (parse_rt_lig_g(mlx, c));
	else if (state == PARSE_RT_LIG_B)
		return (parse_rt_lig_b(mlx, c));
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_lig4(t_mlx *mlx, char c, t_parse state)
{
	if (state == PARSE_RT_LIG_BRI)
		return (parse_rt_lig_bri(mlx, c));
	else if (state == PARSE_RT_LIG_BRI_NUM)
		return (parse_rt_lig_bri_num(mlx, c));
	else if (state == PARSE_RT_LIG_BRI_FLOAT)
		return (parse_rt_lig_bri_float(mlx, c));
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_lig3(t_mlx *mlx, char c, t_parse state)
{
	if (state == PARSE_RT_LIG_POS_Y_NUM)
		return (parse_rt_lig_pos_y_num(mlx, c));
	else if (state == PARSE_RT_LIG_POS_Y_FLOAT)
		return (parse_rt_lig_pos_y_float(mlx, c));
	else if (state == PARSE_RT_LIG_POS_Z_SIGN)
		return (parse_rt_lig_pos_z_sign(mlx, c));
	else if (state == PARSE_RT_LIG_POS_Z_NUM)
		return (parse_rt_lig_pos_z_num(mlx, c));
	else if (state == PARSE_RT_LIG_POS_Z_FLOAT)
		return (parse_rt_lig_pos_z_float(mlx, c));
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_lig2(t_mlx *mlx, char c, t_parse state)
{
	if (state == PARSE_RT_LIG_SPACE)
		return (parse_rt_lig_space(mlx, c));
	else if (state == PARSE_RT_LIG_POS_X_SIGN)
		return (parse_rt_lig_pos_x_sign(mlx, c));
	else if (state == PARSE_RT_LIG_POS_X_NUM)
		return (parse_rt_lig_pos_x_num(mlx, c));
	else if (state == PARSE_RT_LIG_POS_X_FLOAT)
		return (parse_rt_lig_pos_x_float(mlx, c));
	else if (state == PARSE_RT_LIG_POS_Y_SIGN)
		return (parse_rt_lig_pos_y_sign(mlx, c));
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_lig(t_mlx *mlx, char c, t_parse state)
{
	if (PARSE_RT_LIG_SPACE <= state && state <= PARSE_RT_LIG_POS_Y_SIGN)
		return (parse_rt_lig2(mlx, c, state));
	else if (PARSE_RT_LIG_POS_Y_NUM <= state
		&& state <= PARSE_RT_LIG_POS_Z_FLOAT)
		return (parse_rt_lig3(mlx, c, state));
	else if (PARSE_RT_LIG_BRI <= state && state <= PARSE_RT_LIG_BRI_FLOAT)
		return (parse_rt_lig4(mlx, c, state));
	else if (PARSE_RT_LIG_COLOR <= state && state <= PARSE_RT_LIG_B)
		return (parse_rt_lig5(mlx, c, state));
	else
		return (PARSE_RT_ERROR);
}
