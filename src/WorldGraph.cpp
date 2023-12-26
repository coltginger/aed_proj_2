#include "WorldGraph.h"

void WorldGraph::makeAirports() {
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