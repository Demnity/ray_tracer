//
// Created by tandao on 12/31/21.
//

#ifndef RAY_TRACER_LAMBERTIAN_H
#define RAY_TRACER_LAMBERTIAN_H

#include "material.h"
#include "interaction.h"
#include "utility.h"

class Lambertian : public Material {
public:
    Color albedo;
public:
    Lambertian(const Color &albedo) : albedo(albedo) {}
    bool scatter(const Ray &wo, Ray &wi, const Interaction &isect, Color &albedo) const override;
};

//NOTE: always scatter and attenuate by its reflectance R
bool Lambertian::scatter(const Ray &wo, Ray &wi, const Interaction &isect, Color &albedo) const {
    //scatter randomly with cosine-weighted sampling
    Vec3 scatter_dir = isect.normal + rand_in_unit_sphere();

    //in case scatter_dir == 0, which will cause 0-division problems later on
    if(scatter_dir.near_zero()) scatter_dir = isect.normal;

    //return info
    wi = Ray(isect.p, scatter_dir);
    albedo = this->albedo;

    return true;
}

#endif //RAY_TRACER_LAMBERTIAN_H
