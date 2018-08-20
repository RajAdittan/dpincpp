//
// Created by rajam on 8/20/2018.
//

#ifndef PROTOTYPE_PATTERN_IPADDRESS_H
#define PROTOTYPE_PATTERN_IPADDRESS_H


#include <ostream>
#include <memory>
using namespace std;

class IpAddress {
public:
    IpAddress(short a, short b, short c, short d);

    friend std::ostream &operator<<(std::ostream &os, const IpAddress &address);

private:
    short a;
public:
    short getA() const;

    short getB() const;

    short getC() const;

    short getD() const;

    IpAddress && next() { return move(IpAddress{a,b,c,++d});}

private:
    short b;
    short c;
    short d;
};


#endif //PROTOTYPE_PATTERN_IPADDRESS_H
