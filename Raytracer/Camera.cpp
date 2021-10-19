//
// Created by Jannes Van Goeye on 11/10/2019.
//

#include <iostream>
#include "Camera.h"

vector<vector<RTColor>> Camera::raytrace(Environment env, int blockSize) {
    Ray ray;
    ray.start.set(eye);
    vector<vector<RTColor>> frameOfPixelValues;
    
    for(int row = 0; row < screen.resolution.height; row += blockSize) {
        frameOfPixelValues.push_back(vector<RTColor>());
        for(int column = 0; column < screen.resolution.width; column += blockSize) {
            Vec3 newDirection = Vec3(pixels[row][column].x - eye.x, pixels[row][column].y - eye.y, pixels[row][column].z - eye.z);
            ray.direction.set(newDirection);
            RTColor color;
            color = env.trace(ray, DEPTH);
            frameOfPixelValues.at(row).push_back(color);
            //std::cout << color.getString();
        }
    }
    return frameOfPixelValues;
}

void Camera::calculatePixels() {
    double pixelWidth = screen.realSize.width/double(screen.resolution.width);
    double pixelHeight = screen.realSize.height/double(screen.resolution.height);

    for (int pixelRow = 0; pixelRow < screen.resolution.height; pixelRow++) {
        pixels.push_back(vector<RTPoint>());
        for (int pixelColumn = 0; pixelColumn < screen.resolution.width; pixelColumn++) {
            double pixelX = ((pixelColumn - (screen.resolution.width/2)) + 0.5) * pixelWidth;
            double pixelY = ((pixelRow - (screen.resolution.height/2)) + 0.5) * pixelHeight;
            double pixelZ = screen.center.z;
            RTPoint newPixel = RTPoint(pixelX, pixelY, pixelZ);
            //pixels[pixelColumn][pixelRow] = &newPixel;
            pixels.at(pixelRow).push_back(newPixel);
        }
    }

}
