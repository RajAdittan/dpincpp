//
// Created by rajam on 8/18/2018.
//

#ifndef SUBSTITUTION_PRINCIPLE_TRIANGLE_H
#define SUBSTITUTION_PRINCIPLE_TRIANGLE_H

#include "Shape.h"

class Triangle : public Shape {
public:
    void draw() const override {
        cout << "Shape::Triangle draw" << endl;
    }
};

#endif //SUBSTITUTION_PRINCIPLE_TRIANGLE_H
