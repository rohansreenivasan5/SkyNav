#pragma once
#include <unordered_map>
#include "Airport.h"
#include "Flight.h"
#include <string>
#include <vector>

class BFS
{
public:
    std::vector<Flight> getTraversal(unordered_map<int, Airport> airports_, unordered_map<int, vector<Flight>> flights_, Airport start, Airport end);
};