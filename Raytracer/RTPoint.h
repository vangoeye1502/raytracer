//
// Created by Jannes Van Goeye on 11/10/2019.
//

#ifndef UNTITLED1_RTPOINT_H
#define UNTITLED1_RTPOINT_H


class RTPoint {
public:
    double x,y,z;
    RTPoint(double xpos, double ypos, double zpos) { x = xpos; y = ypos; z = zpos; }
    RTPoint() { x = y = z = 0; }

    void set(RTPoint& p) { x = p.x; y = p.y; z = p.z; }
    void set(double xpos, double ypos, double zpos) { x = xpos; y = ypos; z = zpos; }
};


#endif //UNTITLED1_RTPOINT_H
