//
// Created by rajam on 8/20/2018.
//

#include <iostream>
using namespace std;
#include "HostFactory.h"
#include <boost/serialization/serialization.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

using namespace boost;
using namespace boost::serialization;
using namespace boost::archive;

template <typename T>
struct Cloneable {
    virtual T clone() = 0;
};

class CloneHost : public Cloneable<Host> {
public:
    CloneHost(Host &host) : host(host) {
    }
    Host clone() override {
        auto h = Host(host.getDomain(), host.getLocation());
        h.setAddress(host.getDomain()->nextAvailable());
        return h;
    }

private:
    Host& host;
};

int main(int argc, char* argv[]) {

    HostFactory* hf = new HostFactory();

    auto h1 = hf->create("AWS");
    auto h2 = hf->create("GCP");
    auto h3 = hf->create("AZ");

    cout << *h1 << endl << *h2 << endl << *h3 << endl;

    auto h11 = hf->create("AWS");
    auto h21 = hf->create("GCP");
    auto h31 = hf->create("AZ");

    cout << *h11 << endl << *h21 << endl << *h31 << endl;

    auto h22 = CloneHost{*h11}.clone();

    cout << "using clone:\n" << h22 << endl;

    return 0;
}

