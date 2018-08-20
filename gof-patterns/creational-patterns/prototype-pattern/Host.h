//
// Created by rajam on 8/20/2018.
//

#ifndef PROTOTYPE_PATTERN_HOST_H
#define PROTOTYPE_PATTERN_HOST_H

#include <ostream>
#include "Domain.h"
#include "Location.h"
#include "IpAddress.h"

class Host {

private:
    Domain* domain;
    Location* location;
    IpAddress* address;
public:
    // domain is a prototype
    // location is a prototype
    Host(Domain *domain, Location *location);
    virtual ~Host();

    IpAddress *getAddress() const;
    void setAddress(IpAddress *address);
    Domain *getDomain() const;
    Location *getLocation() const;

    friend ostream &operator<<(ostream &os, const Host &host);
};


#endif //PROTOTYPE_PATTERN_HOST_H
