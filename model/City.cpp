//
// Created by Hamed Cédric Sylla on 14/02/2023.
//

#include "City.h"

const string &City::getName() const {
    return name;
}

void City::setName(const string &name) {
    City::name = name;
}

float City::getLatitude() const {
    return latitude;
}

void City::setLatitude(float latitude) {
    City::latitude = latitude;
}

float City::getLongitude() const {
    return longitude;
}

void City::setLongitude(float longitude) {
    City::longitude = longitude;
}

City::City(string name, double latitude, double longitude) {
    this->name = name;
    this->latitude = latitude;
    this->longitude = longitude;

}
