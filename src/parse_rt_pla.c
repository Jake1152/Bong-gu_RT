/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rt_pla.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 22:42:41 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/03 23:18:38 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_init.h"
#include "parse.h"

t_parse	parse_rt_pla5(t_mlx *mlx, char c, t_parse state)
{
	if (state == PARSE_RT_PLA_ORI_Y_NUM)
		return (parse_rt_pla_ori_y_num(mlx, c));
	else if (state == PARSE_RT_PLA_ORI_Y_FLOAT)
		return (parse_rt_pla_ori_y_float(mlx, c));
	else if (state == PARSE_RT_PLA_ORI_Z_SIGN)
		return (parse_rt_pla_ori_z_sign(mlx, c));
	else if (state == PARSE_RT_PLA_ORI_Z_NUM)
		return (parse_rt_pla_ori_z_num(mlx, c));
	else if (state == PARSE_RT_PLA_ORI_Z_FLOAT)
		return (parse_rt_pla_ori_z_float(mlx, c));
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_pla4(t_mlx *mlx, char c, t_parse state)
{
	if (state == PARSE_RT_PLA_ORI)
		return (parse_rt_pla_ori(mlx, c));
	else if (state == PARSE_RT_PLA_ORI_X_SIGN)
		return (parse_rt_pla_ori_x_sign(mlx, c));
	else if (state == PARSE_RT_PLA_ORI_X_NUM)
		return (parse_rt_pla_ori_x_num(mlx, c));
	else if (state == PARSE_RT_PLA_ORI_X_FLOAT)
		return (parse_rt_pla_ori_x_float(mlx, c));
	else if (state == PARSE_RT_PLA_ORI_Y_SIGN)
		return (parse_rt_pla_ori_y_sign(mlx, c));
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_pla3(t_mlx *mlx, char c, t_parse state)
{
	if (state == PARSE_RT_PLA_POS_Y_NUM)
		return (parse_rt_pla_pos_y_num(mlx, c));
	else if (state == PARSE_RT_PLA_POS_Y_FLOAT)
		return (parse_rt_pla_pos_y_float(mlx, c));
	else if (state == PARSE_RT_PLA_POS_Z_SIGN)
		return (parse_rt_pla_pos_z_sign(mlx, c));
	else if (state == PARSE_RT_PLA_POS_Z_NUM)
		return (parse_rt_pla_pos_z_num(mlx, c));
	else if (state == PARSE_RT_PLA_POS_Z_FLOAT)
		return (parse_rt_pla_pos_z_float(mlx, c));
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_pla2(t_mlx *mlx, char c, t_parse state)
{
	if (state == PARSE_RT_PLA_SPACE)
		return (parse_rt_pla_space(mlx, c));
	else if (state == PARSE_RT_PLA_POS_X_SIGN)
		return (parse_rt_pla_pos_x_sign(mlx, c));
	else if (state == PARSE_RT_PLA_POS_X_NUM)
		return (parse_rt_pla_pos_x_num(mlx, c));
	else if (state == PARSE_RT_PLA_POS_X_FLOAT)
		return (parse_rt_pla_pos_x_float(mlx, c));
	else if (state == PARSE_RT_PLA_POS_Y_SIGN)
		return (parse_rt_pla_pos_y_sign(mlx, c));
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_pla(t_mlx *mlx, char c, t_parse state)
{
	if (PARSE_RT_PLA_SPACE <= state && state <= PARSE_RT_PLA_POS_Y_SIGN)
		return (parse_rt_pla2(mlx, c, state));
	else if (PARSE_RT_PLA_POS_Y_NUM <= state
		&& state <= PARSE_RT_PLA_POS_Z_FLOAT)
		return (parse_rt_pla3(mlx, c, state));
	else if (PARSE_RT_PLA_ORI <= state && state <= PARSE_RT_PLA_ORI_Y_SIGN)
		return (parse_rt_pla4(mlx, c, state));
	else if (PARSE_RT_PLA_ORI_Y_NUM <= state
		&& state <= PARSE_RT_PLA_ORI_Z_FLOAT)
		return (parse_rt_pla5(mlx, c, state));
	else if (PARSE_RT_PLA_COLOR <= state && state <= PARSE_RT_PLA_B)
		return (parse_rt_pla6(mlx, c, state));
	else if (state == PARSE_RT_PLA_CHAR)
		return (parse_rt_pla_char(c));
	else
		return (PARSE_RT_ERROR);
}
