//
// Created by rajam on 8/19/2018.
//

#include <iostream>
using namespace std;

#include "HtmlBuilder.h"

int main() {

    // builder
    HtmlBuilder htmlBuilder {"ul"};
    htmlBuilder.add_child("li", "hello world");
    htmlBuilder.add_child("li", "hi there");

    cout << htmlBuilder.to_string() << endl;

    //fluidic builder
    HtmlElement elem = HtmlElement::create("ul")
            .plus_child("li", "hello")
            .plus_child("li", "world")
            .build();

    cout << elem.to_string() << endl;

    return 0;
}