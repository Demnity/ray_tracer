//
// Created by tandao on 12/27/21.
//

#ifndef RAY_TRACER_SHAPE_H
#define RAY_TRACER_SHAPE_H

#include "Interaction.h"
#include "Ray.h"

class Shape {
public:
    virtual bool intersect(const Ray &ray, double t_min, double t_max, Interaction &isect) const = 0;
};
#endif //RAY_TRACER_SHAPE_H
