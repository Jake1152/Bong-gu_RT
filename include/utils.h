#ifndef UTILS_H
# define UTILS_H


#include "utils.h"
#include "vector.h"

t_vec   vec(float x, float y, float z);
t_vec   point(float x, float y, float z);
t_vec   color(float r, float g, float b);
void    vset(t_vec *vec, float x, float y, float z);

float   vlength_sqaure(t_vec vec);
float   vlength(t_vec vec);

t_vec   vplus(t_vec vec, t_vec vec2);
t_vec   vplus_(t_vec vec, float x, float y, float z);
t_vec   vsub(t_vec vec, t_vec vec2);
t_vec   vsub_(t_vec vec, float x, float y, float z);

t_vec   vmult(t_vec vec, float t);
t_vec   vmult_(t_vec vec, t_vec vec2);
t_vec   vdivide(t_vec vec, float t);

float   vdot(t_vec vec, t_vec vec2);
t_vec   vcross(t_vec vec, t_vec vec2);

t_vec   vunit(t_vec vec);
t_vec   vmin(t_vec vec1, t_vec vec2);

#endif