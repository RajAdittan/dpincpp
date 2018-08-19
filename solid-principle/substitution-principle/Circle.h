//
// Created by rajam on 8/18/2018.
//

#ifndef SUBSTITUTION_PRINCIPLE_CIRCLE_H
#define SUBSTITUTION_PRINCIPLE_CIRCLE_H

#include "Shape.h"

class Ellipse : public Shape {
    void draw() const override {
        cout << "Shape::Ellipse::draw" << endl;
    }
};

class Circle : public Ellipse {
public:
    void draw() const override {
        cout << "Shape::Ellipse::Circle::draw" << endl;
    }
};

#endif //SUBSTITUTION_PRINCIPLE_CIRCLE_H
