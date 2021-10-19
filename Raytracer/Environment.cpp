//
// Created by Jannes Van Goeye on 25/10/2019.
//

#include "Environment.h"
#include "Intersection.h"


RTColor Environment::trace(const Ray& ray, int depth) { // A.K.A SHADE
    Intersection intersection;
    intersection = getFirstHit(ray);
    if (intersection.numberOfHits == 0) {
        return backgroundColor;
    }
    return shading(ray, intersection, depth);
}

RTColor Environment::shading(const Ray& ray, Intersection intersection, int depth) {
    RTColor color;
    HitInfo hitInfo = intersection.hits[0];
    double T = hitInfo.hitTime;
    Vec3 intersect_point = ray.start + ray.direction * T;

    /*Vec3 V = ray.direction;
    Vec3 P = ray.start + V * T;*/
    Vec3 normal = hitInfo.objectThatWasHit->getNormal(intersect_point);
    double facing_ratio = normal.dot(ray.direction.normalize());
    color = (hitInfo.objectThatWasHit->color);
    
    switch (hitInfo.objectThatWasHit->texture) {
        case MAT:
        {
            return (color).scale_by(normal.dot(ray.direction.normalize()) * 0.5);

            //return clr;
        }
        case REFLECTEREND:
        {
            RTColor clr = (color).scale_by(normal.dot(ray.direction.normalize()) * 0.5);
            if (depth > 0) {
                clr = clr+ trace(Ray(intersect_point, (ray.direction - normal * ray.direction.dot(normal)*2)), depth - 1);
            }
            return clr;
        }
        case SPIEGELEND:
        {
            RTColor clr = (color).scale_by(normal.dot(ray.direction.normalize()) * 0.5);
            //RTColor clr = RTColor(0, 0, 0);
            for (const Lightsource& light: lightsources){
                Vec3 light2pos = light.position - intersect_point;
                //specular:
                if (check_occlusion(intersect_point, light.position)) {
                    clr = clr + light.color.scale_by2(ray.reflect_by(normal).dot(light2pos)); // add check for occlusion
                    //mat:
                    clr = clr + (color).mix_with(light.color).scale_by(light.intensity / (light.position - intersect_point).norm2());
                }
            }
            //reflections:
            if (depth > 0)
                clr = clr+ trace(Ray(intersect_point.normalize(), (ray.direction - normal * ray.direction.dot(normal)*2)), depth - 1);
            return clr;
        }
        default:
            break;
    }
    /*if (hitInfo.objectThatWasHit->texture == REFLECTEREND) {
        if (depth > 0) {
            clr = clr+ trace(Ray(intersect_point, (ray.direction - normal * ray.direction.dot(normal)*2)), depth - 1);
        }
    } else if (hitInfo.objectThatWasHit->texture == SPIEGELEND) {
            for (const Lightsource& light: lightsources){
                Vec3 light2pos = light.position - intersect_point;
                //specular:
                if (check_occlusion(intersect_point, light.position)) {
                    clr = clr + light.color.scale_by2(ray.reflect_by(normal).dot(light2pos.normalize())); // add check for occlusion
                    //mat:
                    clr = clr + (hitInfo.objectThatWasHit->color).mix_with(light.color).scale_by(light.intensity / (light.position - intersect_point).norm2());
                }
            }
            //reflections:
            if (depth > 0)
                clr = clr+ trace(Ray(intersect_point, (ray.direction - normal * ray.direction.dot(normal)*2)), depth - 1);
            return clr;
            
    }*/
    return color;
}

bool Environment::check_occlusion(Vec3 target, Vec3 source) {
    Vec3 toSource = source - target;
    double t_light = toSource.norm();
    Ray ray = Ray(target, toSource * (1.0 / t_light));
    double min_t = t_light;
    const Object* nearest_obj = nullptr;
    double t = 99999;
    Intersection inter;
    for (Object* object : objects) {
        if (object->hit(ray, inter)) {
            if (min_t > inter.hits[0].hitTime) {
                nearest_obj = object;
                min_t = inter.hits[0].hitTime;
            }
        }
    }
    return nearest_obj == nullptr; // false if lightsource is occluded
}


Intersection Environment::getFirstHit(const Ray& ray) {
    Intersection intersection;
    Intersection firstIntersection;

    for(int i = 0; i < objects.size(); i++) {
        
        if (objects[i]->hit(ray, intersection)) {
            if(firstIntersection.hits.size() == 0 || (intersection.hits[0].hitTime < firstIntersection.hits[0].hitTime)) {
                firstIntersection.set(intersection);
            }
        }
    }

    return firstIntersection;
}
