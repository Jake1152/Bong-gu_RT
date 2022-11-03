/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rt_pla7.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 22:04:27 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/03 23:18:12 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_init.h"
#include "parse.h"
#include "object.h"

t_parse	parse_rt_pla_char(char c)
{
	if (c == 'l')
		return (PARSE_RT_PLA_SPACE);
	else
		return (PARSE_RT_ERROR);
}
