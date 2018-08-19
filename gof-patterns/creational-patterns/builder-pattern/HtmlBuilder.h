//
// Created by rajam on 8/19/2018.
//

#ifndef BUILDER_PATTERN_HTMLBUILDER_H
#define BUILDER_PATTERN_HTMLBUILDER_H

#include "HtmlElement.h"

class HtmlBuilder {
public:
    HtmlBuilder(string name);
    void add_child(string name, string text);
    HtmlBuilder& plus_child(string name, string text);

    HtmlElement build();

    operator HtmlElement() const { return root; }

    string to_string() const { return  root.to_string(); }
private:
    HtmlElement root;
};


#endif //BUILDER_PATTERN_HTMLBUILDER_H
