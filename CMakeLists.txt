cmake_minimum_required(VERSION 3.26)
project(aed_proj_2)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(aed_proj_2
        src/App.cpp
        src/App.h
        src/Graph.h
        src/Airport.h
        src/Airport.h
        src/Airport.cpp
        src/Airline.h
        src/Airline.cpp
        src/Flight.h
        src/Flight.cpp
        src/FileManager.h
        src/FileManager.cpp)
