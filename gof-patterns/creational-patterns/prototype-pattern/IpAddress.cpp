//
// Created by rajam on 8/20/2018.
//

#include "IpAddress.h"

IpAddress::IpAddress(short a, short b, short c, short d) : a(a), b(b), c(c), d(d) {}

std::ostream &operator<<(std::ostream &os, const IpAddress &address) {
    os << "ip: " << address.getA() << "." << address.getB() << "." << address.getC() << "." << address.getD() << '\n';
    return os;
}

short IpAddress::getA() const {
    return a;
}

short IpAddress::getB() const {
    return b;
}

short IpAddress::getC() const {
    return c;
}

short IpAddress::getD() const {
    return d;
}
