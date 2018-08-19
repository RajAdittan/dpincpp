//
// Created by rajam on 8/20/2018.
//

#include "vehicle.h"
#include "factory.h"

#include <iostream>
using namespace std;

unique_ptr<vehicle> make_vehicle(string type) {
    unique_ptr<vehicle> _vehicle;
    if(type=="car") {
        _vehicle = make_unique<car>();
    } else if(type == "cycle") {
        _vehicle = make_unique<cycle>();
    }
    return _vehicle;
}

int main(int argc, char* argv[]) {

    {
        auto vehicle1 = make_vehicle("cycle");
        cout << vehicle1->description() << endl;
    }

    // abstract factory
    MotorFactory motorFactory;
    motorFactory.register_factories();
    auto car = motorFactory.make_vehicle("car");
    cout << car->description() << endl;

    factory* factory1 = new bus_factory();
    auto bus = factory1->make();
    cout << bus->description() << endl;

    return 0;
}