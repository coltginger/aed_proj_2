#include "Airport.h"

Airport::Airport(std::string code, std::string name, std::string city, std::string country, float latitude,
                 float longitude) {
    _code = code;
    _name = name;
    _city = city;
    _country = country;
    _latitude = latitude;
    _longitude = longitude;
}

Airport::Airport() {
    _code = "";
    _name = "";
    _city = "";
    _country = "";
    _latitude = 0;
    _longitude = 0;
}

string Airport::getCode() {
    return _code;
}

string Airport::getName() {
    return _name;
}

string Airport::getCity() {
    return _city;
}

string Airport::getCountry() {
    return _country;
}

float Airport::getLatitude() {
    return _latitude;
}

float Airport::getLongitude() {
    return _longitude;
}

double Airport::getDistance(float latitude, float longitude) {
    double lat1 = _latitude * M_PI / 180.0;
    double lon1 = _longitude * M_PI / 180.0;
    double lat2 = latitude * M_PI / 180.0;
    double lon2 = longitude * M_PI / 180.0;

    double dLat = lat2 - lat1;
    double dLon = lon2 - lon1;

    double a = std::sin(dLat / 2) * std::sin(dLat / 2) +
               std::cos(lat1) * std::cos(lat2) *
               std::sin(dLon / 2) * std::sin(dLon / 2);

    double c = 2 * std::atan2(std::sqrt(a), std::sqrt(1 - a));
    double distance = EARTH_RADIUS_KM * c;
    return distance;
}

bool Airport::operator==(const Airport &other) const {
    return _code == other._code &&
           _name == other._name &&
           _city == other._city &&
           _country == other._country &&
           _latitude == other._latitude &&
           _longitude == other._longitude;
}