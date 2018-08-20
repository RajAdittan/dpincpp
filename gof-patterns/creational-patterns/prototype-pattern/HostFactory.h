//
// Created by rajam on 8/20/2018.
//

#ifndef PROTOTYPE_PATTERN_HOSTFACTORY_H
#define PROTOTYPE_PATTERN_HOSTFACTORY_H

#include "Domain.h"
#include "Location.h"
#include "Host.h"

class HostFactory {
public:
    HostFactory();
    Host* create(string code);

private:
    void resolve_location(Location* location);
private:
    Domain* aws_d;
    Domain* gcp_d;
    Domain* azure_d;
    Domain* digital_d;

    Location* aws_l;
    Location* gcp_l;
    Location* azure_l;
    Location* digital_l;
};

#endif //PROTOTYPE_PATTERN_HOSTFACTORY_H
