/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rt_cam.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 22:42:41 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/03 22:14:07 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_init.h"
#include "parse.h"

t_parse	parse_rt_cam5(t_mlx *mlx, char c, t_parse state)
{
	if (state == PARSE_RT_CAM_ORI_Y_NUM)
		return (parse_rt_cam_ori_y_num(mlx, c));
	else if (state == PARSE_RT_CAM_ORI_Y_FLOAT)
		return (parse_rt_cam_ori_y_float(mlx, c));
	else if (state == PARSE_RT_CAM_ORI_Z_SIGN)
		return (parse_rt_cam_ori_z_sign(mlx, c));
	else if (state == PARSE_RT_CAM_ORI_Z_NUM)
		return (parse_rt_cam_ori_z_num(mlx, c));
	else if (state == PARSE_RT_CAM_ORI_Z_FLOAT)
		return (parse_rt_cam_ori_z_float(mlx, c));
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_cam4(t_mlx *mlx, char c, t_parse state)
{
	if (state == PARSE_RT_CAM_ORI)
		return (parse_rt_cam_ori(mlx, c));
	else if (state == PARSE_RT_CAM_ORI_X_SIGN)
		return (parse_rt_cam_ori_x_sign(mlx, c));
	else if (state == PARSE_RT_CAM_ORI_X_NUM)
		return (parse_rt_cam_ori_x_num(mlx, c));
	else if (state == PARSE_RT_CAM_ORI_X_FLOAT)
		return (parse_rt_cam_ori_x_float(mlx, c));
	else if (state == PARSE_RT_CAM_ORI_Y_SIGN)
		return (parse_rt_cam_ori_y_sign(mlx, c));
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_cam3(t_mlx *mlx, char c, t_parse state)
{
	if (state == PARSE_RT_CAM_POS_Y_NUM)
		return (parse_rt_cam_pos_y_num(mlx, c));
	else if (state == PARSE_RT_CAM_POS_Y_FLOAT)
		return (parse_rt_cam_pos_y_float(mlx, c));
	else if (state == PARSE_RT_CAM_POS_Z_SIGN)
		return (parse_rt_cam_pos_z_sign(mlx, c));
	else if (state == PARSE_RT_CAM_POS_Z_NUM)
		return (parse_rt_cam_pos_z_num(mlx, c));
	else if (state == PARSE_RT_CAM_POS_Z_FLOAT)
		return (parse_rt_cam_pos_z_float(mlx, c));
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_cam2(t_mlx *mlx, char c, t_parse state)
{
	if (state == PARSE_RT_CAM_SPACE)
		return (parse_rt_cam_space(mlx, c));
	else if (state == PARSE_RT_CAM_POS_X_SIGN)
		return (parse_rt_cam_pos_x_sign(mlx, c));
	else if (state == PARSE_RT_CAM_POS_X_NUM)
		return (parse_rt_cam_pos_x_num(mlx, c));
	else if (state == PARSE_RT_CAM_POS_X_FLOAT)
		return (parse_rt_cam_pos_x_float(mlx, c));
	else if (state == PARSE_RT_CAM_POS_Y_SIGN)
		return (parse_rt_cam_pos_y_sign(mlx, c));
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_cam(t_mlx *mlx, char c, t_parse state)
{
	if (PARSE_RT_CAM_SPACE <= state && state <= PARSE_RT_CAM_POS_Y_SIGN)
		return (parse_rt_cam2(mlx, c, state));
	else if (PARSE_RT_CAM_POS_Y_NUM <= state
		&& state <= PARSE_RT_CAM_POS_Z_FLOAT)
		return (parse_rt_cam3(mlx, c, state));
	else if (PARSE_RT_CAM_ORI <= state && state <= PARSE_RT_CAM_ORI_Y_SIGN)
		return (parse_rt_cam4(mlx, c, state));
	else if (PARSE_RT_CAM_ORI_Y_NUM <= state
		&& state <= PARSE_RT_CAM_ORI_Z_FLOAT)
		return (parse_rt_cam5(mlx, c, state));
	else if (PARSE_RT_CAM_FOV <= state && state <= PARSE_RT_CAM_FOV_FLOAT)
		return (parse_rt_cam6(mlx, c, state));
	else
		return (PARSE_RT_ERROR);
}
