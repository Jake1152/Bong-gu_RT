/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 19:35:35 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/04 01:51:49 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORM_H
# define TRANSFORM_H

# include "mlx_init.h"
# include "vector.h"
# include "matrix.h"

int		transform_pos(void	*content, t_object_type type, t_mat view);
int		transform_pos_ori(void	*content, t_object_type type, t_mat view);
int		transform_list(t_list *list, t_mat view);
void	copy_transform(t_mlx *mlx);

#endif
