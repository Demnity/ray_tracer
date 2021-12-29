//
// Created by tandao on 12/29/21.
//

#ifndef RAY_TRACER_CAMERA_H
#define RAY_TRACER_CAMERA_H

#include "utility.h"

class Camera {
private:
    Point3 origin;
    Point3 lower_left_corner;
    Vec3 view_horizontal;
    Vec3 view_vertical;
    double focal_length;

public:
    Camera() {}
    Camera(const Point3 &origin, const double &focal_length, const double &view_width, const double &view_height)
            : origin(origin), focal_length(focal_length) {
        view_horizontal = Vec3(view_width, 0., 0.);
        view_vertical = Vec3(0., view_height, 0.);
        lower_left_corner = Vec3(-view_width/2, -view_height/2, -focal_length);
    }

    /*
     * Take in pixel ratios: u = (current pixel index + rand()) / image width,...
     */
    Ray spawn_ray(const double &u, const double &v) {
        return Ray(origin, lower_left_corner + u * view_horizontal + v * view_vertical - origin);
    }
};

#endif //RAY_TRACER_CAMERA_H
