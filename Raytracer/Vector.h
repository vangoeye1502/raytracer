//
// Created by Jannes Van Goeye on 04/10/2019.
//

#ifndef UNTITLED1_VECTOR_H
#define UNTITLED1_VECTOR_H


#include <cmath>


using namespace std;

class Vec3 {
public:
    double x;
    double y;
    double z;

    Vec3(double xpos, double ypos, double zpos) { x = xpos; y = ypos; z = zpos; }
    //virtual ~Vec3();
    Vec3() { x = 0; y = 0; z = 0; }

    Vec3 operator +(Vec3 vec) {
        return {x+vec.x,y+vec.y,z+vec.z};
    }
    Vec3 operator -(Vec3 vec) {
        return {x-vec.x,y-vec.y,z-vec.z};
    }
    Vec3 operator *(double scalar) {
        return {scalar*x,scalar*y,scalar*z};
    }
    
    Vec3 operator +(Vec3 vec) const {
        return {x+vec.x,y+vec.y,z+vec.z};
    }
    Vec3 operator -(Vec3 vec) const {
        return {x-vec.x,y-vec.y,z-vec.z};
    }
    Vec3 operator *(double scalar) const {
        return {scalar*x,scalar*y,scalar*z};
    }
    double dot(Vec3 vec) {
        return x*vec.x+y*vec.y+z*vec.z;
    }
    double norm() {
        return sqrt(dot(*this));
    }
    Vec3 normalize() {
        return (*this)*(1/norm());
    }
    
    double dot(Vec3 vec) const {
        return x*vec.x+y*vec.y+z*vec.z;
    }
    double norm() const {
        return sqrt(dot(*this));
    }
    Vec3 normalize() const {
        return (*this)*(1/norm());
    }
    
    double norm2() {
        return dot(*this);
    }

    void set(Vec3& vector) {
        x = vector.x;
        y = vector.y;
        z = vector.z;
    }

};


#endif //UNTITLED1_VECTOR_H
