//
//  Square.cpp
//  Raytracer
//
//  Created by Jannes Van Goeye on 22/11/2019.
//  Copyright © 2019 Universiteit Antwerpen. All rights reserved.
//

#include "Square.hpp"
bool Square::hit(const Ray& ray, Intersection& firstIntersection) {
    Ray transformedRay;
    transformedRay = transformMatrix.transform(ray);
    
    double denom = transformedRay.direction.z;
    if (fabs(denom) < 0.0001) { return false; }
    double time = -transformedRay.start.z/denom;
    if (time <= 0.0) return false;
    double hx = transformedRay.start.x + transformedRay.direction.x * time;
    double hy = transformedRay.start.y + transformedRay.direction.y * time;
    if ((hx > 1.0) || (hx < -1.0)) return false;
    if ((hy > 1.0) || (hy < -1.0)) return false;
    firstIntersection.numberOfHits = 1;
    firstIntersection.hits.push_back(HitInfo());
    firstIntersection.hits[0].objectThatWasHit = this;
    firstIntersection.hits[0].hitTime = time;
    firstIntersection.hits[0].rayEnteredObject = true;
    firstIntersection.hits[0].hitPoint.x = hx;
    firstIntersection.hits[0].hitPoint.y = hy;
    firstIntersection.hits[0].hitPoint.z = 0;
    firstIntersection.hits[0].hitNormal.x = 0;
    firstIntersection.hits[0].hitNormal.y = 0;
    firstIntersection.hits[0].hitNormal.z = 1;
    return true;
}

Vec3 Square::getNormal(Vec3 point) {
    Vec3 transformedPoint = transformMatrix.transform(point, 1);
    return transformedPoint;
}
