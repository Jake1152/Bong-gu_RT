/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 06:54:43 by jim               #+#    #+#             */
/*   Updated: 2022/11/04 13:39:05 by jim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "ray.h"
#include "vector.h"

/*
- sphere
- radius
- radius_sqaure

- copy list에 정보가 있다는 전제하에 진행

- 원부터 그려본다.


sphere를 그리기 위해 필요한것은 무엇인가?

- viewport 위의 점에 색상을 칠해준다.
어떻게 칠 할것인가?

- object인지 확인
    object의 충돌하는 지점이 있는가?
- object가 아니면 배경색을 입힌다.

object는 t_node 안에 있다.
*/

t_bool      hit_sphere(t_node *sp_obj, t_ray *ray, t_hit_record *rec)
{
    (void)sp_obj;
    (void)ray;
    (void)rec;
    // t_vec  oc; //방향벡터로 나타낸 구의 중심.
    // t_equation_info equation_info;
    // t_sphere  *sp;

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
    // sp = (t_sphere *)sp_obj;
    // oc = vsub(ray->orig, sp->pos);
    // equation_info.a = vlength_sqaure(ray->dir);
    // equation_info.half_b = vdot(oc, ray->dir);
    // equation_info.c = vlength_sqaure(oc) - sp->dia_squre;
    // // discriminant 는 판별식
    // equation_info.discriminant = equation_info.half_b \
    //                             * equation_info.half_b \
    //                             - equation_info.a * equation_info.c;
    // if (equation_info.discriminant < 0)
    //     return (FALSE);
    // equation_info.sqrtd = sqrt(equation_info.discriminant);
    // equation_info.root = (-equation_info.half_b \
    //                             - equation_info.sqrtd
    //                         ) \
    //                             / equation_info.a;
    // if (equation_info.root < rec->tmin || rec->tmax < equation_info.root)
    // {
    //     equation_info.root = (-equation_info.half_b + equation_info.sqrtd) \
    //                             / equation_info.a;
    //     if (equation_info.root < rec->tmin || rec->tmax < equation_info.root)
    //         return (FALSE);
    // }
    // rec->t = equation_info.root;
    // rec->point = ray_at(ray, equation_info.root);
    // rec->normal = vdivide(vsub(rec->point, sp->pos), sp->dia);
    // set_face_normal(ray, rec);
    // rec->albedo = sp_obj->albedo;
    return (TRUE);
}

