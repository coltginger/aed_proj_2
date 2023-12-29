#include "App.h"
#include <iostream>
#include <string>
#include <limits>
#include <algorithm>

using namespace std;

void App::run() {
    bool STOP = true;

    while (STOP){
        cout << "1. Number of airports and number of flights." << endl
             << "2. Number of flights out of an airport and from how many different airlines." << endl
             << "3. Number of flights per city or airline." << endl
             << "4. Number of different countries that a given airport/city flies to." << endl
             << "5. Number of destinations (airports or cities) available for a given airport." << endl
             << "6. Number of reachable destinations (airports, cities or countries) from a given airport in a maximum number of X stops." << endl
             << "7. Trip with the most stops and its airports." << endl
             << "8. Airport with the most number of related flights." << endl
             << "9. Airports that are essential to the networks circulation." << endl
             << "0. Present the best flight option." << endl << endl
             << "Please select an option (number): ";

        int option;
        int option2;
        int a;
        int b;
        pair <int, int> c;
        vector<pair<string, int>> d, e;
        Airport f;
        string source;

        cin >> option;

        switch (option) {
            case 1:
                a = _worldGraph.numberOfAirports();
                b = _worldGraph.numberOfFlights();

                cout << endl << "There are " << a << " airports and " << b << " available flights." << endl;
                cout << "Press enter to continue." << endl;
                cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
                cin.get();
                break;
            case 2:
                cout << endl << "Input the airport's code (in capital letters): ";
                cin >> source;

                c = _worldGraph.numberOfFlightsInAirport(source);

                cout << endl << "There are " << c.first << " flights out of this airport from " << c.second << " different airlines." << endl;
                cout << "Press enter to continue." << endl;
                cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
                cin.get();
                break;
            case 3:
                d = _worldGraph.numberOfFlightsPerCity();
                e = _worldGraph.numberOfFlightsPerAirline();
                sort(d.begin(), d.end());
                sort(e.begin(), e.end());
                cout << endl << "Flights per city: ";
                for (auto i : d){
                    cout << endl << i.first << " -- " << i.second;
                }
                cout << endl << "Flights per airline: ";
                for (auto i :e){
                    cout << endl << i.first << " -- " << i.second;
                }
                cout << endl << "Press enter to continue." << endl;
                cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
                cin.get();
                break;
            case 4:
                cout << endl << "Airport(1) or City(2)? (Input the number): ";
                cin >> option2;

                switch (option2) {
                    case 1:
                        cout << endl << "Input the airport's code (in capital letters): ";
                        cin >> source;
                        a = _worldGraph.numberOfCountriesAirpoart(source);
                        cout << endl << "The airport goes to " << a << " different countries.";
                        break;
                    case 2:
                        cout << endl << "Input the city's name: ";
                        cin >> source;
                        a = _worldGraph.numberOfCountriesCity(source);
                        cout << endl << "The city's airports go to " << a << " different countries.";
                        break;
                }
                cout << endl << "Press enter to continue." << endl;
                cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
                cin.get();
                break;
            case 5:
                cout << "Do you wish to know airports(1) or cities(2)? (Input the number): " << endl;
                cin >> option2;
                switch (option2) {
                    case 1:
                        cout << "Input the airport's code (in capital letters): ";
                        cin >> source;
                        a = _worldGraph.numberOfAirportsAirport(source);
                        cout << endl << "The airport goes to " << a << " different airports.";
                        break;
                    case 2:
                        cout << "Input the airport's code (in capital letters): ";
                        cin >> source;
                        a = _worldGraph.numberOfCitiesAirport(source);
                        cout << endl << "The airport goes to " << a << " different cities.";
                        break;
                }
                cout << endl << "Press enter to continue." << endl;
                cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
                cin.get();
                break;
            case 6:
                cout << endl << "Input the starting airport's code (in capital letters): ";
                cin >> source;
                cout << "What is the maximum number of stops?: ";
                cin >> a;

                b = _worldGraph.numberOfAirportsAtX(source, a);
                cout << endl << "There are " << b << " airports at a distance of " << a << " stops.";

                cout << endl << "Press enter to continue." << endl;
                cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
                cin.get();
                break;
            case 7:
                cout << endl << "Press enter to continue." << endl;
                cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
                cin.get();
                break;
            case 8:
                f = _worldGraph.findTopKAirport();
                cout << endl << "The airport with the most number of related flights is " << f.getName();
                cout << endl << "Press enter to continue." << endl;
                cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
                cin.get();
                break;
            case 9:
                cout << endl << "Press enter to continue." << endl;
                cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
                cin.get();
                break;

        }
    }
}

App::App() {}