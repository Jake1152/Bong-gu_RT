/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rt2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:29:12 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/05 13:01:57 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "mlx_init.h"

int	check_last(t_mlx *mlx, t_parse state, char c)
{
	if (state == PARSE_RT_LINE)
		return (0);
	else if ((state == PARSE_RT_CAM_FOV_FLOAT || state == PARSE_RT_CAM_FOV_NUM)
		&& '0' <= c && c <= '9')
	{
		mlx->frustum = newFrustumPerspect(
				mlx->viewport.aspect,
				mlx->parse_cam.fov);
		mlx->camera = newCamera(mlx->parse_cam.pos, mlx->parse_cam.ori);
		return (0);
	}
	else if (state == PARSE_RT_AMB_B || state == PARSE_RT_CYL_B
		|| state == PARSE_RT_LIG_B || state == PARSE_RT_PLA_B
		|| state == PARSE_RT_SPH_B)
		return (0);
	else
		return (1);
}
