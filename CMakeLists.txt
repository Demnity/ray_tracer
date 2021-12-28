cmake_minimum_required(VERSION 3.22)
project(ray_tracer)

set(CMAKE_CXX_STANDARD 11)

set ( SOURCE_ONE_WEEKEND
        src/Color.h
        src/Interaction.h
        src/Ray.h
        src/Shape.h
        src/Vec3.h
        src/Sphere.h
        src/main.cpp
        )

add_executable(ray_tracer ${SOURCE_ONE_WEEKEND})
