//
// Created by rajam on 8/20/2018.
//

#ifndef PROTOTYPE_PATTERN_DOMAIN_H
#define PROTOTYPE_PATTERN_DOMAIN_H

#include <string>
#include <ostream>
#include "IpAddress.h"

using namespace std;

class Domain {

private:
    string name;
public:
    Domain(const string &name, short ipA, short ipB, short ipC, short ipD);
    Domain(const Domain& other);

    IpAddress* nextAvailable();

public:
    const string &getName() const;
    void setName(const string &name);
    friend ostream &operator<<(ostream &os, const Domain &domain);

private:
    IpAddress prototypeAddress;
};


#endif //PROTYPE_PATTERN_DOMAIN_H
