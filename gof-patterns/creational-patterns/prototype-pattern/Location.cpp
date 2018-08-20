//
// Created by rajam on 8/20/2018.
//

#include "Location.h"

const string &Location::getCode() const {
    return code;
}

void Location::setCode(const string &code) {
    Location::code = code;
}

const string &Location::getBuilding() const {
    return building;
}

void Location::setBuilding(const string &building) {
    Location::building = building;
}

const string &Location::getCity() const {
    return city;
}

void Location::setCity(const string &city) {
    Location::city = city;
}

const string &Location::getCountry() const {
    return country;
}

void Location::setCountry(const string &country) {
    Location::country = country;
}

Location::Location(const string &code) : code(code) {}

Location::Location(const Location& other)
: code(other.code), building(other.building), city(other.city), country(other.country) {

}

ostream &operator<<(ostream &os, const Location &location) {
    os << "code: " << location.code << "\n building: " << location.building << "\n city: " << location.city << "\n country: "
       << location.country << '\n';
    return os;
}
