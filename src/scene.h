//
// Created by tandao on 12/28/21.
//

#ifndef RAY_TRACER_SCENE_H
#define RAY_TRACER_SCENE_H

#include <vector>
#include <memory>
#include "shape.h"

using std::shared_ptr;
using std::make_shared;

class Scene {
public:
    std::vector<shared_ptr<Shape>> aggregate; //should actually be primitives instead, might update in the future

public:
    Scene() {}
    Scene(shared_ptr<Shape> &shape) {
        addShape(shape);
    }
    void addShape(const shared_ptr<Shape> &shape) {
        aggregate.push_back(shape);
    }
    void clear() {
        aggregate.clear();
    }

    bool intersect(const Ray &ray, double t_min, double t_max, Interaction &isect) const;
};

bool Scene::intersect(const Ray &ray, double t_min, double t_max, Interaction &isect) const {
    //store info on each shape
    Interaction temp;
    bool intersected = false;
    double closest_t = t_max;

    //intersection loop on each shape
    for(const shared_ptr<Shape> &shape : aggregate) {
        if(shape->intersect(ray, t_min, closest_t, temp)) {
            intersected = true;
            closest_t = temp.t;
            isect = temp;
        }
    }

    return intersected;
}

#endif //RAY_TRACER_SCENE_H
