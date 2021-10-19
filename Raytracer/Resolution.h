//
// Created by Jannes Van Goeye on 08/11/2019.
//

#ifndef UNTITLED1_RESOLUTION_H
#define UNTITLED1_RESOLUTION_H


class Resolution {
public:
    int width;
    int height;
    Resolution(int w, int h) {
        width = w;
        height = h;
    }
    Resolution() {
        width = 0;
        height = 0;
    }
};


#endif //UNTITLED1_RESOLUTION_H
