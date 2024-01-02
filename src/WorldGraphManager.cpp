#include "WorldGraphManager.h"
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>


using namespace std;

/**
 * @brief Default constructor for the WorldGraphManager class
 * Initializes the WorldGraphManager by creating airports, airlines, and flights
 * @details Time complexity O(n) where n is the maximum size of the airports, airlines, and flights files
 */
WorldGraphManager::WorldGraphManager() {
    makeAirports();
    makeAirlines();
    makeFlights();
}

/**
 * @brief Creates airports from the airports file
 * @details Time complexity O(n) where n is the size of the airports file
 */
void WorldGraphManager::makeAirports() {
    vector<Airport> res;
    auto filevector = _vectors.getAirportsFile();
    for (int i = 0; i < filevector.size(); i+=6){
        string code = filevector[i];
        string name = filevector[i+1];
        string city = filevector[i+2];
        string country = filevector[i+3];
        float latitude = stof(filevector[i+4]);
        float longitude = stof(filevector[i+5]);
        Airport newairport = Airport(code, name, city, country, latitude, longitude);
        _world.addVertex(newairport);
    }
}

/**
 * @brief Creates airlines from the airlines file
 * @details Time complexity O(n) where n is the size of the airports file
 */
void WorldGraphManager::makeAirlines() {
    vector<Airline> res;
    auto filevector = _vectors.getAirlinesFile();
    for (int i = 0; i < filevector.size(); i+=4){
        string code = filevector[i];
        string name = filevector[i+1];
        string callsign = filevector[i+2];
        string country = filevector[i+3];
        Airline newairline = Airline(code, name, callsign, country);
        _airlines.push_back(newairline);
    }
}

/**
 * @brief Creates flights from the flights file
 * @details Time complexity O(n) where n is the size of the airports file
 */
void WorldGraphManager::makeFlights() {
    vector<Flight> res;
    auto filevector = _vectors.getFlightsFile();
    for(int i = 0; i<filevector.size(); i+=3){
        string source = filevector[i];
        string target = filevector[i+1];
        string airline = filevector[i+2];
        Flight newflight = Flight(source, target, airline);
        _flights.push_back(newflight);
    }
    addFlights();
}

/**
 * @brief Adds flights to the world graph
 * @details Time complexity O(n) where n is the number of flights
 */
void WorldGraphManager::addFlights() {
    for(int i = 0; i<_flights.size(); i++){
        Vertex<Airport>* source = airportFinder(_flights[i].getSource());
        Vertex<Airport>* target = airportFinder(_flights[i].getTarget());
        float weight = sqrt(
                pow((source->getInfo().getLongitude() - target->getInfo().getLongitude()), 2) +
                pow((source->getInfo().getLatitude() - target->getInfo().getLatitude()), 2));
        string airl = _flights[i].getAirline();
        _world.addEdge(source->getInfo(), target->getInfo(), weight, airl);
    }
}

/**
 * @brief Returns the number of airports in the world graph
 * @details Time complexity O(1)
 * @return value that corresponds to the number of airports in the world graph
 */
int WorldGraphManager::numberOfAirports() {
    int res = _world.getNumVertex();
    return res;
}

/**
 * @brief Returns the number of flights in the world graph
 * @details Time complexity O(n) where n is the number of airports
 * @return value that corresponds to the number of airports in the world graph
 */
int WorldGraphManager::numberOfFlights() {
    int res = 0;
    for (auto i: _world.getVertexSet()){
        for (auto j : i->getAdj()){
            res++;
        }
    }
    return res;
}

/**
 * @brief Returns the number of flights and airlines in a given airport
 * @details Time complexity O(n) where n is the number of flights in the airport
 * @param source The airport code
 * @return A pair where the first element is the number of flights and the second element is the number of airlines
 */
pair<int, int> WorldGraphManager::numberOfFlightsInAirport(std::string source) {
    pair<int, int> res;
    int res1 = 0;
    vector<string> airlines;
    auto s = airportFinder(source);
    for (auto i : s->getAdj()){
        res1++;
        auto it = find(airlines.begin(), airlines.end(), i.getAirline());
        if(it == airlines.end()){
            airlines.push_back(i.getAirline());
        }
    }
    int res2 = airlines.size();
    res.first = res1;
    res.second = res2;
    return res;
}

/**
 * @brief Returns the number of flights per city
 * @details Time complexity O(n^2) where n is the number of airports
 * @return A vector of pairs where each pair contains a city name and the number of flights from that city
 */
vector<pair<string, int>> WorldGraphManager::numberOfFlightsPerCity() {
    vector<pair<string, int>> res;
    for (auto v : _world.getVertexSet()) {

        for (auto f: v->getAdj()) {
            string target = f.getDest()->getInfo().getCity();
            auto it = std::find_if(res.begin(), res.end(),
                                   [target](const std::pair<string, int> &element) {
                                       return element.first == target;
                                   });
            if (it == res.end()) {
                pair<string, int> newcity;
                newcity.first = f.getDest()->getInfo().getCity();
                newcity.second = 1;
                res.push_back(newcity);
            } else {
                it->second++;
            }
        }

        string target2 = v->getInfo().getCity();
        auto it2 = std::find_if(res.begin(), res.end(),
                               [target2](const std::pair<string, int> &element) {
                                   return element.first == target2;
                               });
        if(it2==res.end()){
            pair<string, int> newcity;
            newcity.first = v->getInfo().getCity();
            newcity.second = v->getAdj().size();
            res.push_back(newcity);
        }
        else{
            it2->second += v->getAdj().size();
        }
    }
    return res;
}

/**
 * @brief Returns the number of flights per airline
 * @details Time complexity O(n) where n is the number of flights
 * @return A vector of pairs where each pair contains an airline name and the number of flights by that airline
 */
vector<pair<string, int>> WorldGraphManager::numberOfFlightsPerAirline() {
    vector<pair<string, int>> res;
    for (auto f : _flights){
        string target = f.getAirline();
        auto it = std::find_if(res.begin(), res.end(),
                               [target](const std::pair<string, int> &element) {
                                   return element.first == target;
                               });
        if (it == res.end()) {
            pair<string, int> newairline;
            newairline.first = f.getAirline();
            newairline.second = 1;
            res.push_back(newairline);
        } else {
            it->second++;
        }
    }
    return res;
}

/**
 * @brief Returns the number of countries an airport has flights to
 * @details Time complexity O(n) where n is the number of flights from the airport
 * @param source The airport code
 * @return The number of countries the airport has flights to
 */
int WorldGraphManager::numberOfCountriesAirport(std::string source) {
    int res;
    vector<string> checked;
    auto v = airportFinder(source);
    for(auto i : v->getAdj()){
        string destcountry = i.getDest()->getInfo().getCountry();
        auto it = find(checked.begin(),checked.end(), destcountry);
        if(it == checked.end()){
            checked.push_back(destcountry);
            res++;
        }
    }
    return res;
}

/**
 * @brief Returns the number of countries a city has flights to
 * @details Time complexity O(n^2) where n is the number of airports
 * @param source The city name
 * @return The number of countries the city has flights to
 */
int WorldGraphManager::numberOfCountriesCity(std::string source) {
    int res;
    vector<string> checked;
    for(auto v : _world.getVertexSet()){
        if (v->getInfo().getCity() == source){
            for(auto i : v->getAdj()){
                string destcountry = i.getDest()->getInfo().getCountry();
                auto it = find(checked.begin(),checked.end(), destcountry);
                if(it == checked.end()){
                    checked.push_back(destcountry);
                    res++;
                }
            }
        }
    }
    return res;
}

/**
 * @brief Returns the number of airports an airport has flights to
 * @details Time complexity O(n) where n is the number of flights from the airport
 * @param source The airport code
 * @return The number of airports the airport has flights to
 */
int WorldGraphManager::numberOfAirportsAirport(std::string source) {
    int res;
    vector<string> checked;
    auto v = airportFinder(source);
    for (auto i : v->getAdj()){
        string destairport = i.getDest()->getInfo().getCode();
        auto it = find(checked.begin(),checked.end(), destairport);
        if(it == checked.end()){
            checked.push_back(destairport);
            res++;
        }
    }
    return res;
}

/**
 * @brief Returns the number of cities an airport has flights to
 * @details Time complexity O(n) where n is the number of flights from the airport
 * @param source The airport code
 * @return The number of cities the airport has flights to
 */
int WorldGraphManager::numberOfCitiesAirport(std::string source) {
    int res;
    vector<string> checked;
    auto v = airportFinder(source);
    for (auto i : v->getAdj()){
        string destcity = i.getDest()->getInfo().getCity();
        auto it = find(checked.begin(),checked.end(), destcity);
        if(it == checked.end()){
            checked.push_back(destcity);
            res++;
        }
    }
    return res;

}

/**
 * @brief Returns the number of airports within a certain distance from a given airport
 * @details Time complexity O(n) where n is the number of airports
 * @param source The airport code
 * @param distance The distance in kilometers
 * @return The number of airports within the given distance
 */
int WorldGraphManager::numberOfAirportsAtX(std::string source, int distance) {
    for (auto i : _world.getVertexSet()) i->setVisited(false);
    vector<Airport> res;
    auto s = airportFinder(source);
    queue<Vertex<Airport>*> q;
    q.push(s);
    s->setVisited(true);
    int level = 0;
    while(!q.empty()){
        int level_size = q.size();
        while (level_size != 0){
            s = q.front();
            q.pop();
            if(level <= distance) res.push_back(s->getInfo());
            for (auto e : s->getAdj()){
                if(!e.getDest()->isVisited()){
                    q.push(e.getDest());
                    e.getDest()->setVisited(true);
                }
            }
            level_size--;
        }
        level++;
    }
    return (res.size());
}

vector<pair<Airport, Airport>> WorldGraphManager::findLongestTrips() {
    vector<pair<Airport, Airport>> res;
//TODO
    return res;
}

/**
 * @brief Returns the airport with the most flights
 * @details Time complexity O(n^2), where n is the number of airports
 * @return The airport with the most flights
 */
Airport WorldGraphManager::findTopKAirport() {
    vector<pair<int, Airport>> vector;
    for(auto i : _world.getVertexSet()){
        pair<int, Airport> newpair;
        newpair.first = i->getAdj().size();
        newpair.second = i->getInfo();
        vector.push_back(newpair);
    }
    for (auto i : _world.getVertexSet()){
        for (auto j : i->getAdj()){
            Airport target = j.getDest()->getInfo();
            auto it = std::find_if(vector.begin(), vector.end(),
                                   [target](const std::pair<int, Airport> &element) {
                                       return element.second == target;
                                   });
            if(it == vector.end()){
                pair<int, Airport> newpair;
                newpair.first = 1;
                newpair.second = j.getDest()->getInfo();
                vector.push_back(newpair);
            }
            else{
                it->first++;
            }
        }
    }
    auto pairComparator = [](const pair<int, Airport>& a, const pair<int, Airport>& b) {
        return a.first > b.first;
    };
    sort(vector.begin(), vector.end(), pairComparator);
    return vector[0].second;
}

/**
 * @brief Returns the vertex corresponding to a given airport code
 * @details Time complexity O(n) where n is the number of airports
 * @param code The airport code
 * @return The vertex corresponding to the given airport code
 */
Vertex<Airport>* WorldGraphManager::airportFinder(std::string code) {
    string newsource;
    for(auto i : _world.getVertexSet())
        if (code == i->getInfo().getCode()) return i;
    cout << "That code does not exist, try again: ";
    cin >> newsource;
    return airportFinder(newsource);
}