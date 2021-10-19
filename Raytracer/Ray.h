//
// Created by Jannes Van Goeye on 04/10/2019.
//

#ifndef UNTITLED1_RAY_H
#define UNTITLED1_RAY_H


#include "Vector.h"
#include "RTPoint.h"

class Ray {
public:
    Ray(Vec3 strt, Vec3 dir) { start = strt; direction = dir; }
    explicit Ray(Vec3 strt) { start = strt; }
    Ray() = default;

    Vec3 direction;
    Vec3 start;

    void setStart(Vec3& strt) { start.set(strt); }
    void setDirection(float x, float y, float z) { direction.x = x; direction.y = y; direction.z = z; }
    void setDirection(Vec3& dir) { direction.set(dir); }
    Vec3 getPosition(double t) const;
    Vec3 reflect_by(const Vec3& normal) const{
        return direction - normal * normal.dot(direction) * 2;
    }
};


#endif //UNTITLED1_RAY_H
