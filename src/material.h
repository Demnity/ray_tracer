//
// Created by tandao on 12/31/21.
//

#ifndef RAY_TRACER_MATERIAL_H
#define RAY_TRACER_MATERIAL_H

#include "ray.h"

struct Interaction; //forward declaration due to circular dependency

class Material {
public:
    virtual bool scatter(const Ray &wo, Ray &wi, const Interaction &isect, Color &albedo) const = 0;
};

#endif //RAY_TRACER_MATERIAL_H
