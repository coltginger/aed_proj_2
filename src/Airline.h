#include <string>
using namespace std;
#ifndef AED_PROJ_2_AIRLINE_H
#define AED_PROJ_2_AIRLINE_H

/**
 * @brief Class to store information about a certain Airline, including its code, name, callsign and country
 */
class Airline {
private:
    string _code;
    string _name;
    string _callsign;
    string _country;

public:
    Airline(string code, string name, string callsign, string country);
    Airline();

    string getCode();
    string getName();
    string getCallsign();
    string getCountry();
};


#endif //AED_PROJ_2_AIRLINE_H
