//
// Created by Jannes Van Goeye on 04/10/2019.
//

#ifndef UNTITLED1_OBJECT_H
#define UNTITLED1_OBJECT_H

#include <iostream>
#include "Transformation.h"
#include "Intersection.h"
#include "RTColor.h"
#include "RTTexture.h"

class Object {
public:
    Object();

    RTColor color;
    RTTexture texture;
    Transformation transformMatrix;
    Transformation inverseTransformMatrix;

    virtual bool hit(const Ray& ray, Intersection& firstIntersection) = 0;
    //virtual bool intersect(const Ray& ray, Intersection& firstIntersection) = 0;

    virtual Vec3 getNormal(Vec3 point) = 0;
    void translation(double dx, double dy, double dz);
    void scaleXY(double scalefactor);
    void rotateX(double angle);
    void rotateY(double angle);
    void rotateZ(double angle);

};


#endif //UNTITLED1_OBJECT_H
