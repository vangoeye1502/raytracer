//
//  LightSource.hpp
//  Raytracer
//
//  Created by Jannes Van Goeye on 26/11/2019.
//  Copyright © 2019 Universiteit Antwerpen. All rights reserved.
//

#ifndef LightSource_hpp
#define LightSource_hpp

#include <stdio.h>
#include "Vector.h"
#include "RTColor.h"

class Lightsource {
public:
    Vec3 position;
    RTColor color;
    double intensity = 100;
    Lightsource(Vec3 position_, RTColor color_ = RTColor(255,255,255), double intensity_=100.0) : position(position_), color(color_), intensity(intensity_) {}
};

#endif /* LightSource_hpp */
