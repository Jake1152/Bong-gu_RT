/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:29:12 by min-jo            #+#    #+#             */
/*   Updated: 2022/10/30 21:58:21 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "mlx_init.h"

t_parse	parse_arg_space(char c, int *num)
{
	if ('0' <= c && c <= '9')
	{
		*num += *num * 10 + c - '0';
		return (PARSE_ARG_NUM);
	}
	else if (c == ' ' || c == '\t')
		return (PARSE_ARG_SPACE);
	else
		return (PARSE_ARG_ERROR);
}

t_parse	parse_arg_num(char c, int *num)
{
	if ('0' <= c && c <= '9')
	{
		*num += *num * 10 + c - '0';
		return (PARSE_ARG_NUM);
	}
	else if (c == ' ' || c == '\t')
		return (PARSE_ARG_FINISH);
	else
		return (PARSE_ARG_ERROR);
}

int	parse_arg(char *str, int *num)
{
	t_parse	state;

	*num = 0;
	state = PARSE_ARG_SPACE;
	while (*str)
	{
		if (state == PARSE_ARG_ERROR)
			return (-1);
		else if (state == PARSE_ARG_FINISH)
			return (0);
		else if (state == PARSE_ARG_SPACE)
			state = parse_arg_space(*str, num);
		else if (state == PARSE_ARG_NUM)
			state = parse_arg_num(*str, num);
		++str;
	}
	return (0);
}
