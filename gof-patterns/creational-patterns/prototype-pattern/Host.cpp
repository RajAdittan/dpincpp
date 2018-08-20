//
// Created by rajam on 8/20/2018.
//

#include "Host.h"

Host::Host(Domain *domain, Location *location)
// copy constructor does deep copy
// : domain( new Domain{*domain} ), location(new Location{*location} )
: domain(domain), location(location)
{
}

IpAddress *Host::getAddress() const {
    return address;
}

void Host::setAddress(IpAddress *address) {
    Host::address = address;
}

Domain *Host::getDomain() const {
    return domain;
}

Location *Host::getLocation() const {
    return location;
}

Host::~Host() {
    delete address;
}

ostream &operator<<(ostream &os, const Host &host) {
    os << "domain: " << *host.domain << "location: " << *host.location << "address: " << *host.address;
    return os;
}
