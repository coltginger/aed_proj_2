#include "WorldGraphManager.h"

#ifndef AED_PROJ_2_APP_H
#define AED_PROJ_2_APP_H

/**
 * @brief Class that takes care of the UI seen by the user and is the one that calls all other functions and classes
 */
class App {
private:
    WorldGraphManager _worldGraph;
public:
    App();
    void run();
};


#endif //AED_PROJ_2_APP_H
