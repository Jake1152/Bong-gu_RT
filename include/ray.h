#ifndef RAY_H
# define RAY_H

# include "vector.h"

typedef struct s_ray
{
	t_vec   orig;
    t_vec   dir;
}       	t_ray;

t_vec   ray_at(t_ray *ray, double t);

#endif