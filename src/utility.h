//
// Created by tandao on 12/28/21.
//

#ifndef RAY_TRACER_UTILITY_H
#define RAY_TRACER_UTILITY_H

#include <cmath>
#include <limits>
#include <memory>

using std::shared_ptr;
using std::make_shared;

//constants
const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// Utility Functions
inline double degrees_to_radians(double degrees) {
    return degrees * pi / 180.0;
}

// Common Headers
#include "Ray.h"
#include "Vec3.h"

#endif //RAY_TRACER_UTILITY_H
