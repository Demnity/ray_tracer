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



// Common Headers
#include "Ray.h"
#include "Vec3.h"

#endif //RAY_TRACER_UTILITY_H
