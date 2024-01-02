#include "FileManager.h"
#include "Graph.h"
#include "Airport.h"
#include "Airline.h"
#include "Flight.h"
#include <vector>

#ifndef AED_PROJ_2_WORLDGRAPH_H
#define AED_PROJ_2_WORLDGRAPH_H

/**
 * @brief Class responsible for creating and managing a world graph that represents airports, airlines, and flights.
 * It is responsible for working with the FileManager to parse data and store it in the class's respective fields
 * After parsing the data, the class is responsbile for providing various functions to query and manipulate data related to airports, airlines and flights.
 */
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

    pair<int, int> numberOfFlightsInAirport(string source);

    vector<pair<string, int>> numberOfFlightsPerCity();
    vector<pair<string, int>> numberOfFlightsPerAirline();

    int numberOfCountriesAirport(string source);
    int numberOfCountriesCity(string source);

    int numberOfAirportsAirport(string source);
    int numberOfCitiesAirport(string source);

    int numberOfAirportsAtX(string source, int distance);

    vector<pair<Airport, Airport>> findLongestTrips();

    Airport findTopKAirport();

};


#endif //AED_PROJ_2_WORLDGRAPH_H
