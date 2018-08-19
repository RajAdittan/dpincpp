//
// Created by rajam on 8/20/2018.
//

#ifndef ABSTRACTFACTORY_PATTERN_VEHICLE_H
#define ABSTRACTFACTORY_PATTERN_VEHICLE_H

#include <string>
using namespace std;

struct vehicle {
    virtual string description() const = 0;
};

struct cycle : public vehicle {
    string description() const override {
        return "A bicycle, also called a cycle or bike, is a human-powered, pedal-driven, single-track vehicle, having two wheels attached to a frame, one behind the other.";
    }
};

struct car : public vehicle {
    string description() const override {
        return "A car is a wheeled motor vehicle used for transportation. Most definitions of car say they run primarily on roads, seat one to eight people, have four tires, and mainly transport people rather than goods.";
    }
};

struct bus : public vehicle {
    string description() const override {
        return "A bus is a road vehicle designed to carry many passengers. Buses can have a capacity as high as 300 passengers.";
    }
};


#endif //ABSTRACTFACTORY_PATTERN_VEHICLE_H
