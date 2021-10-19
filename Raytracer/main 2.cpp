#include <iostream>
#include <vector>
#include "Camera.h"
#include "Sphere.h"

int main() {
    std::vector<Object> objects;
    int amountOfRows = 20;
    int amountOfColumns = 20;
    //std::cout << "Hello, World!" << std::endl;
    Environment environment;
    Camera camera = Camera(500, 500, 200);
    camera.calculatePixels();
    camera.raytrace(environment, 1);
    return 0;
}