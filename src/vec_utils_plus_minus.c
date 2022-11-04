#include "utils.h"
// 벡터합
t_vec      vplus(t_vec vec, t_vec vec2)
{
    vec.x += vec2.x;
    vec.y += vec2.y;
    vec.z += vec2.z;
    return (vec);
}

// 벡터합2
t_vec      vplus_(t_vec vec, float x, float y, float z)
{
    vec.x += x;
    vec.y += y;
    vec.z += z;
    return (vec);
}

// 벡터차
t_vec      vsub(t_vec vec, t_vec vec2)
{
    vec.x -= vec2.x;
    vec.y -= vec2.y;
    vec.z -= vec2.z;
    return (vec);
}

t_vec      vsub_(t_vec vec, float x, float y, float z)
{
    vec.x -= x;
    vec.y -= y;
    vec.z -= z;
    return (vec);
}
