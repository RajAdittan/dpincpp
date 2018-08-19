//
// Created by rajam on 8/20/2018.
//

#ifndef ABSTRACTFACTORY_PATTERN_FACTORY_H
#define ABSTRACTFACTORY_PATTERN_FACTORY_H

#include "vehicle.h"
#include <memory>
#include <map>

using namespace std;

struct factory { // abstract factory
    virtual ~factory() = default;
    virtual unique_ptr<vehicle> make() const = 0;
};

struct cycle_factory : public factory { // concrete factory
    unique_ptr<vehicle> make() const override;
};

struct car_factory : public factory {
    unique_ptr<vehicle> make() const override;
};

struct bus_factory : public factory {
    unique_ptr<vehicle> make() const override;
};

class MotorFactory {
public:
    MotorFactory() = default;
    void register_factories () {
        factories["car"] = make_unique<car_factory>();
        factories["cycle"] = make_unique<cycle_factory>();
        factories["bus"] = make_unique<bus_factory>();
    }
    unique_ptr<vehicle> make_vehicle(const string& name) {
        auto vehicle1 = factories[name]->make();
        return vehicle1;
    }
private:
    map<string, unique_ptr<factory>> factories{};
};

#endif //ABSTRACTFACTORY_PATTERN_FACTORY_H
