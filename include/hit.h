#ifndef HIT_H
# define HIT_H

#include "object.h"
#include "ray.h"

t_bool      hit(t_list *world, t_ray *ray, t_hit_record *rec);
t_bool      hit_obj(t_node *object, t_ray *ray, t_hit_record *rec);

t_bool      hit_sphere(t_node *sp_obj, t_ray *ray, t_hit_record *rec);

#endif