//
// Created by Jannes Van Goeye on 08/11/2019.
//

#ifndef UNTITLED1_SCREEN_H
#define UNTITLED1_SCREEN_H


#include "Resolution.h"
#include "RTPoint.h"
#include "RTSize.h"

class Screen {
public:
    Resolution resolution;
    RTPoint center;
    RTSize realSize;

    Screen(Resolution res, RTPoint screenCenter, RTSize real) {
        resolution = res;
        center = screenCenter;
        realSize = real;
    }

    Screen() {
        resolution = Resolution(0, 0);
        center = RTPoint(0, 0, 0);
        realSize = RTSize(0, 0);
    }
};


#endif //UNTITLED1_SCREEN_H
