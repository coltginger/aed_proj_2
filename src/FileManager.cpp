#include "FileManager.h"
#include <sstream>
#include <fstream>
using namespace std;

/**
 * @brief Default constructor for FileManager
 * @details Time complexity O(1)
 */
FileManager::FileManager() {
    _airportsfile = fileToVector("../src/csv/airports.csv");
    _airlinesfile = fileToVector("../src/csv/airlines.csv");
    _flightsfile = fileToVector("../src/csv/flights.csv");
}

/**
 * @brief Setter function for _airportsfile field
 * @details Time complexity O(1)
 * @param airportsfile
 */
void FileManager::setAirportsFile(vector<std::string> airportsfile) {
    _airportsfile = airportsfile;
}

/**
 * @brief Setter function for _airlinesfile field
 * @details Time complexity O(1)
 * @param airlinesfile
 */
void FileManager::setAirlinesFile(vector<std::string> airlinesfile) {
    _airlinesfile = airlinesfile;
}

/**
 * @brief Setter function for _flightsfile field
 * @details Time complexity O(1)
 * @param flightsfile
 */
void FileManager::setFlightsFile(vector<std::string> flightsfile) {
    _flightsfile = flightsfile;
}

/**
 * @brief Getter function for _airportsfile field
 * @details Time complexity O(1)
 * @return _airportsfile
 */
vector<string> FileManager::getAirportsFile() {
    return _airportsfile;
}

/**
 * @brief Getter function for _airlinesfile field
 * @details Time complexity O(1)
 * @return _airlinesfile
 */
vector<string> FileManager::getAirlinesFile() {
    return _airlinesfile;
}

/**
 * @brief Getter function for _flightsfile field
 * @details Time complexity O(1)
 * @return _flightsfile
 */
vector<string> FileManager::getFlightsFile() {
    return _flightsfile;
}

/**
 * @brief Turns the information in the .csv files into a vector
 * @details Time complexity O(n) with n being the amount of lines in the file. Gets called at the start of run() in App.
 * All strings separated by a comma or by a new line are all a member in the vector
 * @param filename The name of the .csv file
 * @return res, which is the file in vector form
 */
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