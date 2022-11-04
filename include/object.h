/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:57:09 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/04 12:50:35 by jim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "vector.h"
# include "light.h"

# define EPSILON 1e-6

typedef int	t_bool;

typedef enum e_bool
{
	FALSE,
	TRUE,
}			t_e_bool;

typedef struct s_sphere
{
	t_vec	pos;
	float	dia;
	float	dia_squre;
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

typedef struct s_hit_record
{
	t_vec		point;
	t_vec		normal;
	double		tmin;
	double		tmax;
	double		t;
	t_bool		front_face;
	t_vec		albedo;
}				t_hit_record;

typedef struct s_equation_info
{
    double  a;
    double  half_b;
    double  c;
    double  discriminant;
    double  sqrtd;
    double  root;
}				t_equation_info;


/*
* object.c
*/
void	init_list(t_list *list);
int		append_node(t_list *list, void *content);
void	clear_list(t_list *list);
void	*copy_content(t_object_type type, void *content);
int		copy_list(t_list *dst, t_list *src);

/*
* object3.c
*/
void	*content_light_spot(void* content);
void	*content_sphere(void* content);
void	*content_plane(void* content);
void	*content_cylinder(void* content);

/*
* object3.c
*/
int		add_list_lig_ret_space(void *mlx);
int		add_list_shp_ret_char(void *mlx);
int		add_list_pla_ret_char(void *mlx);
int		add_list_cyl_ret_char(void *mlx);

#endif
