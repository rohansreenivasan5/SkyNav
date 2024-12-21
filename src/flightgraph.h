#pragma once
#include <unordered_map>
#include "Airport.h"
#include "Flight.h"
#include <string>
#include <vector>

using namespace std;

class Graph {
    public:
    // default constructor
    Graph();

    // construct graph from files
    Graph(string airportFile, string flightFile);

    // returns a reference to the airport in the graph from the airport id
    Airport& getAirport(int airport_id) {return airports_[airport_id];};

    // load airport and flight data information from files
    void readData(string airportFile, string flightFile);

    vector<Flight> Dijkstra(int source, int destination);
    std::vector<Flight> BFS(int source, int destination);

    private:
    // map storing airports with the airport id as the key, allowing for fast look-up of airports based on airport id
    unordered_map<int, Airport> airports_;
    unordered_map<int, vector<Flight>> flights_;
};