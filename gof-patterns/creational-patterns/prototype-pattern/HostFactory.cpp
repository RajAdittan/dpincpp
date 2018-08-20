//
// Created by rajam on 8/20/2018.
//

#include "HostFactory.h"

HostFactory::HostFactory() {
    // prototype domains
    aws_d = new Domain{"aws.amazon.com",10,11,0,0};
    gcp_d = new Domain{"cloud.google.com",8,8,0,0};
    azure_d = new Domain{"azure.microsoft.com",172,168,0,0};
    digital_d = new Domain{"cloud.digitalocean.com",92,88,0,0};

    // prototype locations
    aws_l = new Location{"AWS"};
    gcp_l = new Location{"GCP"};
    azure_l = new Location{"AZ"};
    digital_l = new Location{"DO"};

    resolve_location(aws_l);
    resolve_location(gcp_l);
    resolve_location(azure_l);
    resolve_location(digital_l);
}


Host* HostFactory::create(string code) {
    if(code == "AWS") {
        auto host = new Host{aws_d, aws_l};
        host->setAddress(aws_d->nextAvailable());
        return host;
    }
    if(code == "GCP") {
        auto host = new Host{gcp_d, gcp_l};
        host->setAddress(gcp_d->nextAvailable());
        return host;
    }
    if(code == "AZ") {
        auto host = new Host{azure_d, azure_l};
        host->setAddress(azure_d->nextAvailable());
        return host;
    }
    if(code == "DO") {
        auto host = new Host{digital_d, digital_l};
        host->setAddress(digital_d->nextAvailable());
        return host;
    }
}

void HostFactory::resolve_location(Location* location) {
    location->setCity("Singapore");
    location->setCountry("Singapore");
    if(location->getCode() == "AWS") {
        location->setBuilding("Central Business District, Singapore Social Hub");
    }
    if(location->getCode() == "GCP") {
        location->setBuilding("Central Business District, Google");
    }
    if(location->getCode() == "AZ") {
        location->setBuilding("Central Business District, Microsoft");
    }
    if(location->getCode() == "DO") {
        location->setBuilding("-NA-");
    }
}