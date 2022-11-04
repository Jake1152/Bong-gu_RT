#include "utils.h"

// 벡터 길이 제곱
float      vlength_sqaure(t_vec vec)
{
    return (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

// 벡터 길이
float      vlength(t_vec vec)
{
    return (sqrt(vlength_sqaure(vec)));
}
