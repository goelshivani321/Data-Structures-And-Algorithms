//
// Created by shivani goel on 3/17/18.
//

#include "City.h"

const string &City::getName() const {
    return name;
}

const string &City::getState() const {
    return state;
}

const Coordinate &City::getCoordinate() const {
    return coordinate;
}

istream &operator>>(istream &ins, City &city) {
    getline(ins,city.name,',');
    getline(ins,city.state,',');
    string lat,lon;

    getline(ins,lat,',');
    getline(ins,lon);

    city.coordinate.set_latitude(stod(lat));
    city.coordinate.set_longitude(stod(lon));
    return ins;
}

ostream &operator<<(ostream &outs, const City &city) {
    outs << "*" << city.name << " " << city.state;
    return outs;
}

City::~City() {

}
