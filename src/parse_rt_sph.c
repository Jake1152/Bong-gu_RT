/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rt_sph.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 22:42:41 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/03 23:50:21 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_init.h"
#include "parse.h"

t_parse	parse_rt_sph5(t_mlx *mlx, char c, t_parse state)
{
	if (state == PARSE_RT_SPH_COLOR)
		return (parse_rt_sph_color(mlx, c));
	else if (state == PARSE_RT_SPH_R)
		return (parse_rt_sph_r(mlx, c));
	else if (state == PARSE_RT_SPH_G)
		return (parse_rt_sph_g(mlx, c));
	else if (state == PARSE_RT_SPH_B)
		return (parse_rt_sph_b(mlx, c));
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_sph4(t_mlx *mlx, char c, t_parse state)
{
	if (state == PARSE_RT_SPH_POS_Z_FLOAT)
		return (parse_rt_sph_pos_z_float(mlx, c));
	else if (state == PARSE_RT_SPH_DIA)
		return (parse_rt_sph_dia(mlx, c));
	else if (state == PARSE_RT_SPH_DIA_NUM)
		return (parse_rt_sph_dia_num(mlx, c));
	else if (state == PARSE_RT_SPH_DIA_FLOAT)
		return (parse_rt_sph_dia_float(mlx, c));
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_sph3(t_mlx *mlx, char c, t_parse state)
{
	if (state == PARSE_RT_SPH_POS_Y_SIGN)
		return (parse_rt_sph_pos_y_sign(mlx, c));
	else if (state == PARSE_RT_SPH_POS_Y_NUM)
		return (parse_rt_sph_pos_y_num(mlx, c));
	else if (state == PARSE_RT_SPH_POS_Y_FLOAT)
		return (parse_rt_sph_pos_y_float(mlx, c));
	else if (state == PARSE_RT_SPH_POS_Z_SIGN)
		return (parse_rt_sph_pos_z_sign(mlx, c));
	else if (state == PARSE_RT_SPH_POS_Z_NUM)
		return (parse_rt_sph_pos_z_num(mlx, c));
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_sph2(t_mlx *mlx, char c, t_parse state)
{
	if (state == PARSE_RT_SPH_CHAR)
		return (parse_rt_sph_char(c));
	else if (state == PARSE_RT_SPH_SPACE)
		return (parse_rt_sph_space(mlx, c));
	else if (state == PARSE_RT_SPH_POS_X_SIGN)
		return (parse_rt_sph_pos_x_sign(mlx, c));
	else if (state == PARSE_RT_SPH_POS_X_NUM)
		return (parse_rt_sph_pos_x_num(mlx, c));
	else if (state == PARSE_RT_SPH_POS_X_FLOAT)
		return (parse_rt_sph_pos_x_float(mlx, c));
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_sph(t_mlx *mlx, char c, t_parse state)
{
	if (PARSE_RT_SPH_CHAR <= state && state <= PARSE_RT_SPH_POS_X_FLOAT)
		return (parse_rt_sph2(mlx, c, state));
	else if (PARSE_RT_SPH_POS_Y_SIGN <= state
		&& state <= PARSE_RT_SPH_POS_Z_NUM)
		return (parse_rt_sph3(mlx, c, state));
	else if (PARSE_RT_SPH_POS_Z_FLOAT <= state
		&& state <= PARSE_RT_SPH_DIA_FLOAT)
		return (parse_rt_sph4(mlx, c, state));
	else if (PARSE_RT_SPH_COLOR <= state && state <= PARSE_RT_SPH_B)
		return (parse_rt_sph5(mlx, c, state));
	else
		return (PARSE_RT_ERROR);
}
