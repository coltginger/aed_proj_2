#include "Airline.h"

/**
 * @brief Constructor for Airline that sets code, name, callsign and country
 * @details Time complexity O(1)
 * @param code The airline's code
 * @param name The airline's name
 * @param callsign The airline's call sign
 * @param country The airline's country
 */
Airline::Airline(std::string code, std::string name, std::string callsign, std::string country) {
    _code = code;
    _name = name;
    _callsign = callsign;
    _country = country;
}

/**
 * @brief Default constructor for Airline
 * @details Time complexity O(1)
 */
Airline::Airline() {
    _code = "";
    _name = "";
    _callsign = "";
    _country =  "";
}

/**
 * @brief Returns the airline's code
 * @details Time complexity O(1)
 * @return _code
 */
string Airline::getCode() {
    return _code;
}

/**
 * @brief Returns the airline's name
 * @details Time complexity O(1)
 * @return _name
 */
string Airline::getName() {
    return _name;
}

/**
 * @brief Returns the airline's call sign
 * @details Time complexity O(1)
 * @return _callsign
 */
string Airline::getCallsign() {
    return _callsign;
}

/**
 * @brief Returns the airline's country
 * @details Time complexity O(1)
 * @return _country
 */
string Airline::getCountry() {
    return _country;
}