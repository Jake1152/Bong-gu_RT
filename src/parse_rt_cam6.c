/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rt_cam6.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 22:42:41 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/04 00:02:39 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_init.h"
#include "parse.h"
#include "object.h"

t_parse	parse_rt_cam_fov(t_mlx *mlx, char c)
{
	if (c == ' ')
		return (PARSE_RT_CAM_FOV);
	else if ('0' <= c && c <= '9')
	{
		mlx->parse_cam.fov = c - '0';
		return (PARSE_RT_CAM_FOV_NUM);
	}
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_cam_fov_num(t_mlx *mlx, char c)
{
	float	tmp;

	if ('0' <= c && c <= '9')
	{
		tmp = 10 * mlx->parse_cam.fov + c - '0';
		if (tmp > 180.0)
			return (PARSE_RT_ERROR);
		mlx->parse_cam.fov = tmp;
		return (PARSE_RT_CAM_FOV_NUM);
	}
	else if (c == '.')
	{
		mlx->parse.div = 1;
		return (PARSE_RT_CAM_FOV_FLOAT);
	}
	else if (c == '\n')
	{
		mlx->frustum = newFrustumPerspect(mlx->viewport.aspect,
				mlx->parse_cam.fov);
		mlx->camera = newCamera(mlx->parse_cam.pos, mlx->parse_cam.ori);
		return (PARSE_RT_LINE);
	}
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_cam_fov_float(t_mlx *mlx, char c)
{
	if ('0' <= c && c <= '9')
	{
		mlx->parse.div *= 10;
		mlx->parse_cam.fov += (double)(c - '0') / mlx->parse.div;
		return (PARSE_RT_CAM_FOV_FLOAT);
	}
	else if (c == '\n')
	{
		mlx->frustum = newFrustumPerspect(mlx->viewport.aspect,
				mlx->parse_cam.fov);
		mlx->camera = newCamera(mlx->parse_cam.pos, mlx->parse_cam.ori);
		return (PARSE_RT_LINE);
	}
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_cam6(t_mlx *mlx, char c, t_parse state)
{
	if (state == PARSE_RT_CAM_FOV)
		return (parse_rt_cam_fov(mlx, c));
	else if (state == PARSE_RT_CAM_FOV_NUM)
		return (parse_rt_cam_fov_num(mlx, c));
	else if (state == PARSE_RT_CAM_FOV_FLOAT)
		return (parse_rt_cam_fov_float(mlx, c));
	else
		return (PARSE_RT_ERROR);
}
