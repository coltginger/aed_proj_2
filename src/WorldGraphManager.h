#include "FileManager.h"
#include "Graph.h"
#include "Airport.h"
#include "Airline.h"
#include <vector>

#ifndef AED_PROJ_2_WORLDGRAPH_H
#define AED_PROJ_2_WORLDGRAPH_H


class WorldGraphManager {
private:
    FileManager _vectors;
    vector<Airline> _airlines;
    Graph<Airport> _world;

public:
    WorldGraphManager();

    void makeAirports();
    void makeAirlines();
    void makeFlights();
};


#endif //AED_PROJ_2_WORLDGRAPH_H
