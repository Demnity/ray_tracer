//
// Created by tandao on 12/31/21.
//

#ifndef RAY_TRACER_DIELECTRIC_H
#define RAY_TRACER_DIELECTRIC_H

#include "material.h"
#include "interaction.h"

class Dielectric : public Material {
public:
    double eta;
public:
    Dielectric(double eta) : eta(eta) {}
    bool scatter(const Ray &wo, Ray &wi, const Interaction &isect, Color &albedo) const override;
};

bool Dielectric::scatter(const Ray &wo, Ray &wi, const Interaction &isect, Color &albedo) const {
    albedo = Color(1., 1., 1.); //NOTE: meaning this material will never absorb light, should rename it to another appropriate variable naem

    //invert eta depending on where the ray is inside the object or not
    double ior = isect.front_face ? 1 / eta : eta;

    Vec3 unit_dir = unit(wo.d());
    double cos_theta = dot(wo.d(), isect.normal);
    double sin_theta = sqrt(1 - cos_theta * cos_theta);
    Vec3 out_dir;

    //if the ray angle with the normal is larger than the critical angle
    if(ior * sin_theta > 1.) {
        //Reflection
        out_dir = reflect(unit_dir, isect.normal);
    } else {
        //Refraction
        out_dir = refract(unit_dir, isect.normal, ior); //requires the direction to be normalized
    }

    wi = Ray(isect.p, out_dir);
    
    return true;
}

#endif //RAY_TRACER_DIELECTRIC_H
