#include "utils.h"

// 벡터 * 스칼라 곱연산
t_vec      vmult(t_vec vec, float t)
{
    vec.x *= t;
    vec.y *= t;
    vec.z *= t;
    return (vec);
}

// 벡터 축 값끼리 곱연산
t_vec      vmult_(t_vec vec, t_vec vec2)
{
    vec.x *= vec2.x;
    vec.y *= vec2.y;
    vec.z *= vec2.z;
    return (vec);
}

// 벡터 스칼라 나누기
t_vec      vdivide(t_vec vec, float t)
{
    vec.x *= 1 / t;
    vec.y *= 1 / t;
    vec.z *= 1 / t;

    return vec;
}