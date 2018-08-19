//
// Created by rajam on 8/18/2018.
//

#include <iostream>
#include <vector>

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
    void add_parent_and_child(const Person& parent, const Person& child) {
        relations.push_back({parent, Relationship ::parent, child});
        relations.push_back({child, Relationship ::child, parent});
    }
};

struct RelationshipVisitor {
    void visit(Relationships relationships) const {
        for(auto && relation [first, relative, second]: relationships.relations) {
            cout << relation->first << "is " << relation->relative << " to " << relation->second << endl;
        }
    }
};

int main(int argc, char* argv[]) {
    Person parent{"Johnson"};
    Person child1{"Chris"}, child2{"Mathew"};

    Relationships relationships;

    relationships.add_parent_and_child(parent, child1);
    relationships.add_parent_and_child(parent, child2);
    RelationshipVisitor visitor;
    visitor.visit(relationships);
    return 0;
}