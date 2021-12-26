//
// Created by tandao on 12/26/21.
//

#ifndef RAY_TRACER_VEC3_H
#define RAY_TRACER_VEC3_H

#include <cmath>
#include <iostream>

class vec3 {
public:
    vec3() : e{0, 0, 0} {}
    vec3(double e1, double e2, double e3) : e{e1, e2, e3} {}

    double x() {return e[0];}
    double y() {return e[1];}
    double z() {return e[2];}

    vec3 operator+=(const vec3 &v) {
        e[0] += v.e[0];
        e[1] += v.e[1];
        e[2] += v.e[2];
        return *this;
    }

    vec3 operator-=(const vec3 &v) {
        e[0] -= v.e[0];
        e[1] -= v.e[1];
        e[2] -= v.e[2];
        return *this;
    }

    vec3 operator*=(const double &v) {
        e[0] *= v;
        e[1] *= v;
        e[2] *= v;
        return *this;
    }

    vec3 operator/=(const double &v) {
        e[0] /= v;
        e[1] /= v;
        e[2] /= v;
        return *this;
    }

    vec3 operator-() const {
        return vec3(-e[0], -e[1], -e[2]);
    }

    double& operator[](int index) {
        return e[index];
    }

    double operator[](int index) const {
        return e[index];
    }

    double length_squared() {
        return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
    }

    double length() {
        return sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]);
    }
public:
    double e[3];
};

using point3 = vec3;
using color = vec3;
#endif //RAY_TRACER_VEC3_H
