//
// Created by rajam on 8/20/2018.
//

#include "factory.h"

unique_ptr<vehicle> cycle_factory::make() const {
    return unique_ptr<vehicle>(new cycle());
}

unique_ptr<vehicle> car_factory::make() const {
    return unique_ptr<vehicle>(new car());
}

unique_ptr<vehicle> bus_factory::make() const {
    return unique_ptr<vehicle>(new bus());
}
