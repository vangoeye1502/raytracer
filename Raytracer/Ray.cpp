//
// Created by Jannes Van Goeye on 04/10/2019.
//

#include "Ray.h"

Vec3 Ray::getPosition(double t) const {
    Vec3 pos = start + direction * t;
    return pos;
}
