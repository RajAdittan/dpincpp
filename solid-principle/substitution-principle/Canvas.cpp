//
// Created by rajam on 8/18/2018.
//

#include "Canvas.h"


void Canvas::draw(const Shape* shape) {
    if(nullptr == shape) return;
    shape->draw();
}