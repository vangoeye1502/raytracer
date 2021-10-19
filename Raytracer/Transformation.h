//
// Created by Jannes Van Goeye on 25/10/2019.
//

#ifndef UNTITLED1_TRANSFORMATION_H
#define UNTITLED1_TRANSFORMATION_H

#include <vector>
#include "Ray.h"

enum Affine {ROTATEX,ROTATEY,ROTATEZ,SCALE,TRANSLATE,SHEAR};

using namespace std;

class Transformation {
public:
    vector<vector<double>> matrix = {{1,0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};

    Transformation operator * (const Transformation& v) const;

    void swapRows(int i, int j);
    void divideRow(int i, double temp);
    int getRow(int i);
    void subRow(int i, int j, double temp);

    Vec3 transform(Vec3 point, int w);
    Ray transform(const Ray& ray);
    Transformation inverse();
    Transformation transpose();
};


#endif //UNTITLED1_TRANSFORMATION_H
