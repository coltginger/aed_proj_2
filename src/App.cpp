#include "App.h"
#include <iostream>
#include <string>
using namespace std;

void App::run() {
    bool STOP = true;

    while (STOP){
        cout << "1. Show the global number of airports and number of flights." << endl
             << "2. Number of flights out of an airport and from how many different airlines." << endl
             << "3. Number of flights per city or airline" << endl;
    }
}

App::App() {}