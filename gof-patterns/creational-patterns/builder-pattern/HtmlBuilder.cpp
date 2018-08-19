//
// Created by rajam on 8/19/2018.
//

#include "HtmlBuilder.h"

HtmlBuilder::HtmlBuilder(string name) {
    root.setName(name);
}

HtmlElement HtmlBuilder::build() {
    return root;
}

void HtmlBuilder::add_child(string name, string text) {
    root.add_element( {name, text} );
}

HtmlBuilder& HtmlBuilder::plus_child(string name, string text) {
    root.add_element( {name, text} );
    return *this;
}