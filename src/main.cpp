#include <iostream>
#include "Color.h"
#include "Ray.h"

Vec3 Lerp(const double t, const Vec3 &u1, const Vec3 &u2) {
    return (1 - t) * u1 + t * u2;
}

double hit_sphere(const Point3 &center, double radius, const Ray &ray) {
    Vec3 ray_o_to_center = ray.o() - center;
    double a = dot(ray.d(), ray.d());
    double b = dot(ray.d(), ray_o_to_center);
    double c = dot(ray_o_to_center, ray_o_to_center) - radius * radius;
    double delta = b * b - a * c;
    return delta < 0. ? -1. : (-b - sqrt(delta)) / a;
}

Color ray_color(const Ray &r) {
    Point3 sphere_center(0., 0., -3.);
    double t = hit_sphere(sphere_center, 2, r);
    if(t >= 0.) {
        Vec3 normal = unit(r.at(t) - sphere_center);
        return 0.5 * Color(normal.x() + 1., normal.y() + 1., normal.z() + 1.);
    }
    Vec3 unit_direction = unit(r.d());
    t = 0.5 * (unit_direction.y() + 1.0);
    return (1. - t) * Color(1.0, 1.0, 1.0) + t * Color(0.5, 0.7, 1.0);
}

int main() {
    //image ratio
    const double aspect_ratio = 16. / 9.;

    //image width and height
    const int max_height = 400;
    const int max_width = aspect_ratio * max_height;

    //defining the near plane width and height
    const double focal_length = 1.;
    const double view_height = 2.;
    const double view_width = aspect_ratio * view_height;

    const Vec3 view_horizontal(view_width, 0., 0.);
    const Vec3 view_vertical(0., view_height, 0.);
    const Vec3 lower_left_coord(-view_width/2, -view_height/2, -focal_length);

    //origin of the camera
    const Point3 origin(0., 0., 0.);

    std::cout << "P3\n" << max_width << " " << max_height << "\n255\n";
    for(int j = max_height - 1; j > 0; --j) {
        //progress bar
        std::cerr << "\nProgress: " << (max_height - j - 1) * 100/ max_height << '%' << std::flush;

        //render loop, could be parallelized
        for(int i = 0; i < max_width; ++i) {
            //ratio to trace rays to
            double u = double(j) / (max_height - 1);
            double v = double(i) / (max_width  - 1);

            //tracing the ray
            Ray ray(origin, lower_left_coord + u * view_vertical + v * view_horizontal - origin);

            //outputting color
            Color color = ray_color(ray);
            write_color(std::cout, color);
        }
    }
    std::cerr << "\nDone.\n";
}