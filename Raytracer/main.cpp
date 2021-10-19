//
//  main.cpp
//  Raytracer
//
//  Created by Jannes Van Goeye on 15/11/2019.
//  Copyright © 2019 Universiteit Antwerpen. All rights reserved.
//

#include <iostream>
#include <vector>
#include "Camera.h"
#include "Sphere.h"
#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>

#include <OpenGL/glext.h>


extern const int WIDTH;
extern const int HEIGHT;
GLubyte* PixelBuffer = new GLubyte[WIDTH * HEIGHT * 3];
Camera camera = Camera(WIDTH, HEIGHT, 200);
Environment environment;



void setup() {
    // clear the framebuffer each frame with black color
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

// Function that does the drawing
// glut calls this function whenever it needs to redraw
void display() {
    // clear the color buffer before each drawing
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // draw triangles starting from index 0 and
    // using 3 indices
    glDrawPixels(WIDTH, HEIGHT, GL_RGB, GL_UNSIGNED_BYTE, PixelBuffer);


    // swap the buffers and hence show the buffers
    // content to the screen
    glutSwapBuffers();
}



void makePixel(int x, int y, int r, int g, int b, GLubyte* pixels, int width, int height)
{
    if (0 <= x && x < width && 0 <= y && y < height) {
        int position = (x + y * width) * 3;
        pixels[position] = r;
        pixels[position + 1] = g;
        pixels[position + 2] = b;
    }
}

void trace() {
    std::vector<std::vector<RTColor>> pixels = camera.raytrace(environment, 1);

    for(int i = 0; i < pixels.size(); i++) {
       for(int j = 0; j < pixels[i].size(); j++) {
            RTColor color = pixels[i][j];
            makePixel(j,i,color.red,color.green,color.blue,PixelBuffer, WIDTH, HEIGHT);
           //makePixel(i,j,200,120,105,PixelBuffer, WIDTH, HEIGHT);
        }
    }
}

/*void tasten (unsigned char key, int xmouse, int ymouse)
{
    switch (key){
        case 'z':
            camera.addToFocalLength(100);
            trace();
            break;

        case 's':
            camera.subtractFromFocalLength(100);
            trace();
        break;

        default:
         break;
    }
}*/

int main(int argc, char * argv[]) {
    int test = 0;
    std::cout << "test" << std::endl;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Computer Graphics - Raytracer V0.0.1");
    //glewInit();
    setup();
    //glMatrixMode(GL_PROJECTION);
    //gluOrtho2D (0.0, windWidth, 0.0, windHeight);
    //DrawCircle(100, 100, 100, 1);
    
    std::vector<Object> objects;
    
    camera.calculatePixels();
    trace();
        
            
    glutDisplayFunc(display);
    //glutKeyboardFunc(tasten);
    glutMainLoop();
    return 0;
}

















