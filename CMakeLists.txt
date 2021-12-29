cmake_minimum_required(VERSION 3.22)
project(ray_tracer)

set(CMAKE_CXX_STANDARD 11)

set ( SOURCE_ONE_WEEKEND
        src/color.h
        src/interaction.h
        src/ray.h
        src/shape.h
        src/vec3.h
        src/sphere.h
        src/main.cpp
        src/scene.h src/utility.h src/camera.h)

add_executable(ray_tracer ${SOURCE_ONE_WEEKEND})
