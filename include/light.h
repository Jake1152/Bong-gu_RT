/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 16:02:47 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/03 17:21:30 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "vector.h"

typedef struct s_light_ambient
{
	float	bri;
	t_color	col;
}	t_light_ambient;

typedef struct s_light_spot
{
	t_vec	pos;
	float	bri;
	t_color	col;
}	t_light_spot;

#endif
