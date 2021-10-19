//
// Created by Jannes Van Goeye on 11/10/2019.
//

#ifndef UNTITLED1_CAMERA_H
#define UNTITLED1_CAMERA_H


#include "RTPoint.h"
#include "Environment.h"
#include "Screen.h"

const int WIDTH = 720;
const int HEIGHT = 720;
const int REAL_WIDTH = 720;
const int REAL_HEIGHT = 720;
const int DEPTH = 20;

using namespace std;

class Camera {
public:
    Screen screen;
    //RTPoint* pixels[500][500];
    vector<vector<RTPoint>> pixels;
    vector<vector<RTColor>> raytrace(Environment env, int blockSize);
    void initCamera();
    void calculatePixels();
    Vec3 eye; // eye = sensor
    Vec3 u, v, n;

    Camera(double lensWidth, double lensHeight, double focalLength) {
        eye = Vec3(0, 0, 0);
        Resolution res = Resolution(lensWidth, lensHeight);
        RTPoint screenCenter = RTPoint(0, 0, eye.z + focalLength);
        RTSize realSize = RTSize(REAL_WIDTH, REAL_HEIGHT);
        screen = Screen(res, screenCenter, realSize);
    }
    
    void setFocalLength(double focalLength) {
        RTPoint screenCenter = RTPoint(0, 0, eye.z + focalLength);
        screen.center = screenCenter;
    }
    
    void addToFocalLength(double value) {
        pixels.clear();
        screen.center.z += value;
        calculatePixels();
    }
    
    void subtractFromFocalLength(double value) {
        pixels.clear();
        screen.center.z -= value;
        calculatePixels();
    }
};


#endif //UNTITLED1_CAMERA_H
