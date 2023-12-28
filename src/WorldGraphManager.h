#include "FileManager.h"
#include "Graph.h"
#include "Airport.h"
#include "Airline.h"
#include "Flight.h"
#include <vector>

#ifndef AED_PROJ_2_WORLDGRAPH_H
#define AED_PROJ_2_WORLDGRAPH_H


class WorldGraphManager {
private:
    FileManager _vectors;
    vector<Airline> _airlines;
    vector<Flight> _flights;
    Graph<Airport> _world;

public:
    WorldGraphManager();

    void makeAirports();
    void makeAirlines();
    void makeFlights();
    void addFlights();

    Vertex<Airport>* airportFinder(string code);

    int numberOfAirports();
    int numberOfFlights();
};


#endif //AED_PROJ_2_WORLDGRAPH_H
