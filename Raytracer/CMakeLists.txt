cmake_minimum_required(VERSION 3.15)
project(untitled1)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled1 main.cpp Object.cpp Object.h Vector.cpp Vector.h Ray.cpp Ray.h Vlak.cpp Vlak.h RTPoint.cpp RTPoint.h Sphere.cpp Sphere.h Camera.cpp Camera.h Environment.cpp Environment.h Intersection.cpp Intersection.h HitInfo.cpp HitInfo.h RTColor.cpp RTColor.h Transformation.cpp Transformation.h Pixel.cpp Pixel.h Resolution.cpp Resolution.h Screen.cpp Screen.h RTSize.cpp RTSize.h)