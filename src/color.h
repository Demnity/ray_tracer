//
// Created by tandao on 12/26/21.
//

#ifndef RAY_TRACER_COLOR_H
#define RAY_TRACER_COLOR_H

#include "vec3.h"
#include "utility.h"

inline std::ostream& write_color(std::ostream& out, Color color, const int &samples_per_pixel) {
    //normalizing color values
    double r = color.x() / samples_per_pixel;
    double g = color.y() / samples_per_pixel;
    double b = color.z() / samples_per_pixel;

    //gamma correction, gamma = 2.0
    r = sqrt(r);
    g = sqrt(g);
    b = sqrt(b);

    //clamp the values then turn into 8bit color
    return out << static_cast<int>(256 * clamp(r, 0., 0.999))
            << ' ' << static_cast<int>(256 * clamp(g, 0., 0.999))
            << ' ' << static_cast<int>(256 * clamp(b, 0., 0.999)) << '\n';
}

#endif //RAY_TRACER_COLOR_H
