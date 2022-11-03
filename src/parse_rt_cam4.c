/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rt_cam4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 22:42:41 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/03 23:52:19 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_init.h"
#include "parse.h"

t_parse	parse_rt_cam_ori(t_mlx *mlx, char c)
{
	if (c == ' ')
		return (PARSE_RT_CAM_ORI);
	else if (c == '-')
	{
		mlx->parse.sign = -1;
		mlx->parse_cam.ori.x = 0;
		return (PARSE_RT_CAM_ORI_X_SIGN);
	}
	else if ('0' <= c && c <= '9')
	{
		mlx->parse.sign = 1;
		mlx->parse_cam.ori.x = c - '0';
		return (PARSE_RT_CAM_ORI_X_NUM);
	}
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_cam_ori_x_sign(t_mlx *mlx, char c)
{
	if ('0' <= c && c <= '9')
	{
		mlx->parse_cam.ori.x = -(c - '0');
		return (PARSE_RT_CAM_ORI_X_NUM);
	}
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_cam_ori_x_num(t_mlx *mlx, char c)
{
	float	tmp;

	if ('0' <= c && c <= '9')
	{
		tmp = 10 * mlx->parse_cam.ori.x + mlx->parse.sign * (c - '0');
		if (tmp * mlx->parse.sign > 1.0)
			return (PARSE_RT_ERROR);
		mlx->parse_cam.ori.x = tmp;
		return (PARSE_RT_CAM_ORI_X_NUM);
	}
	else if (c == '.')
	{
		mlx->parse.div = 1;
		return (PARSE_RT_CAM_ORI_X_FLOAT);
	}
	else if (c == ',')
	{
		mlx->parse.sign = 1;
		return (PARSE_RT_CAM_ORI_Y_SIGN);
	}
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_cam_ori_x_float(t_mlx *mlx, char c)
{
	if ('0' <= c && c <= '9')
	{
		mlx->parse.div *= 10;
		mlx->parse_cam.ori.x += mlx->parse.sign * (double)(c - '0'
				) / mlx->parse.div;
		return (PARSE_RT_CAM_ORI_X_FLOAT);
	}
	else if (c == ',')
	{
		mlx->parse.sign = 1;
		return (PARSE_RT_CAM_ORI_Y_SIGN);
	}
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_cam_ori_y_sign(t_mlx *mlx, char c)
{
	if (c == '-' && mlx->parse.sign == 1)
	{
		mlx->parse.sign = -1;
		mlx->parse_cam.ori.y = 0;
		return (PARSE_RT_CAM_ORI_Y_SIGN);
	}
	else if ('0' <= c && c <= '9' && mlx->parse.sign == -1)
	{
		mlx->parse_cam.ori.y = -(c - '0');
		return (PARSE_RT_CAM_ORI_Y_NUM);
	}
	else if ('0' <= c && c <= '9' && mlx->parse.sign == 1)
	{
		mlx->parse.sign = 1;
		mlx->parse_cam.ori.y = c - '0';
		return (PARSE_RT_CAM_ORI_Y_NUM);
	}
	else
		return (PARSE_RT_ERROR);
}
