/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:29:14 by min-jo            #+#    #+#             */
/*   Updated: 2022/10/30 21:43:15 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "mlx_init.h"

typedef enum e_prase
{
	PARSE_ARG_ERROR,
	PARSE_ARG_FINISH,
	PARSE_ARG_SPACE,
	PARSE_ARG_NUM,

	PARSE_RT_CHAR,
	PARSE_RT_FLAOT,
	PARSE_RT_VECTOR,
	PARSE_RT_COLOR,
}	t_parse;

/*
* parse_arg.c
*/
t_parse	parse_arg_space(char c, int *num);
t_parse	parse_arg_num(char c, int *num);
int		parse_arg(char *str, int *num);

/*
* parse_rt.c
*/
int	parse_rt(t_mlx *mlx, char *rtfile_str);

#endif
