//
// Created by Jannes Van Goeye on 11/10/2019.
//

#ifndef UNTITLED1_SPHERE_H
#define UNTITLED1_SPHERE_H


#include "Object.h"

class Sphere: public Object {
public:
    Sphere(Vec3 point, double r, RTColor rgbColor, RTTexture tex) {
        center = point;
        radius = r;
        color = rgbColor;
        texture = tex;
    };

    ~Sphere() = default;

    Vec3 center;
    double radius;

    bool hit(const Ray& ray, Intersection& firstIntersection);
    bool intersect(const Ray& ray, Intersection& firstIntersection);
    Vec3 getNormal(Vec3 point);
};


#endif //UNTITLED1_SPHERE_H
