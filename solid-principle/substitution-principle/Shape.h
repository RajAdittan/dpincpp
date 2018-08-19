//
// Created by rajam on 8/18/2018.
//

#ifndef SUBSTITUTION_PRINCIPLE_SHAPE_H
#define SUBSTITUTION_PRINCIPLE_SHAPE_H

class Shape {
public:
    virtual ~Shape() = default;
    virtual void draw() const = 0;
};

#endif //SUBSTITUTION_PRINCIPLE_SHAPE_H
