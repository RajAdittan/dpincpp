//
// Created by rajam on 8/18/2018.
//

#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

enum class Relationship {
    parent,
    child,
    sibling,
    spouse
};

struct Person {
    string name;
};

struct Relationships {
    vector<tuple<Person, Relationship, Person>> relations;

    Relationships() = default;

    void add_parent_and_child(const Person& parent, const Person& child) {
        relations.push_back(make_tuple(parent, Relationship::parent, child));
        relations.push_back(make_tuple(child, Relationship ::child, parent));
    }
};

struct RelationshipVisitor {
    void visit(Relationships relationships) const {
        for(auto && relation : relationships.relations) {
            cout << get<0>(relation).name << "is " << (int)get<1>(relation) << " to " << get<2>(relation).name << endl;
        }
    }
};

int main(int argc, char* argv[]) {
    Person parent{"Johnson"};
    Person child1{"Chris"}, child2{"Mathew"};

    Relationships relationships = Relationships();

    relationships.add_parent_and_child(parent, child1);
    relationships.add_parent_and_child(parent, child2);
    RelationshipVisitor visitor;
    visitor.visit(relationships);
    return 0;
}