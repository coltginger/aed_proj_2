#include <string>
using namespace std;

#ifndef AED_PROJ_2_FLIGHT_H
#define AED_PROJ_2_FLIGHT_H

/**
 * @brief Class to store information about a certain Flight, including its source, target and airline
 */
class Flight {
private:
    string _source;
    string _target;
    string _airline;

public:
    Flight(string source, string target, string airline);
    Flight();

    string getSource();
    string getTarget();
    string getAirline();
};


#endif //AED_PROJ_2_FLIGHT_H
