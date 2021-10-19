//
// Created by Jannes Van Goeye on 25/10/2019.
//

#ifndef UNTITLED1_HITINFO_H
#define UNTITLED1_HITINFO_H


#include "Vector.h"

class Object;

class HitInfo {
public:
    Object* objectThatWasHit;
    bool rayEnteredObject;
    Vec3 hitPoint;
    Vec3 hitNormal;
    double hitTime;

    void set(HitInfo& hitInfo) {
        hitNormal.set(hitInfo.hitNormal);
        hitPoint.set(hitInfo.hitPoint);
        rayEnteredObject = hitInfo.rayEnteredObject;
        objectThatWasHit = hitInfo.objectThatWasHit;
    }
};


#endif //UNTITLED1_HITINFO_H
