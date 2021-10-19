//
// Created by Jannes Van Goeye on 25/10/2019.
//

#ifndef UNTITLED1_ENVIRONMENT_H
#define UNTITLED1_ENVIRONMENT_H

using namespace std;

#include <utility>
#include <vector>

#include "Ray.h"
#include "Intersection.h"
#include "RTColor.h"
#include "Sphere.h"
#include "Square.hpp"
#include "LightSource.hpp"

class Environment {
public:
    RTColor backgroundColor;
    std::vector<Object*> objects;
    std::vector<Lightsource> lightsources;

    Environment() {
        backgroundColor = RTColor(0, 0, 0);
        Transformation sqrMatrix;
        /*vector<vector<double>>  squareMatrix =
        { {2,0,0,0}, {0,cos(0.1),-sin(0.1),0}, {0,sin(0.1),cos(0.1), -3}, {0, 0, 0, 1} };*/
        vector<vector<double>>  squareMatrix =
        { {1,0,0,-10}, {0,1,0,0}, {0,0,1,-5}, {0, 0, 0, 1} };
        sqrMatrix.matrix = squareMatrix;
        Sphere* sphere1 = new Sphere(Vec3(0,0,0),2, RTColor(255, 0, 0), SPIEGELEND);
        Sphere* sphere2 = new Sphere(Vec3(0,0,0),2, RTColor(150, 150, 150), SPIEGELEND);
        Sphere* sphere3 = new Sphere(Vec3(0,0,0),2, RTColor(130, 80, 200), SPIEGELEND);
        Sphere* sphere4 = new Sphere(Vec3(0,0,0),2, RTColor(30, 255, 255), SPIEGELEND);
        Sphere* sphere5 = new Sphere(Vec3(0,0,0),2, RTColor(238, 125, 0), SPIEGELEND);

        Square* vlak1 = new Square(Vec3(0,0,0), RTColor(0, 0, 0), SPIEGELEND);
        Square* vlak2 = new Square(Vec3(0,0,0), RTColor(255, 0, 255), SPIEGELEND);
        Square* vlak3 = new Square(Vec3(0,0,0), RTColor(0, 255, 255), SPIEGELEND);
        Square* vlak4 = new Square(Vec3(0,0,0), RTColor(255, 0, 0), MAT);
        Square* vlak5 = new Square(Vec3(0,0,0), RTColor(0, 0, 255), MAT);
        Square* vlak6 = new Square(Vec3(0,0,0), RTColor(255, 0, 0), MAT);
        Square* vlak7 = new Square(Vec3(0,0,0), RTColor(0, 255, 0), MAT);
        Square* vlak8 = new Square(Vec3(0,0,0), RTColor(0, 0, 255), MAT);


        Lightsource light1 = Lightsource(Vec3(-7, -3, 2), RTColor(255,255,255));
        Lightsource light2 = Lightsource(Vec3(0, 0, 0), RTColor(255,255,255));
        /*Lightsource light3 = Lightsource(Vec3(0, 0, 0), RTColor(255,255,255));
        Lightsource light4 = Lightsource(Vec3(-5, 0, -7), RTColor(255,255,255));
        Lightsource light5 = Lightsource(Vec3(5, 0, -10), RTColor(255,255,255));*/

        sphere1->translation(-3, 0, -4);
        sphere1->scaleXY(1);
        sphere2->translation(1, -0, -4);
        sphere3->translation(1, 1, -2);
        sphere4->translation(3, -1.5, -2);
        sphere5->translation(0, -3, -4);

        vlak1->translation(-1, -4, -7);
        vlak1->scaleXY(0.3);
        vlak2->translation(1, 0, 3);
        vlak2->scaleXY(0.3);
        //vlak3->rotateX(2.1);
        vlak3->scaleXY(5);
        vlak3->translation(0, 0, -5);
        vlak4->translation(0, 0, -99);
        vlak4->scaleXY(0.08);
        vlak5->translation(3, 0, -98);
        vlak5->scaleXY(0.08);
        vlak6->translation(3, 0, -98);
               vlak6->scaleXY(0.08);
        vlak7->translation(0, -3, -98);
               vlak7->scaleXY(0.08);
        vlak8->translation(0, 3, -98);
               vlak8->scaleXY(0.08);


        //objects.push_back(new Square(Vec3(0,0,0), sqrMatrix, RTColor(120, 50, 20), REFLECTEREND));

        objects.push_back(sphere1);
        objects.push_back(sphere2);
        objects.push_back(sphere3);
        objects.push_back(sphere4);
        objects.push_back(sphere5);
        //objects.push_back(vlak1);
        //objects.push_back(vlak2);
        objects.push_back(vlak3);
        objects.push_back(vlak4);
        objects.push_back(vlak5);
        objects.push_back(vlak6);
        objects.push_back(vlak7);
        objects.push_back(vlak8);

        lightsources.push_back(light1);
        lightsources.push_back(light2);
        /*lightsources.push_back(light3);
        lightsources.push_back(light4);
        lightsources.push_back(light5);*/


        /*objects.push_back(new Sphere(RTPoint(1,1,200),50));
        objects.push_back(new Sphere(RTPoint(1,200,1),50));
        objects.push_back(new Sphere(RTPoint(200,1,1),50));
        objects.push_back(new Sphere(RTPoint(-200,1,1),50));*/

    }
    
    void add(Object *object) {
        objects.push_back(object);
    }
    
    void add(Lightsource light) {
        lightsources.push_back(light);
    }

    RTColor trace(const Ray& ray, int depth); // Deze functie doed hetzelfde als de "shade" functie in het handboek
    Intersection getFirstHit(const Ray& ray);
    RTColor shading(const Ray& ray, Intersection intersection, int depth);
    bool check_occlusion(Vec3 target, Vec3 source);
};


#endif //UNTITLED1_ENVIRONMENT_H
