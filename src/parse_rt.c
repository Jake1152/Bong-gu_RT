/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:29:12 by min-jo            #+#    #+#             */
/*   Updated: 2022/10/30 23:45:27 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "parse.h"
#include "mlx_init.h"

t_parse	get_object_state(char c)
{
	if (c == 'A')
		return (PARSE_RT_AMBIENT_SPACE);
	else if (c == 'C')
		return (PARSE_RT_CAMERA);
	else if (c == 'L' || c == 'l')
		return (PARSE_RT_LIGHT);
	else if (c == 's')
		return (PARSE_RT_SPHERE);
	else if (c == 'p')
		return (PARSE_RT_PLANE);
	else if (c == 'c')
		return (PARSE_RT_CYLINDER);
	return (PARSE_RT_ERROR);
}

t_parse	parse_rt_line(char c)
{
	if (c == '\n')
		return (PARSE_RT_LINE);
	else if (c == ' ')
		return (PARSE_RT_SPACE);
	else
		return (get_object_state(c));
}

t_parse	parse_rt_space(char c)
{
	if (c == ' ')
		return (PARSE_RT_SPACE);
	else
		return (get_object_state(c));
}

t_parse	parse_rt_default(t_mlx *mlx, char c, t_parse state)
{
	if (state == PARSE_RT_AMBIENT_SPACE || state == PARSE_RT_AMBIENT_NUM
		|| state == PARSE_RT_AMBIENT_FLOAT || state == PARSE_RT_AMBIENT_COLOR
		|| state == PARSE_RT_AMBIENT_R || state == PARSE_RT_AMBIENT_G
		|| state == PARSE_RT_AMBIENT_B)
		return (parse_rt_ambient(mlx, c, state));
	else if (state == PARSE_RT_CAMERA)
		return (parse_rt_camera(mlx, c, state));
	else if (state == PARSE_RT_LIGHT)
		return (parse_rt_light(mlx, c, state));
	else if (state == PARSE_RT_SPHERE)
		return (parse_rt_sphere(mlx, c, state));
	else if (state == PARSE_RT_PLANE)
		return (parse_rt_plane(mlx, c, state));
	else if (state == PARSE_RT_CYLINDER)
		return (parse_rt_cylinder(mlx, c, state));
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
			state = parse_rt_line(c);
		else if (state == PARSE_RT_SPACE)
			state = parse_rt_space(c);
		else
			state = parse_rt_default(mlx, c, state);
	}
	return (0);
}
