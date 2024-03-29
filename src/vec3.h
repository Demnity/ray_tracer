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

    //returns true if all elements are close to 0
    bool near_zero() const {
        const double s = 1e-8;
        return (fabs(e[0]) < s) && (fabs(e[1]) < s) && (fabs(e[2]) < s);
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

Vec3 reflect(const Vec3 &v, const Vec3 &normal) {
    return v - 2 * dot(v, normal) * normal;
}

//TODO: will look into this formula later on
Vec3 refract(const Vec3& uv, const Vec3& n, double etai_over_etat) {
    auto cos_theta = fmin(dot(-uv, n), 1.0);
    Vec3 r_out_perp =  etai_over_etat * (uv + cos_theta*n);
    Vec3 r_out_parallel = -sqrt(fabs(1.0 - r_out_perp.length_squared())) * n;
    return r_out_perp + r_out_parallel;
}

//aliases
using Point3 = Vec3;
using Color = Vec3;
#endif //RAY_TRACER_VEC3_H
