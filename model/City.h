//
// Created by Hamed Cédric Sylla on 14/02/2023.
//

#include <iostream>
#ifndef CHALLENGE_TSP_CITY_H
#define CHALLENGE_TSP_CITY_H

using namespace std;

class City {
protected:
    string name;
    double latitude;
    double longitude;
public:
    City(string name, double latitude, double longitude);

    const string &getName() const;

    void setName(const string &name);

    float getLatitude() const;

    void setLatitude(float latitude);

    float getLongitude() const;

    void setLongitude(float longitude);
};


#endif //CHALLENGE_TSP_CITY_H
