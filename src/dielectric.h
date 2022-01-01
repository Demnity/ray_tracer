//
// Created by tandao on 12/31/21.
//

#ifndef RAY_TRACER_DIELECTRIC_H
#define RAY_TRACER_DIELECTRIC_H

#include "material.h"
#include "interaction.h"
#include "utility.h"

class Dielectric : public Material {
public:
    double eta;

public:
    Dielectric(double eta) : eta(eta) {}
    bool scatter(const Ray &wo, Ray &wi, const Interaction &isect, Color &albedo) const override;

private:
    static double fresnel(double cosine, double ref_idx) {
        // Use Schlick's approximation for reflectance.
        auto r0 = (1-ref_idx) / (1+ref_idx);
        r0 = r0*r0;
        return r0 + (1-r0)*pow((1 - cosine),5);
    }
};

bool Dielectric::scatter(const Ray &wo, Ray &wi, const Interaction &isect, Color &albedo) const {
    albedo = Color(1., 1., 1.); //NOTE: meaning this material will never absorb light, should rename it to another appropriate variable naem

    //invert eta depending on where the ray is inside the object or not
    double ior = isect.front_face ? 1 / eta : eta;

    Vec3 unit_dir = unit(wo.d());
    double cos_theta = fmin(dot(-wo.d(), isect.normal), 1.);
    double sin_theta = sqrt(1 - cos_theta * cos_theta);
    Vec3 out_dir;

    //if the ray angle with the normal is larger than the critical angle
    if(ior * sin_theta > 1. || fresnel(cos_theta, ior) > rand_num()) {
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
