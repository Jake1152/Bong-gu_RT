/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 06:54:43 by jim               #+#    #+#             */
/*   Updated: 2022/11/04 16:47:13 by jim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "object.h"
#include "ray.h"
#include "vector.h"
#include "utils.h"

t_bool      hit_plane(t_node *sp_obj, t_ray *ray, t_hit_record *rec)
{
    // (void)sp_obj;
    // (void)ray;
    // (void)rec;
    t_vec  oc; //방향벡터로 나타낸 구의 중심.
    t_equation_info equation_info;
    t_plane  *pl;
    /*
    it's in the t_equation_info
    double  a;
    double  half_b;
    double  c;
    double  discriminant; //판별식
    double  sqrtd;
    double  root;
    t_node  *sp;
    */
    pl = (t_plane *)sp_obj;
    oc = vsub(ray->orig, pl->pos);
    equation_info.a = vlength_sqaure(ray->dir);
    equation_info.half_b = vdot(oc, ray->dir);
    equation_info.c = vlength_sqaure(oc) - pl->dia_squre;
    // discriminant 는 판별식
    equation_info.discriminant = equation_info.half_b \
                                * equation_info.half_b \
                                - equation_info.a * equation_info.c;
    if (equation_info.discriminant < 0)
        return (FALSE);
    equation_info.sqrtd = sqrt(equation_info.discriminant);
    equation_info.root = (-equation_info.half_b \
                                - equation_info.sqrtd
                            ) \
                                / equation_info.a;
    if (equation_info.root < rec->tmin || rec->tmax < equation_info.root)
    {
        equation_info.root = (-equation_info.half_b + equation_info.sqrtd) \
                                / equation_info.a;
        if (equation_info.root < rec->tmin || rec->tmax < equation_info.root)
            return (FALSE);
    }
    rec->t = equation_info.root;
    rec->point = ray_at(ray, equation_info.root);
    rec->normal = vdivide(vsub(rec->point, pl->pos), sp->dia);
    // set_face_normal(ray, rec);
    // rec->albedo = sp_obj->albedo;
    return (TRUE);
}

