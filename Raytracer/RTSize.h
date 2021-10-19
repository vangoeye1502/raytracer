//
// Created by Jannes Van Goeye on 08/11/2019.
//

#ifndef UNTITLED1_RTSIZE_H
#define UNTITLED1_RTSIZE_H


class RTSize {
public:
    double width;
    double height;
    RTSize() {
        width = 0;
        height = 0;
    }
    RTSize(double w, double h) {
        width = w;
        height = h;
    }
};


#endif //UNTITLED1_RTSIZE_H
