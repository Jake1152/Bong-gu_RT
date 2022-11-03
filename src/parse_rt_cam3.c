/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rt_cam3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 22:42:41 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/04 00:00:58 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_init.h"
#include "parse.h"

t_parse	parse_rt_cam_pos_y_num(t_mlx *mlx, char c)
{
	if ('0' <= c && c <= '9')
	{
		mlx->parse_cam.pos.y = 10 * mlx->parse_cam.pos.y
			+ mlx->parse.sign * (c - '0');
		return (PARSE_RT_CAM_POS_Y_NUM);
	}
	else if (c == '.')
	{
		mlx->parse.div = 1;
		return (PARSE_RT_CAM_POS_Y_FLOAT);
	}
	else if (c == ',')
	{
		mlx->parse.sign = 1;
		return (PARSE_RT_CAM_POS_Z_SIGN);
	}
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_cam_pos_y_float(t_mlx *mlx, char c)
{
	if ('0' <= c && c <= '9')
	{
		mlx->parse.div *= 10;
		mlx->parse_cam.pos.y += mlx->parse.sign
			* (double)(c - '0') / mlx->parse.div;
		return (PARSE_RT_CAM_POS_Y_FLOAT);
	}
	else if (c == ',')
	{
		mlx->parse.sign = 1;
		return (PARSE_RT_CAM_POS_Z_SIGN);
	}
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_cam_pos_z_sign(t_mlx *mlx, char c)
{
	if (c == '-' && mlx->parse.sign == 1)
	{
		mlx->parse.sign = -1;
		mlx->parse_cam.pos.z = 0;
		return (PARSE_RT_CAM_POS_Z_SIGN);
	}
	else if ('0' <= c && c <= '9' && mlx->parse.sign == -1)
	{
		mlx->parse_cam.pos.z = -(c - '0');
		return (PARSE_RT_CAM_POS_Z_NUM);
	}
	else if ('0' <= c && c <= '9' && mlx->parse.sign == 1)
	{
		mlx->parse.sign = 1;
		mlx->parse_cam.pos.z = c - '0';
		return (PARSE_RT_CAM_POS_Z_NUM);
	}
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_cam_pos_z_num(t_mlx *mlx, char c)
{
	if ('0' <= c && c <= '9')
	{
		mlx->parse_cam.pos.z = 10 * mlx->parse_cam.pos.z
			+ mlx->parse.sign * (c - '0');
		return (PARSE_RT_CAM_POS_Z_NUM);
	}
	else if (c == '.')
	{
		mlx->parse.div = 1;
		return (PARSE_RT_CAM_POS_Z_FLOAT);
	}
	else if (c == ' ')
		return (PARSE_RT_CAM_ORI);
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_cam_pos_z_float(t_mlx *mlx, char c)
{
	if ('0' <= c && c <= '9')
	{
		mlx->parse.div *= 10;
		mlx->parse_cam.pos.z += mlx->parse.sign
			* (double)(c - '0') / mlx->parse.div;
		return (PARSE_RT_CAM_POS_Z_FLOAT);
	}
	else if (c == ' ')
		return (PARSE_RT_CAM_ORI);
	else
		return (PARSE_RT_ERROR);
}
