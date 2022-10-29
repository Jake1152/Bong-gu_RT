#ifndef KMUCS_GRAPHICS_TRANSFORM_HPP
#define KMUCS_GRAPHICS_TRANSFORM_HPP

#include <cmath>
#include "vec.hpp"
#include "mat.hpp"
#include "operator.hpp"

namespace kmuvcl
{
    namespace math
    {
#ifndef M_PI
        const float M_PI = 3.14159265358979323846f;
#endif
        template <unsigned int N, typename T>
        vec<N, T> normalize(const vec<N, T>& other)
        {
            vec<N, T> result;
            T sum = 0;
            for(unsigned int i=0;i<N;i++)
            {
                sum += other(i)*other(i);
            }
            sum = sqrt(sum);
            for(unsigned int i=0;i<N;i++)
            {
                result(i) = other(i) / sum;
            }
            return result;
        }

        template <typename T>
        mat<4, 4, T> translate(T dx, T dy, T dz)
        {
            mat<4, 4, T> translateMat;
            // TODO: Fill up this function properly
            translateMat(0,0) = 1;
            translateMat(1,1) = 1;
            translateMat(2,2) = 1;
            translateMat(3,3) = 1;
            translateMat(0,3) = dx;
            translateMat(1,3) = dy;
            translateMat(2,3) = dz;
            return translateMat;
        }

        template <typename T>
        mat<4, 4, T> rotate(T angle, T x, T y, T z)
        {
            mat<4, 4, T> rotateMat;
            // TODO: Fill up this function properly
            vec<3, T> u(x,y,z);
            u = normalize(u);

            T cos_angle = cos(angle * M_PI / 180.0);
            T sin_angle = sin(angle * M_PI / 180.0);

            rotateMat(0,0) = cos_angle + u(0)*u(0)*(1-cos_angle);
            rotateMat(0,1) = u(0)*u(1)*(1-cos_angle)-u(2)*sin_angle;
            rotateMat(0,2) = u(0)*u(2)*(1-cos_angle)+u(1)*sin_angle;
            rotateMat(1,0) = u(1)*u(0)*(1-cos_angle)+u(2)*sin_angle;
            rotateMat(1,1) = cos_angle+u(1)*u(1)*(1-cos_angle);
            rotateMat(1,2) = u(1)*u(2)*(1-cos_angle)-u(0)*sin_angle;
            rotateMat(2,0) = u(2)*u(0)*(1-cos_angle)-u(1)*sin_angle;
            rotateMat(2,1) = u(2)*u(1)*(1-cos_angle)+u(0)*sin_angle;
            rotateMat(2,2) = cos_angle+u(2)*u(2)*(1-cos_angle);
            rotateMat(3,3) = 1;
            return rotateMat;
        }

        template<typename T>
        mat<4, 4, T> scale(T sx, T sy, T sz)
        {
            mat<4, 4, T> scaleMat;
            // TODO: Fill up this function properly
            scaleMat.set_to_zero();
            scaleMat(0,0) = sx;
            scaleMat(1,1) = sy;
            scaleMat(2,2) = sz;
            scaleMat(3,3) = 1;
            return scaleMat;
        }

        template<typename T>
        mat<4, 4, T> lookAt(T eyeX, T eyeY, T eyeZ, T centerX, T centerY, T centerZ, T upX, T upY, T upZ)
        {
            // TODO: Fill up this function properly
            vec<3, T> cam_pos(eyeX, eyeY, eyeZ);
            vec<3, T> center(centerX, centerY, centerZ);
            vec<3, T> cam_z_axis = cam_pos - center;
            cam_z_axis = normalize(cam_z_axis);

            vec<3, T> up(upX, upY, upZ);
            vec<3, T> cam_x_axis = cross(up, cam_z_axis);
            cam_x_axis = normalize(cam_x_axis);

            vec<3, T> cam_y_axis = cross(cam_z_axis, cam_x_axis);
            cam_y_axis = normalize(cam_y_axis);

            mat<4, 4, T> axisMat, posMat;

            axisMat(0,0) = cam_x_axis(0);
            axisMat(0,1) = cam_x_axis(1);
            axisMat(0,2) = cam_x_axis(2);
            axisMat(1,0) = cam_y_axis(0);
            axisMat(1,1) = cam_y_axis(1);
            axisMat(1,2) = cam_y_axis(2);
            axisMat(2,0) = cam_z_axis(0);
            axisMat(2,1) = cam_z_axis(1);
            axisMat(2,2) = cam_z_axis(2);
            axisMat(3,3) = 1;

            posMat(0,0) = 1;
            posMat(1,1) = 1;
            posMat(2,2) = 1;
            posMat(0,3) = -cam_pos(0);
            posMat(1,3) = -cam_pos(1);
            posMat(2,3) = -cam_pos(2);
            posMat(3,3) = 1;

            mat<4, 4, T> viewMat = axisMat * posMat;
            return viewMat;
        }

        template<typename T>
        mat<4, 4, T> ortho(T left, T right, T bottom, T top, T nearVal, T farVal)
        {
            mat<4, 4, T> orthoMat;
            // TODO: Fill up this function properly
            orthoMat(0,0) = 2/(right-left);
            orthoMat(1,1) = 2/(top-bottom);
            orthoMat(2,2) = -2/(farVal-nearVal);
            orthoMat(0,3) = -(right+left)/(right-left);
            orthoMat(1,3) = -(top+bottom)/(top-bottom);
            orthoMat(2,3) = -(farVal+nearVal)/(farVal-nearVal);
            orthoMat(3,3) = 1;
            return orthoMat;
        }

        template<typename T>
        mat<4, 4, T> frustum(T left, T right, T bottom, T top, T nearVal, T farVal)
        {
           mat<4, 4, T> frustumMat;
           // TODO: Fill up this function properly
           frustumMat(0,0) = 2*nearVal/(right-left);
           frustumMat(1,1) = 2*nearVal/(top-bottom);

           frustumMat(0,2) = (right+left)/(right-left);
           frustumMat(1,2) = (top+bottom)/(top-bottom);
           frustumMat(2,2) = -(farVal+nearVal)/(farVal-nearVal);
           frustumMat(2,3) = 2*farVal*nearVal/(farVal-nearVal);
           frustumMat(3,2) = -1;

           return frustumMat;
        }

        template<typename T>
        mat<4, 4, T> perspective(T fovy, T aspect, T zNear, T zFar)
        {
          // TODO: Fill up this function properly
          T  top = tan(fovy/2 * M_PI / 180.0) * zNear;
          T  right = top / aspect;

          return frustum(-right, right, -top, top, zNear, zFar);
        }
    }
}
#endif
