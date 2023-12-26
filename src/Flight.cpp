#include "Flight.h"

Flight::Flight(std::string source, std::string target, std::string airline) {
    _source = source;
    _target = target;
    _airline = airline;
}

Flight::Flight() {
    _source = "";
    _target = "";
    _airline = "";
}

string Flight::getSource() {
    return _source;
}

string Flight::getTarget() {
    return _target;
}

string Flight::getAirline() {
    return _airline;
}