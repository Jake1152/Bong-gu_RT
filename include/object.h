/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:57:09 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/06 05:14:50 by jim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "vector.h"
# include "light.h"

typedef struct s_sphere
{
	t_vec	pos;
	float	dia;
	t_color	col;
}	t_sphere;

typedef struct s_plane
{
	t_vec	pos;
	t_vec	ori;
	t_color	col;
}	t_plane;

typedef struct s_cylinder
{
	t_vec	pos;
	t_vec	ori;
	float	dia;
	float	hei;
	t_color	col;
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

void	init_list(t_list *list);
int		append_node(t_list *list, void *content, t_object_type type);
void	clear_list(t_list *list);
void	*copy_content(t_object_type type, void *content);
int		copy_list(t_list *dst, t_list *src);

void	*content_light_spot(void *content);
void	*content_sphere(void *content);
void	*content_plane(void *content);
void	*content_cylinder(void *content);

int		add_list_lig_ret_space(void *mlx);
int		add_list_shp_ret_char(void *mlx);
int		add_list_pla_ret_char(void *mlx);
int		add_list_cyl_ret_char(void *mlx);

#endif
