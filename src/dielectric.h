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
    albedo = Color(1., 1., 1.); //NOTE: this material will always refract
    double ior = isect.front_face ? 1 / eta : eta;
    Vec3 refracted_dir = refract(unit(wo.d()), isect.normal, ior); //requires the direction to be normalized
    wi = Ray(isect.p, refracted_dir);
    return true;
}

#endif //RAY_TRACER_DIELECTRIC_H
