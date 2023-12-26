#include <string>
using namespace std;

#ifndef AED_PROJ_2_AIRPORT_H
#define AED_PROJ_2_AIRPORT_H


class Airport {
private:
    string _code;
    string _name;
    string _city;
    string _country;
    float _latitude;
    float _longitude;


public:
    Airport(string code, string name, string city, string country, float latitude, float longitude);
    Airport();
    string getCode();
    string getName();
    string getCity();
    string getCountry();
    float getLatitude();
    float getLongitude();
};


#endif //AED_PROJ_2_AIRPORT_H
