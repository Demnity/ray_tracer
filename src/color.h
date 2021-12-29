//
// Created by tandao on 12/26/21.
//

#ifndef RAY_TRACER_COLOR_H
#define RAY_TRACER_COLOR_H

#include "vec3.h"

inline std::ostream& write_color(std::ostream& out, Color color) {
    return out << static_cast<int>(255.999 * color.e[0])
            << ' ' << static_cast<int>(255.999 * color.e[1])
            << ' ' << static_cast<int>(255.999 * color.e[2]) << '\n';
}

#endif //RAY_TRACER_COLOR_H
