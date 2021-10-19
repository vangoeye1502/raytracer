//
// Created by Jannes Van Goeye on 11/10/2019.
//

#include "Sphere.h"
bool Sphere::hit(const Ray& ray, Intersection& firstIntersection) {
    Ray transformedRay;
    transformedRay = transformMatrix.transform(ray);
    double A,B,C;
    A = transformedRay.direction.dot(transformedRay.direction);
    B = transformedRay.start.dot(transformedRay.direction);
    C = transformedRay.start.dot(transformedRay.start) - 1.0;

    double D = B * B - A * C;

    if (D < 0.0) {
        return false;
    }

    int numberOfHits = 0;
    double dRoot = sqrt(D);
    double t_1 = (-B - dRoot)/A;
    double t_2 = (-B + dRoot)/A;

    if (t_1 > 0.00001) {
        firstIntersection.hits.push_back(HitInfo());
        firstIntersection.hits[0].hitTime = t_1;
        firstIntersection.hits[0].objectThatWasHit = this;
        firstIntersection.hits[0].rayEnteredObject = true;

        Vec3 p = transformedRay.getPosition(t_1);
        firstIntersection.hits[0].hitPoint.set(p);
        firstIntersection.hits[0].hitNormal.set(p);
        numberOfHits = 1;
    }

    if (t_2 > 0.00001) {
        firstIntersection.hits.push_back(HitInfo());
        firstIntersection.hits[numberOfHits].hitTime = t_2;
        firstIntersection.hits[numberOfHits].objectThatWasHit = this;
        firstIntersection.hits[numberOfHits].rayEnteredObject = false;

        Vec3 p = transformedRay.getPosition(t_2);
        firstIntersection.hits[numberOfHits].hitPoint.set(p);
        firstIntersection.hits[numberOfHits].hitNormal.set(p);
        numberOfHits++;
    }
    
    firstIntersection.numberOfHits = numberOfHits;

    return (numberOfHits > 0);
}

/*bool Sphere::intersect(const Ray& ray, Intersection& firstIntersection) {
    Ray transformedRay;
    transformedRay = transformMatrix.transform(ray);
    Vec3 v = transformedRay.start - center;
    double t = 0;
    
    const double b = 2 * v.dot(transformedRay.direction);
    const double c = v.dot(v) - radius*radius;
    double delta = b*b - 4 * c;

    if (delta < 0) {
        t = 999999; // no intersection, at 'infinity'
        return false;
    }

    const double t1 = (-b - sqrt(delta))/2;
    const double t2 = (-b + sqrt(delta))/2;

    if (t2 < 0) { // the sphere is behind us
        t = 999999;
        return false;
    }
    firstIntersection.hits.push_back(HitInfo());
    firstIntersection.hits[0].hitTime = t1;
    firstIntersection.hits[0].objectThatWasHit = this;
    firstIntersection.hits[0].rayEnteredObject = true;
    Vec3 p = transformedRay.getPosition(t1);
    firstIntersection.hits[0].hitPoint.set(p);
    firstIntersection.hits[0].hitNormal.set(p);
    
    t = (t1 >= 0) ? t1 : t2;
    
    return true;
}*/

Vec3 Sphere::getNormal(Vec3 point) {
    Vec3 transformedPoint = transformMatrix.transform(point, 1);
    return (transformedPoint - center) * (-1/(1));
}
