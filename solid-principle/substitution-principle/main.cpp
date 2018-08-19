//
// Created by rajam on 8/18/2018.
//
#include <iostream>
using namespace std;

#include "Circle.h"
#include "Triangle.h"

#include "Canvas.h"

int main(int argc, char* argv[]) {

    Canvas canvas;

    //draw a triangle
    Triangle triangle;
    canvas.draw(&triangle);

    //draw a ellipse
    Ellipse ellipse;
    canvas.draw(&ellipse);

    //substitute a derived class with new functionality for a base class

    //draw a circle
    Circle circle;
    canvas.draw(&circle);

    return 0;
}
