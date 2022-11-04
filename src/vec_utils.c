#include "utils.h"
#include "vector.h"

//벡터3 생성자
t_vec      vec(float x, float y, float z)
{
    t_vec vec;

    vec.x = x;
    vec.y = y;
    vec.z = z;
    return (vec);
}

//포인트3 생성자
t_vec    point(float x, float y, float z)
{
    t_vec point;

    point.x = x;
    point.y = y;
    point.z = z;
    return (point);
}

//색상3 생성자
t_vec    color(float r, float g, float b)
{
    t_vec color;

    color.x = r;
    color.y = g;
    color.z = b;
    return (color);
}

// 벡터 값 설정
void        vset(t_vec *vec, float x, float y, float z)
{
    vec->x = x;
    vec->y = y;
    vec->z = z;
}
