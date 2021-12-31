//
// Created by tandao on 12/31/21.
//

#ifndef RAY_TRACER_METAL_H
#define RAY_TRACER_METAL_H

#include "material.h"
#include "interaction.h"
#include "vec3.h"

class Metal : public Material {
public:
    Color albedo;
    double roughness; //this is not realistic, should be using different reflectance model (e.g. GGX, Fresnel)

public:
    Metal(const Color &albedo, double roughness = 0) : albedo(albedo), roughness(roughness) {}
    bool scatter(const Ray &wo, Ray &wi, const Interaction &isect, Color &albedo) const override;
};

bool Metal::scatter(const Ray &wo, Ray &wi, const Interaction &isect, Color &albedo) const {
    Vec3 reflected = reflect(unit(wo.d()), isect.normal); //always normalize the normal before reflecting

    //return info
    wi = Ray(isect.p, reflected + roughness * rand_in_unit_sphere());
    albedo = this->albedo;

    return dot(reflected, isect.normal) > 0.;
}

#endif //RAY_TRACER_METAL_H
