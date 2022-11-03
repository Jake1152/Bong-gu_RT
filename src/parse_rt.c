/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:29:12 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/03 21:47:44 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "mlx_init.h"
#include "parse.h"
#include "object.h"

t_parse	get_object_state(t_mlx *mlx, char c)
{
	if (c == 'A')
		return (PARSE_RT_AMB_SPACE);
	else if (c == 'C')
		return (PARSE_RT_CAM_SPACE);
	else if (c == 'L' || c == 'l')
		return (add_list_lig_ret_space(mlx));
	else if (c == 's')
		return (add_list_shp_ret_char(mlx));
	else if (c == 'p')
		return (add_list_pla_ret_char(mlx));
	else if (c == 'c')
		return (add_list_cyl_ret_char(mlx));
	else
		return (PARSE_RT_ERROR);
}

t_parse	parse_rt_line(t_mlx *mlx, char c)
{
	if (c == '\n')
		return (PARSE_RT_LINE);
	else if (c == ' ')
		return (PARSE_RT_SPACE);
	else
		return (get_object_state(mlx, c));
}

t_parse	parse_rt_space(t_mlx *mlx, char c)
{
	if (c == ' ')
		return (PARSE_RT_SPACE);
	else
		return (get_object_state(mlx, c));
}

t_parse	parse_rt_default(t_mlx *mlx, char c, t_parse state)
{
	if (state & PARSE_RT_AMB)
		return (parse_rt_amb(mlx, c, state));
	else if (state & PARSE_RT_CAM)
		return (parse_rt_cam(mlx, c, state));
	else if (state & PARSE_RT_LIG)
		return (parse_rt_lig(mlx, c, state));
	else if (state & PARSE_RT_SPH)
		return (parse_rt_sph(mlx, c, state));
	else if (state & PARSE_RT_PLA)
		return (parse_rt_pla(mlx, c, state));
	else if (state & PARSE_RT_CYL)
		return (parse_rt_cyl(mlx, c, state));
	else
		return (PARSE_RT_ERROR);
}

int	parse_rt(t_mlx *mlx, int fd)
{
	t_parse	state;
	char	c;

	state = PARSE_RT_LINE;
	while (read(fd, &c, 1) > 0)
	{
		if (state == PARSE_RT_ERROR)
			return (-1);
		else if (state == PARSE_RT_FINISH)
			return (0);
		else if (state == PARSE_RT_LINE)
			state = parse_rt_line(mlx, c);
		else if (state == PARSE_RT_SPACE)
			state = parse_rt_space(mlx, c);
		else
			state = parse_rt_default(mlx, c, state);
	}
	if (check_last(mlx, state, c))
		return (1);
	return (0);
}
