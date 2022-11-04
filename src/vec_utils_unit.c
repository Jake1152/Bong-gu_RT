#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

// 단위 벡터
t_vec      vunit(t_vec vec)
{
    float len = vlength(vec);
    if (len == 0)
    {
        printf("Error\n:Devider is 0");
        exit(0);
    }
    vec.x /= len;
    vec.y /= len;
    vec.z /= len;
    return (vec);
}

// 두 벡터의 원소를 비교하여 작은 값들만 반환
t_vec  vmin(t_vec vec1, t_vec vec2)
{
    if (vec1.x > vec2.x)
        vec1.x = vec2.x;
    if (vec1.y > vec2.y)
        vec1.y = vec2.y;
    if (vec1.z > vec2.z)
        vec1.z = vec2.z;
    return (vec1);
}
