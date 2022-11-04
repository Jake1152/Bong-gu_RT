/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 19:35:35 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/05 07:24:16 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORM_H
# define TRANSFORM_H

# include "mlx_init.h"
# include "vector.h"
# include "matrix.h"

void	transform_pos(void	*content, t_object_type type, t_mat view);
void	transform_pos_ori(void	*content, t_object_type type, t_mat view);
void	transform_list(t_list *list, t_mat view);
void	copy_transform(t_mlx *mlx);

#endif
