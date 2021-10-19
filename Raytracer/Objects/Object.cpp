//
// Created by Jannes Van Goeye on 04/10/2019.
//

#include "Object.h"

Object::Object() = default;

void Object::translation(double dx, double dy, double dz) {
    transformMatrix.matrix[0][3] += dx;
    transformMatrix.matrix[1][3] += dy;
    transformMatrix.matrix[2][3] += dz;
    
    inverseTransformMatrix = transformMatrix.inverse();
}

void Object::scaleXY(double scalefactor) {
    transformMatrix.matrix[0][0] -= scalefactor;
    transformMatrix.matrix[1][1] -= scalefactor;
    transformMatrix.matrix[2][2] -= scalefactor;
    
    inverseTransformMatrix = transformMatrix.inverse();
}

void Object::rotateX(double angle) {
    transformMatrix.matrix[1][1] = cos(angle);
    transformMatrix.matrix[2][1] = sin(angle);
    transformMatrix.matrix[1][2] = -sin(angle);
    transformMatrix.matrix[2][2] = cos(angle);
}

void Object::rotateY(double angle) {
    transformMatrix.matrix[0][0] = cos(angle);
    transformMatrix.matrix[0][2] = sin(angle);
    transformMatrix.matrix[2][0] = -sin(angle);
    transformMatrix.matrix[2][2] = cos(angle);
}

void Object::rotateZ(double angle) {
    transformMatrix.matrix[0][0] = cos(angle);
    transformMatrix.matrix[0][1] = -sin(angle);
    transformMatrix.matrix[1][0] = sin(angle);
    transformMatrix.matrix[1][1] = cos(angle);
}

