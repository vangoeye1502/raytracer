//
//  Square.hpp
//  Raytracer
//
//  Created by Jannes Van Goeye on 22/11/2019.
//  Copyright © 2019 Universiteit Antwerpen. All rights reserved.
//

#ifndef Square_hpp
#define Square_hpp

#include <stdio.h>
#include "Object.h"

class Square: public Object {
public:
    Square(Vec3 point, Transformation& matrix, RTColor c, RTTexture tex) {
        center = point;
        transformMatrix.matrix = matrix.matrix;
        inverseTransformMatrix = matrix.inverse();
        color = c;
        texture = tex;
    };
    Square(Vec3 point, RTColor c, RTTexture tex) {
        center = point;
        color = c;
        texture = tex;
    };

    ~Square() = default;

    Vec3 center;

    bool hit(const Ray& ray, Intersection& firstIntersection);
    Vec3 getNormal(Vec3 point);
};
#endif /* Square_hpp */
