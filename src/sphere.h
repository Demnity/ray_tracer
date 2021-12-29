//
// Created by tandao on 12/27/21.
//

#ifndef RAY_TRACER_SPHERE_H
#define RAY_TRACER_SPHERE_H

#include "shape.h"

class Sphere : public Shape {
public:
    Point3 center;
    double radius;

public:
    Sphere() {}
    Sphere(Point3 center, double radius) : center(center), radius(radius) {}

    bool intersect(const Ray &ray, double t_min, double t_max, Interaction &isect) const override;
};

bool Sphere::intersect(const Ray &ray, double t_min, double t_max, Interaction &isect) const {
    Vec3 ray_o_to_center = ray.o() - center;

    //formula calculation ax^2 + bx + c = d
    double a = dot(ray.d(), ray.d());
    double b = dot(ray.d(), ray_o_to_center);
    double c = dot(ray_o_to_center, ray_o_to_center) - radius * radius;
    double delta = b * b - a * c;

    //no intersection
    if(delta < 0) return false;
    double t = (-b - sqrt(delta)) / a;

    //check if t is in acceptable range
    if(t < t_min || t > t_max) {
        t = (-b + sqrt(delta)) / a;
        if(t < t_min || t > t_max) return false;
    }

    //recording intersection info

    isect.set_face_normal(ray, (ray.at(t) - center) / radius);
    isect.p = ray.at(t);
    isect.t = t;

    return true;
}


#endif //RAY_TRACER_SPHERE_H
