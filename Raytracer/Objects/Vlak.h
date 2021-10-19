//
// Created by Jannes Van Goeye on 04/10/2019.
//

#ifndef UNTITLED1_VLAK_H
#define UNTITLED1_VLAK_H


#include "Object.h"

class Vlak: public Object {
public:
    Vlak();
    ~Vlak();

    double hit(Ray &ray);
};


#endif //UNTITLED1_VLAK_H
