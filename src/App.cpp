#include "App.h"
#include <iostream>
#include <string>
#include <limits>
using namespace std;

void App::run() {
    bool STOP = true;

    while (STOP){
        cout << "1. Number of airports and number of flights." << endl
             << "2. Number of flights out of an airport and from how many different airlines." << endl
             << "3. Number of flights per city or airline." << endl
             << "4. Number of different countries that a given airport/city flies to." << endl
             << "5. Number of destinations (airports, cities or countries) available for a given airport." << endl
             << "6. Number of reachable destinations (airports, cities or countries) from a given airport in a maximum number of X stops." << endl
             << "7. Trip with the most stops and its airports." << endl
             << "8. Airport with the most number of related flights." << endl
             << "9. Airports that are essencial to the networks circulation." << endl
             << "0. Present the best flight option." << endl << endl
             << "Please select an option (number): ";

        int option;

        cin >> option;

        switch (option) {
            case 1:
                int a = _worldGraph.numberOfAirports();
                int b = _worldGraph.numberOfFlights();

                cout << endl << "There are " << a << " airports and " << b << " available flights." << endl;
                cout << "Press enter to continue." << endl;
                cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
                cin.get();
                
        }
    }
}

App::App() {}