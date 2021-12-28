//
// Created by tandao on 12/27/21.
//

#ifndef RAY_TRACER_INTERACTION_H
#define RAY_TRACER_INTERACTION_H

#include "Vec3.h"

struct Interaction {
    Vec3 normal;
    Point3 p;
    double t;
};

#endif //RAY_TRACER_INTERACTION_H
