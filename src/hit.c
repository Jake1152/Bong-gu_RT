#include "object.h"
#include "ray.h"
#include <math.h>

t_bool      hit(t_list *world, t_ray *ray, t_hit_record *rec)
{
    t_bool          hit_anything;
    t_hit_record    temp_rec;
    t_node          *object_node;

    temp_rec = *rec;
    hit_anything = FALSE;
    object_node = &(world->head);
    while(object_node)
    {
        if (hit_obj(world, ray, &temp_rec))
        {
            hit_anything = TRUE;
            temp_rec.tmax = temp_rec.t;
            *rec = temp_rec;
        }
        object_node = object_node->next;
    }
    return (hit_anything);
}

// hit_obj는 오브젝트 타입에 맞는 hit함수로 연결해주는 관문
t_bool      hit_obj(t_node *object, t_ray *ray, t_hit_record *rec)
{
    t_bool  hit_result;

    hit_result = FALSE;
    if (object->type == TYPE_SPHERE)
        hit_result = hit_sphere(object, ray, rec);
    return (hit_result);
}
