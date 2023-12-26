#include "FileManager.h"
#include "Graph.h"
#include "Airport.h"
#include <vector>

#ifndef AED_PROJ_2_WORLDGRAPH_H
#define AED_PROJ_2_WORLDGRAPH_H


class WorldGraph {
private:
    FileManager _vectors;
    Graph<Airport> _world;

public:
    void makeAirports();
};


#endif //AED_PROJ_2_WORLDGRAPH_H
