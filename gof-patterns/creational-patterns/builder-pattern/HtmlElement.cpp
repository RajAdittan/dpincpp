//
// Created by rajam on 8/19/2018.
//

#include "HtmlElement.h"
#include "HtmlBuilder.h"

#include <sstream>

HtmlElement::HtmlElement(string &name, string &text) {
    this->name = name;
    this->text = text;
}

const string &HtmlElement::getName() const {
    return name;
}

void HtmlElement::setName(const string &name) {
    HtmlElement::name = name;
}

const string &HtmlElement::getText() const {
    return text;
}

void HtmlElement::setText(const string &text) {
    HtmlElement::text = text;
}

void HtmlElement::add_element(const HtmlElement & element) {
    elements.emplace_back(element);
}

HtmlBuilder HtmlElement::create(string root_name) {
    return HtmlBuilder(root_name);
}

string HtmlElement::to_string(int indent) const {
    ostringstream oss;
    string indent_space(indent_sz*indent, ' ');
    oss << indent_space << "<" << name << ">" << endl;
    if(text.size() > 0) {
        oss << string(indent_sz*(indent+1), ' ') << text << endl;
    }
    for(const auto & elem : elements) {
        oss << elem.to_string(indent + 1);
    }
    oss << indent_space << "</" << name << ">" << endl;
    return oss.str();
}