#include <iostream>
#include "Color.h"
#include "Ray.h"
#include "Scene.h"
#include "Sphere.h"
#include "utility.h"

Color ray_color(const Ray &ray, const Scene &scene) {
    Interaction isect;
    if(scene.intersect(ray, 0, infinity, isect)) {
        //Normal interpolation
        //Taking normal range from [-1,1] to [0,1] for coloring
        return 0.5 * (isect.normal + Color(1., 1., 1.));
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

    const Vec3 view_horizontal(view_width, 0., 0.);
    const Vec3 view_vertical(0., view_height, 0.);
    const Vec3 lower_left_coord(-view_width/2, -view_height/2, -focal_length);

    //origin of the camera
    const Point3 origin(0., 0., 0.);

    ////SCENE
    Scene scene;
    scene.addShape(make_shared<Sphere>(Point3(0,0,-1), 0.5));
    scene.addShape(make_shared<Sphere>(Point3(0,-100.5,-1), 100));

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
            Color color = ray_color(ray, scene);
            write_color(std::cout, color);
        }
    }
    std::cerr << "\nDone.\n";
}
