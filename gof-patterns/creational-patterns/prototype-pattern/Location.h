//
// Created by rajam on 8/20/2018.
//

#ifndef PROTOTYPE_PATTERN_LOCATION_H
#define PROTOTYPE_PATTERN_LOCATION_H

#include <string>
#include <ostream>

using namespace std;

class Location {
public:
    Location(const string &code);
    Location(const Location& other);

    const string &getCode() const;

    void setCode(const string &code);

    const string &getBuilding() const;

    void setBuilding(const string &building);

    const string &getCity() const;

    void setCity(const string &city);

    const string &getCountry() const;

    void setCountry(const string &country);

    friend ostream &operator<<(ostream &os, const Location &location);

private:
    string code;
    string building;
    string city;
    string country;
};


#endif //PROTOTYPE_PATTERN_LOCATION_H
