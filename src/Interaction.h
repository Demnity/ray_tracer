//
// Created by tandao on 12/27/21.
//

#ifndef RAY_TRACER_INTERACTION_H
#define RAY_TRACER_INTERACTION_H

#include "Vec3.h"
#include "Ray.h"

struct Interaction {
    Vec3 normal;
    Point3 p;
    double t;
    bool front_face;

    inline void set_face_normal(const Ray &ray, const Vec3 &n) {
        front_face = dot(ray.d(), n) < 0.;
        normal = front_face ? n : -n;
    }
};

#endif //RAY_TRACER_INTERACTION_H
