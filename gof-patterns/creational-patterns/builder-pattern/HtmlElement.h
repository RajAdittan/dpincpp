//
// Created by rajam on 8/19/2018.
//

#ifndef BUILDER_PATTERN_HTMLELEMENT_H
#define BUILDER_PATTERN_HTMLELEMENT_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class HtmlBuilder;

class HtmlElement {
public:
    HtmlElement(string &name, string &text);

    const string &getName() const;

    void setName(const string &name);

    const string &getText() const;

    void setText(const string &text);

    void add_element(const HtmlElement & element);

    static HtmlBuilder create(string root_name);

    string to_string(int indent = 0) const;

private:
    HtmlElement() = default;
    friend HtmlBuilder;
private:
    string name;
    string text;
    vector<HtmlElement> elements;
    const size_t indent_sz = 2;
};


#endif //BUILDER_PATTERN_HTMLELEMENT_H
