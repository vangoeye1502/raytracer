//
// Created by Jannes Van Goeye on 25/10/2019.
//

#ifndef UNTITLED1_RTCOLOR_H
#define UNTITLED1_RTCOLOR_H


#include <string>
#include <sstream>

class RTColor {
public:
    double red, green, blue;

    RTColor() { red = green = blue = 0; }
    RTColor(double r, double g, double b) { red = r; green = g; blue = b; }
    RTColor(const RTColor& color) { red = color.red; green = color.green; blue = color.blue; }

    void set(double r, double g, double b) {
        if (r > 255) {
            red = 255;
        } else if (r < 0) {
            red = 0;
        } else {
            red = r;
        }
        if (g > 255) {
            green = 255;
        } else if (g < 0) {
            green = 0;
        } else {
            green = g;
        }
        if (b > 255) {
            blue = 255;
        } else if (b < 0) {
            blue = 0;
        } else {
            blue = b;
        }
    }
    void set(const RTColor& color) { red = color.red; green = color.green; blue = color.blue; }
    std::string getString() {
        std::ostringstream stream;
        stream << "Color: " << red;
        stream << ", " << green;
        stream << ", " << blue;

        std::string text = stream.str();
        return text;
    }
    
    RTColor operator +(const RTColor& rhs) const {
        return Color_trunc(red + rhs.red, green + rhs.green, blue + rhs.blue);
    }
    static int trunc(double val) {
        if (val < 0) { return 0; }
        return (val > 255) ? 255 : val;
    }
    static RTColor Color_trunc(double red, double green, double blue) {
        return RTColor(trunc(red), trunc(green), trunc(blue));
    }
    RTColor scale_by(double scalar)const {
        return (scalar > 0) ? Color_trunc(scalar * red, scalar * green, scalar * blue) : RTColor(0,0,0);
    }
    RTColor scale_by2(double scalar)const {
        if (scalar < 0)
            return  RTColor(0, 0, 0);
        scalar *= scalar;
        return Color_trunc(scalar * red, scalar * green, scalar * blue);
    }
    RTColor mix_with(const RTColor& rhs) const {
        return RTColor(red * rhs.red, green * rhs.green, blue * rhs.blue);
    }
};


#endif //UNTITLED1_RTCOLOR_H
