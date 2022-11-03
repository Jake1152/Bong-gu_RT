/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rt_cyl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 22:42:41 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/03 23:45:47 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_init.h"
#include "parse.h"

t_parse	parse_rt_cyl5(t_mlx *mlx, char c, t_parse state)
{
	if (state == PARSE_RT_CYL_ORI_Y_NUM)
		return (parse_rt_cyl_ori_y_num(mlx, c));
	else if (state == PARSE_RT_CYL_ORI_Y_FLOAT)
		return (parse_rt_cyl_ori_y_float(mlx, c));
	else if (state == PARSE_RT_CYL_ORI_Z_SIGN)
		return (parse_rt_cyl_ori_z_sign(mlx, c));
	else if (state == PARSE_RT_CYL_ORI_Z_NUM)
		return (parse_rt_cyl_ori_z_num(mlx, c));
	else if (state == PARSE_RT_CYL_ORI_Z_FLOAT)
		return (parse_rt_cyl_ori_z_float(mlx, c));
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_cyl4(t_mlx *mlx, char c, t_parse state)
{
	if (state == PARSE_RT_CYL_ORI)
		return (parse_rt_cyl_ori(mlx, c));
	else if (state == PARSE_RT_CYL_ORI_X_SIGN)
		return (parse_rt_cyl_ori_x_sign(mlx, c));
	else if (state == PARSE_RT_CYL_ORI_X_NUM)
		return (parse_rt_cyl_ori_x_num(mlx, c));
	else if (state == PARSE_RT_CYL_ORI_X_FLOAT)
		return (parse_rt_cyl_ori_x_float(mlx, c));
	else if (state == PARSE_RT_CYL_ORI_Y_SIGN)
		return (parse_rt_cyl_ori_y_sign(mlx, c));
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_cyl3(t_mlx *mlx, char c, t_parse state)
{
	if (state == PARSE_RT_CYL_POS_Y_NUM)
		return (parse_rt_cyl_pos_y_num(mlx, c));
	else if (state == PARSE_RT_CYL_POS_Y_FLOAT)
		return (parse_rt_cyl_pos_y_float(mlx, c));
	else if (state == PARSE_RT_CYL_POS_Z_SIGN)
		return (parse_rt_cyl_pos_z_sign(mlx, c));
	else if (state == PARSE_RT_CYL_POS_Z_NUM)
		return (parse_rt_cyl_pos_z_num(mlx, c));
	else if (state == PARSE_RT_CYL_POS_Z_FLOAT)
		return (parse_rt_cyl_pos_z_float(mlx, c));
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_cyl2(t_mlx *mlx, char c, t_parse state)
{
	if (state == PARSE_RT_CYL_SPACE)
		return (parse_rt_cyl_space(mlx, c));
	else if (state == PARSE_RT_CYL_POS_X_SIGN)
		return (parse_rt_cyl_pos_x_sign(mlx, c));
	else if (state == PARSE_RT_CYL_POS_X_NUM)
		return (parse_rt_cyl_pos_x_num(mlx, c));
	else if (state == PARSE_RT_CYL_POS_X_FLOAT)
		return (parse_rt_cyl_pos_x_float(mlx, c));
	else if (state == PARSE_RT_CYL_POS_Y_SIGN)
		return (parse_rt_cyl_pos_y_sign(mlx, c));
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_cyl(t_mlx *mlx, char c, t_parse state)
{
	if (PARSE_RT_CYL_SPACE <= state && state <= PARSE_RT_CYL_POS_Y_SIGN)
		return (parse_rt_cyl2(mlx, c, state));
	else if (PARSE_RT_CYL_POS_Y_NUM <= state
		&& state <= PARSE_RT_CYL_POS_Z_FLOAT)
		return (parse_rt_cyl3(mlx, c, state));
	else if (PARSE_RT_CYL_ORI <= state && state <= PARSE_RT_CYL_ORI_Y_SIGN)
		return (parse_rt_cyl4(mlx, c, state));
	else if (PARSE_RT_CYL_ORI_Y_NUM <= state
		&& state <= PARSE_RT_CYL_ORI_Z_FLOAT)
		return (parse_rt_cyl5(mlx, c, state));
	else if (PARSE_RT_CYL_DIA <= state && state <= PARSE_RT_CYL_DIA_FLOAT)
		return (parse_rt_cyl6(mlx, c, state));
	else if (state == PARSE_RT_CYL_CHAR)
		return (parse_rt_cyl_char(c));
	else if (PARSE_RT_CYL_HEI <= state && state <= PARSE_RT_CYL_HEI_FLOAT)
		return (parse_rt_cyl7(mlx, c, state));
	else if (PARSE_RT_CYL_COLOR <= state && state <= PARSE_RT_CYL_B)
		return (parse_rt_cyl8(mlx, c, state));
	else
		return (PARSE_RT_ERROR);
}
