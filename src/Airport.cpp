#include "Airport.h"

/**
 * @brief Constructor for Airport that sets code, name, callsign, country, latitude and longitude
 * @details Time complexity O(1)
 * @param code The airport's code
 * @param name The airport's name
 * @param city The airport's city
 * @param country The airport's country
 * @param latitude The airport's latitude
 * @param longitude The airport's longitude
 */
Airport::Airport(std::string code, std::string name, std::string city, std::string country, float latitude,
                 float longitude) {
    _code = code;
    _name = name;
    _city = city;
    _country = country;
    _latitude = latitude;
    _longitude = longitude;
}

/**
 * @brief Default constructor for Airport that sets code, name, callsign, country, latitude and longitude
 * @details Time complexity O(1)
 */
Airport::Airport() {
    _code = "";
    _name = "";
    _city = "";
    _country = "";
    _latitude = 0;
    _longitude = 0;
}

/**
 * @brief Getter function for _code field
 * @details Time complexity O(1)
 * @return _code
 */
string Airport::getCode() {
    return _code;
}

/**
 * @brief Getter function for _name field
 * @details Time complexity O(1)
 * @return _name
 */
string Airport::getName() {
    return _name;
}

/**
 * @brief Getter function for _city field
 * @details Time complexity O(1)
 * @return _city
 */
string Airport::getCity() {
    return _city;
}

/**
 * @brief Getter function for _country field
 * @details Time complexity O(1)
 * @return _country
 */
string Airport::getCountry() {
    return _country;
}

/**
 * @brief Getter function for _latitude field
 * @details Time complexity O(1)
 * @return _latitude
 */
float Airport::getLatitude() {
    return _latitude;
}

/**
 * @brief Getter function for _longitude field
 * @details Time complexity O(1)
 * @return _longitude
 */
float Airport::getLongitude() {
    return _longitude;
}

/**
 * @brief Calculates the distance from this airport to the given coordinates
 * @details Time complexity O(1)
 * @param latitude The latitude of the location to calculate the distance to
 * @param longitude The longitude of the location to calculate the distance to
 * @return The distance in kilometers from this airport to the given coordinates
 */
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

/**
 * @brief Checks if two Airports match the exact same values
 * @details Time complexity O(1)
 * @param other
 * @return True if all attributes match
 */
bool Airport::operator==(const Airport &other) const {
    return _code == other._code &&
           _name == other._name &&
           _city == other._city &&
           _country == other._country &&
           _latitude == other._latitude &&
           _longitude == other._longitude;
}