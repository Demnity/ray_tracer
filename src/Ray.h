//
// Created by tandao on 12/27/21.
//

#ifndef RAY_TRACER_RAY_H
#define RAY_TRACER_RAY_H

#include "Vec3.h"

class Ray {
public:
    Point3 origin;
    Vec3 direction;

public:
    Ray(const Point3 &origin, const Vec3 &direction) : origin(origin), direction(direction) {}

    Point3 o() const {return origin;}

    Vec3 d() const {return direction;}

    Point3 at(double t) const {
        return origin + t * direction;
    }
};

#endif //RAY_TRACER_RAY_H
