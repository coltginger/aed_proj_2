#include "FileManager.h"
#include <sstream>
#include <fstream>
using namespace std;

FileManager::FileManager() {
    _airportsfile = fileToVector("../src/csv/airports.csv");
    _airlinesfile = fileToVector("../src/csv/airlines.csv");
    _flightsfile = fileToVector("../src/csv/flights.csv");
}

void FileManager::setAirportsFile(vector<std::string> airportsfile) {
    _airportsfile = airportsfile;
}

void FileManager::setAirlinesFile(vector<std::string> airlinesfile) {
    _airlinesfile = airlinesfile;
}

void FileManager::setFlightsFile(vector<std::string> flightsfile) {
    _flightsfile = flightsfile;
}

vector<string> FileManager::getAirportsFile() {
    return _airportsfile;
}

vector<string> FileManager::getAirlinesFile() {
    return _airlinesfile;
}

vector<string> FileManager::getFlightsFile() {
    return _flightsfile;
}


vector<string> FileManager::fileToVector(std::string filename) {
    vector<string> res;

    ifstream file;
    file.open(filename);
    string line;
    string word;
    getline(file, line);

    while(getline(file,line)){
        stringstream ss(line);

        while(getline(ss, word, ',')) res.push_back(word);

    }
    return res;
}