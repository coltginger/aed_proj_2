#include "WorldGraphManager.h"
#include <cmath>
#include <algorithm>

using namespace std;

WorldGraphManager::WorldGraphManager() {
    makeAirports();
    makeAirlines();
    makeFlights();
}

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

Vertex<Airport>* WorldGraphManager::airportFinder(std::string code) {
    for(auto i : _world.getVertexSet())
        if (code == i->getInfo().getCode()) return i;
}

int WorldGraphManager::numberOfAirports() {
    int res = 0;
    for (auto i : _world.getVertexSet()){
        res++;
    }
    return res;
}

int WorldGraphManager::numberOfFlights() {
    int res = 0;
    for (auto i: _flights){
        res++;
    }
    return res;
}

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