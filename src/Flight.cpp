#include "Flight.h"

/**
 * @brief Constructor for Flight class, sets source, target and airline
 * @details Time complexity O(1)
 * @param source Origin of the flight
 * @param target Destination for the flight
 * @param airline Call sign of the airline responsible for the flight
 */
Flight::Flight(std::string source, std::string target, std::string airline) {
    _source = source;
    _target = target;
    _airline = airline;
}

/**
 * @brief Default constructor for Flight class, all fields are set as empty strings
 * @details Time complexity O(1)
 */
Flight::Flight() {
    _source = "";
    _target = "";
    _airline = "";
}

/**
 * @brief Getter function for _source field
 * @details Time complexity O(1)
 * @return _source
 */
string Flight::getSource() {
    return _source;
}

/**
 * @brief Getter function for _target field
 * @details Time complexity O(1)
 * @return _target
 */
string Flight::getTarget() {
    return _target;
}

/**
 * @brief Getter function for _airline field
 * @details Time complexity O(1)
 * @return _airline
 */
string Flight::getAirline() {
    return _airline;
}