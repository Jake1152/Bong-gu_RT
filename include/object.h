/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:57:09 by min-jo            #+#    #+#             */
/*   Updated: 2022/10/29 20:34:41 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "vector.h"
# include "light.h"

typedef struct s_sphere
{
	t_vec	position;
	float	diameter;
	t_color	color;
}	t_sphere;

typedef struct s_plane
{
	t_vec	position;
	t_vec	orient;
	t_color	color;
}	t_plane;

typedef struct s_cylinder
{
	t_vec	position;
	t_vec	orient;
	float	diameter;
	float	height;
	t_color	color;
}	t_cylinder;

typedef enum s_obejct_type
{
	TYPE_SPHERE,
	TYPE_PLANE,
	TYPE_CYLINDER,
	TYPE_LIGHT_SPOT,
}	t_object_type;

typedef struct s_node
{
	void			*content;
	t_object_type	type;
	struct s_node	*pre;
	struct s_node	*next;
}	t_node;

typedef struct s_list
{
	int		size;
	t_node	head;
	t_node	tail;
}	t_list;

void	init_ist(t_list *list);
int		append_node(t_list *list, void *content);
void	clear_list(t_list *list);

#endif
