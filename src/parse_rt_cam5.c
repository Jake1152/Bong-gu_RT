/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rt_cam5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 22:42:41 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/04 00:04:44 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_init.h"
#include "parse.h"

t_parse	parse_rt_cam_ori_y_num(t_mlx *mlx, char c)
{
	float	tmp;

	if ('0' <= c && c <= '9')
	{
		tmp = 10 * mlx->parse_cam.ori.y + mlx->parse.sign * (c - '0');
		if (tmp * mlx->parse.sign > 1.0)
			return (PARSE_RT_ERROR);
		mlx->parse_cam.ori.y = tmp;
		return (PARSE_RT_CAM_ORI_Y_NUM);
	}
	else if (c == '.')
	{
		mlx->parse.div = 1;
		return (PARSE_RT_CAM_ORI_Y_FLOAT);
	}
	else if (c == ',')
	{
		mlx->parse.sign = 1;
		return (PARSE_RT_CAM_ORI_Z_SIGN);
	}
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_cam_ori_y_float(t_mlx *mlx, char c)
{
	if ('0' <= c && c <= '9')
	{
		mlx->parse.div *= 10;
		mlx->parse_cam.ori.y += mlx->parse.sign
			* (double)(c - '0') / mlx->parse.div;
		return (PARSE_RT_CAM_ORI_Y_FLOAT);
	}
	else if (c == ',')
	{
		mlx->parse.sign = 1;
		return (PARSE_RT_CAM_ORI_Z_SIGN);
	}
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_cam_ori_z_sign(t_mlx *mlx, char c)
{
	if (c == '-' && mlx->parse.sign == 1)
	{
		mlx->parse.sign = -1;
		mlx->parse_cam.ori.z = 0;
		return (PARSE_RT_CAM_ORI_Z_SIGN);
	}
	else if ('0' <= c && c <= '9' && mlx->parse.sign == -1)
	{
		mlx->parse_cam.ori.z = -(c - '0');
		return (PARSE_RT_CAM_ORI_Z_NUM);
	}
	else if ('0' <= c && c <= '9' && mlx->parse.sign == 1)
	{
		mlx->parse.sign = 1;
		mlx->parse_cam.ori.z = c - '0';
		return (PARSE_RT_CAM_ORI_Z_NUM);
	}
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_cam_ori_z_num(t_mlx *mlx, char c)
{
	float	tmp;

	if ('0' <= c && c <= '9')
	{
		tmp = 10 * mlx->parse_cam.ori.z + mlx->parse.sign * (c - '0');
		if (tmp * mlx->parse.sign > 1.0)
			return (PARSE_RT_ERROR);
		mlx->parse_cam.ori.z = tmp;
		return (PARSE_RT_CAM_ORI_Z_NUM);
	}
	else if (c == '.')
	{
		mlx->parse.div = 1;
		return (PARSE_RT_CAM_ORI_Z_FLOAT);
	}
	else if (c == ' ')
		return (PARSE_RT_CAM_FOV);
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_cam_ori_z_float(t_mlx *mlx, char c)
{
	if ('0' <= c && c <= '9')
	{
		mlx->parse.div *= 10;
		mlx->parse_cam.ori.z += mlx->parse.sign
			* (double)(c - '0') / mlx->parse.div;
		return (PARSE_RT_CAM_ORI_Z_FLOAT);
	}
	else if (c == ' ')
		return (PARSE_RT_CAM_FOV);
	else
		return (PARSE_RT_ERROR);
}
