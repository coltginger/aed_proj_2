#include "Airline.h"

Airline::Airline(std::string code, std::string name, std::string callsign, std::string country) {
    _code = code;
    _name = name;
    _callsign = callsign;
    _country = country;
}

Airline::Airline() {
    _code = "";
    _name = "";
    _callsign = "";
    _country =  "";
}

string Airline::getCode() {
    return _code;
}

string Airline::getName() {
    return _name;
}

string Airline::getCallsign() {
    return _callsign;
}

string Airline::getCountry() {
    return _country;
}