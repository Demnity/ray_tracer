#include <iostream>
#include "color.h"
#include "ray.h"
#include "scene.h"
#include "sphere.h"
#include "utility.h"
#include "camera.h"
#include "lambertian.h"
#include "metal.h"

//This is very wrong, light is yet to be defined!!
Color ray_color(const Ray &ray, const Scene &scene, int depth) {
    Interaction isect;

    //reaching max depth, terminating
    if(depth <= 0) return Color(0., 0., 0.);

    //range from 0.000001 to inf due to errors in floating point
    if(scene.intersect(ray, 0.00001, infinity, isect)) {
        Ray wi;
        Color albedo;
        if(isect.material->scatter(ray, wi, isect, albedo))
            return albedo * ray_color(wi, scene, depth - 1);
        return Color(0., 0., 0.);
    }
    Vec3 unit_direction = unit(ray.d());
    double t = 0.5 * (unit_direction.y() + 1.0);
    return (1. - t) * Color(1.0, 1.0, 1.0) + t * Color(0.5, 0.7, 1.0);
}

int main() {
    ////IMAGE
    //image ratio
    const double aspect_ratio = 16. / 9.;

    //image width and height
    const int max_height = 400;
    const int max_width = aspect_ratio * max_height;

    ////CAMERA
    //defining the near plane width and height
    const double focal_length = 1.;
    const double view_height = 2.;
    const double view_width = aspect_ratio * view_height;
    const Point3 cam_origin(0., 0., 3.);
    Camera camera(cam_origin, focal_length, view_width, view_height);

    ////Super sampling
    const int samples_per_pixel = 1000;
    const int max_depth = 50;

    ////SCENE
    Scene scene;

    shared_ptr<Lambertian> material_ground = make_shared<Lambertian>(Color(0.8, 0.8, 0.0));
    shared_ptr<Lambertian> material_center = make_shared<Lambertian>(Color(0.7, 0.3, 0.3));
    shared_ptr<Metal> material_left   = make_shared<Metal>(Color(0.8, 0.8, 0.8), 0.8);
    shared_ptr<Metal> material_right  = make_shared<Metal>(Color(0.8, 0.6, 0.2), 0.1);

    scene.addShape(make_shared<Sphere>(Point3( 0.0, -100.5, -1.0), 100.0, material_ground));
    scene.addShape(make_shared<Sphere>(Point3( 0.0,    0.0, -1.0),   0.5, material_center));
    scene.addShape(make_shared<Sphere>(Point3(-1.0,    0.0, -1.0),   0.5, material_left));
    scene.addShape(make_shared<Sphere>(Point3( 1.0,    0.0, -1.0),   0.5, material_right));

    std::cout << "P3\n" << max_width << " " << max_height << "\n255\n";
    //render loop, could be parallelized
    for(int j = max_height - 1; j > 0; --j) {
        //progress bar
        std::cerr << "\nProgress: " << (max_height - j - 1) * 100/ max_height << '%' << std::flush;

        for(int i = 0; i < max_width; ++i) {
            Color color(0., 0., 0.);
            //super sampling
            for(int k = 0; k < samples_per_pixel; k++) {
                //ratio to trace rays to
                double u = (i + rand_num()) / (max_width - 1);
                double v = (j + rand_num()) / (max_height - 1);

                //tracing the ray
                Ray ray = camera.spawn_ray(u, v);

                //outputting color
                color += ray_color(ray, scene, max_depth);
            }
            write_color(std::cout, color, samples_per_pixel);
        }
    }
    std::cerr << "\nDone.\n";
}
