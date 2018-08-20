//
// Created by rajam on 8/20/2018.
//

#include "Domain.h"

const string &Domain::getName() const {
    return name;
}

void Domain::setName(const string &name) {
    Domain::name = name;
}

Domain::Domain(const string &name, short ipA, short ipB, short ipC, short ipD)
: name(name), prototypeAddress(ipA,ipB,ipC,ipD) {}

Domain::Domain(const Domain& other)
: name(other.name), prototypeAddress(
        other.prototypeAddress.getA(),
        other.prototypeAddress.getB(),
        other.prototypeAddress.getC(),
        other.prototypeAddress.getD() ){}

IpAddress* Domain::nextAvailable() {
    prototypeAddress = prototypeAddress.next();
    return new IpAddress(prototypeAddress);
}

ostream &operator<<(ostream &os, const Domain &domain) {
    os << "name: " << domain.name << '\n';
    return os;
}
