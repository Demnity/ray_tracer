//
// Created by tandao on 12/26/21.
//

#ifndef RAY_TRACER_VEC3_H
#define RAY_TRACER_VEC3_H

#include <cmath>
#include <iostream>

//3D vector
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

inline std::ostream& operator<<(std::ostream& out, const vec3& v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

inline vec3 operator+(const vec3 &v1, const vec3 &v2) {
    return vec3(v1.e[0] + v2.e[0], v1.e[1] + v2.e[1], v1.e[2] + v2.e[2]);
}

inline vec3 operator-(const vec3 &v1, const vec3 &v2) {
    return vec3(v1.e[0] - v2.e[0], v1.e[1] - v2.e[1], v1.e[2] - v2.e[2]);
}

inline vec3 operator*(const vec3 &v1, const vec3 &v2) {
    return vec3(v1.e[0] * v2.e[0], v1.e[1] * v2.e[1], v1.e[2] * v2.e[2]);
}

inline vec3 operator*(const vec3 &v, double t) {
    return vec3(v.e[0] * t, v.e[1] * t, v.e[2] * t);
}

inline vec3 operator*(double t, const vec3 &v) {
    return v * t;
}

inline vec3 operator/(const vec3 &v, double t) {
    return v * 1 / t;
}

inline double dot(const vec3 &v1, const vec3 &v2) {
    return v1.e[0] * v2.e[0] + v1.e[1] * v2.e[1] + v1.e[2] * v2.e[2];
}

inline vec3 cross(const vec3 &v1, const vec3 &v2) {
    return vec3(v1.e[1] * v2.e[2] - v1.e[2] * v2.e[1],
                v1.e[2] * v2.e[0] - v1.e[0] * v2.e[2],
                v1.e[0] * v2.e[1] - v1.e[1] * v2.e[0]);
}

inline vec3 unit(vec3 v) {
    return v / v.length();
}

//aliases
using point3 = vec3;
using color = vec3;
#endif //RAY_TRACER_VEC3_H
