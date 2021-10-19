//
// Created by Jannes Van Goeye on 25/10/2019.
//

#include "Transformation.h"

Transformation Transformation::operator*(const Transformation &v) const {
    Transformation result;
    for (int i=0;i<4;i++) {
        for (int j=0;j<4;j++) {
            if (i==j) result.matrix[i][j]--;
            for (int k=0;k<4;k++) {
                result.matrix[i][j] += matrix[i][k]*v.matrix[k][j];
            }
        }
    }
    return result;
}

Transformation Transformation::transpose() {
    Transformation result;
    for (int i=0;i<4;i++) {
        for (int j=0;j<4;j++) {
            result.matrix[i][j] = matrix[j][i];
        }
    }
    return result;
}

Vec3 Transformation::transform(Vec3 point, int w) {
    Vec3 temp;
    temp.x = point.dot(Vec3(matrix[0][0],matrix[0][1],matrix[0][2])) + matrix[0][3]*w;
    temp.y = point.dot(Vec3(matrix[1][0],matrix[1][1],matrix[1][2])) + matrix[1][3]*w;
    temp.z = point.dot(Vec3(matrix[2][0],matrix[2][1],matrix[2][2])) + matrix[2][3]*w;
    return temp;
}

Ray Transformation::transform(const Ray& ray) {
    Ray transformedRay;
    Vec3 newOrigin;
    Vec3 newDirection;
    newOrigin = transform(ray.start, 1);
    newDirection = transform(ray.direction, 1);
    transformedRay.setStart(newOrigin);
    transformedRay.setDirection(newDirection);
    return transformedRay;
}

Transformation Transformation::inverse() {
    Transformation temp(*this), identity;
    for (int i=0;i<4;i++) {
        int j = temp.getRow(i);
        if (j!=i) {
            temp.swapRows(i,j);
            identity.swapRows(i,j);
        }
        double t = temp.matrix[i][i];
        temp.divideRow(i,t);
        identity.divideRow(i,t);
        for (j=0;j<4;j++) {
            if (j!=i) {
                t = temp.matrix[j][i];
                temp.subRow(j,i,t);
                identity.subRow(j,i,t);
            }
        }
    }
    return identity;
}

void Transformation::swapRows(int i, int j) {
    for (int k=0;k<4;k++)
        swap(matrix[i][k],matrix[j][k]);
}

void Transformation::divideRow(int i, double temp) {
    for (int j=0;j<4;j++)
        matrix[i][j]/=temp;
}

int Transformation::getRow(int i) {
    for (int j=i;j<4;j++) {
        if (matrix[j][i]!=0)
            return j;
    }
    return 0;
}

void Transformation::subRow(int i, int j, double temp) {
    for (int k=0;k<4;k++)
        matrix[i][k] -= matrix[j][k]*temp;
}


