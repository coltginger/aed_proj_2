#include <string>
using namespace std;

#ifndef AED_PROJ_2_FLIGHT_H
#define AED_PROJ_2_FLIGHT_H

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
