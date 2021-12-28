//
// Created by tandao on 12/27/21.
//

#ifndef RAY_TRACER_SPHERE_H
#define RAY_TRACER_SPHERE_H

#include "Shape.h"

class Sphere : public Shape {
public:
    Sphere() {}
    Sphere(Point3 center, double radius) : center(center), radius(radius) {}

public:
    Point3 center;
    double radius;
};

#endif //RAY_TRACER_SPHERE_H
