//
// Created by tandao on 12/26/21.
//

#ifndef RAY_TRACER_VEC3_H
#define RAY_TRACER_VEC3_H

#include <cmath>
#include <iostream>

//3D vector
class Vec3 {
public:
    double e[3];

public:
    Vec3() : e{0, 0, 0} {}
    Vec3(double e1, double e2, double e3) : e{e1, e2, e3} {}

    double x() {return e[0];}
    double y() {return e[1];}
    double z() {return e[2];}

    Vec3 operator+=(const Vec3 &v) {
        e[0] += v.e[0];
        e[1] += v.e[1];
        e[2] += v.e[2];
        return *this;
    }

    Vec3 operator-=(const Vec3 &v) {
        e[0] -= v.e[0];
        e[1] -= v.e[1];
        e[2] -= v.e[2];
        return *this;
    }

    Vec3 operator*=(const double &v) {
        e[0] *= v;
        e[1] *= v;
        e[2] *= v;
        return *this;
    }

    Vec3 operator/=(const double &v) {
        e[0] /= v;
        e[1] /= v;
        e[2] /= v;
        return *this;
    }

    Vec3 operator-() const {
        return Vec3(-e[0], -e[1], -e[2]);
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
};

inline std::ostream& operator<<(std::ostream& out, const Vec3& v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

inline Vec3 operator+(const Vec3 &v1, const Vec3 &v2) {
    return Vec3(v1.e[0] + v2.e[0], v1.e[1] + v2.e[1], v1.e[2] + v2.e[2]);
}

inline Vec3 operator+(double t, const Vec3 &v) {
    return Vec3(v.e[0] + t, v.e[1] + t, v.e[2] + t);
}

inline Vec3 operator+(const Vec3 &v, double t) {
    return t + v;
}

inline Vec3 operator-(const Vec3 &v1, const Vec3 &v2) {
    return Vec3(v1.e[0] - v2.e[0], v1.e[1] - v2.e[1], v1.e[2] - v2.e[2]);
}

inline Vec3 operator*(const Vec3 &v1, const Vec3 &v2) {
    return Vec3(v1.e[0] * v2.e[0], v1.e[1] * v2.e[1], v1.e[2] * v2.e[2]);
}

inline Vec3 operator*(const Vec3 &v, double t) {
    return Vec3(v.e[0] * t, v.e[1] * t, v.e[2] * t);
}

inline Vec3 operator*(double t, const Vec3 &v) {
    return v * t;
}

inline Vec3 operator/(const Vec3 &v, double t) {
    return v * (1 / t);
}

inline double dot(const Vec3 &v1, const Vec3 &v2) {
    return v1.e[0] * v2.e[0] + v1.e[1] * v2.e[1] + v1.e[2] * v2.e[2];
}

inline Vec3 cross(const Vec3 &v1, const Vec3 &v2) {
    return Vec3(v1.e[1] * v2.e[2] - v1.e[2] * v2.e[1],
                v1.e[2] * v2.e[0] - v1.e[0] * v2.e[2],
                v1.e[0] * v2.e[1] - v1.e[1] * v2.e[0]);
}

inline Vec3 unit(Vec3 v) {
    return v / v.length();
}

//aliases
using Point3 = Vec3;
using Color = Vec3;
#endif //RAY_TRACER_VEC3_H
