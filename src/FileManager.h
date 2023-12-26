#include <string>
#include <vector>
using namespace std;
#ifndef AED_PROJ_2_FILEMANAGER_H
#define AED_PROJ_2_FILEMANAGER_H


class FileManager {
private:
    vector<string> _airportsfile;
    vector<string> _airlinesfile;
    vector<string> _flightsfile;

public:
    FileManager();

    void setAirportsFile(vector<string> airportsfile);
    void setAirlinesFile(vector<string> airlinesfile);
    void setFlightsFile(vector<string> flightsfile);

    vector<string> getAirportsFile();
    vector<string> getAirlinesFile();
    vector<string> getFlightsFile();

    vector<string> fileToVector(string filename);
};


#endif //AED_PROJ_2_FILEMANAGER_H
