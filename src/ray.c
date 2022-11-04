#include "ray.h"
#include "utils.h"

//ray origin point 부터 방향벡터 ray dir * t 만큼 떨어진 점.
t_vec   ray_at(t_ray *ray, double t)
{
    t_vec   at;

    at = vadd(ray->orig, vmult(ray->dir, t));
    return (at);
}
