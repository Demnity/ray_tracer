//
// Created by tandao on 12/28/21.
//

#ifndef RAY_TRACER_UTILITY_H
#define RAY_TRACER_UTILITY_H

#include <cmath>
#include <limits>
#include <memory>
#include <random>

using std::shared_ptr;
using std::make_shared;
using std::random_device;
using std::mt19937;
using std::uniform_real_distribution;

//constants
const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

//random number generator C++11 standard


// Utility Functions
inline double degrees_to_radians(double degrees) {
    return degrees * pi / 180.0;
}

inline double rand_num() {
    static random_device rd;
    static mt19937 mt(rd());
    static uniform_real_distribution<double> dist(0., 1.);
    return dist(mt);
}

inline double rand_num(double min, double max) {
    return min + (max - min) * rand_num();
}

inline Vec3 rand_vec3() {
    return Vec3(rand_num(), rand_num(), rand_num());
}

inline Vec3 rand_vec3(double min, double max) {
    //return min + (max - min) * rand_vec3();
    return Vec3(rand_num(min, max), rand_num(min, max), rand_num(min, max));
}

Vec3 rand_in_unit_sphere() {
    while (true) {
        auto p = rand_vec3(-1,1);
        if (p.length_squared() >= 1) continue;
        return p;
    }
}

inline double clamp(double x, double min, double max) {
    if(x < min) return min;
    if(x > max) return max;
    return x;
}



// Common Headers
#include "ray.h"
#include "vec3.h"

#endif //RAY_TRACER_UTILITY_H
