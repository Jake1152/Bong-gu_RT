/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 16:02:47 by min-jo            #+#    #+#             */
/*   Updated: 2022/10/23 19:20:41 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "vector.h"

typedef struct s_light_spot
{
	t_vec	position;
	float	bright;
	t_color	color;
}	t_light_spot;

#endif
