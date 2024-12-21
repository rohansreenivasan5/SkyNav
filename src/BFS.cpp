#include "BFS.h"
#include <unordered_map>
#include "Airport.h"
#include "Flight.h"
#include <string>
#include <vector>
#include <queue>

std::vector<Flight> getTraversal(unordered_map<int, Airport> airports_, unordered_map<int, vector<Flight>> flights_, Airport start, Airport end)
{
    std::vector<int> visited;
    visited.resize(airports_.size());
    std::queue<Airport> q;
    visited[start.getID()] = 1;
    q.push(start);
    Airport v;
    std::vector<Flight> toReturn;
    while (!q.empty())
    {
        v = q.front();
        q.pop();
        if (v.getID() == end.getID()) {
            break;
            //we have reached the end of our BFS!
        }
        for (Flight f : flights_[v.getID()])
        {
            // for all flights at airport v...
            int id = f.getDestinationID();
            Airport dest = airports_[f.getDestinationID()];
            if (visited[id] == 0)
            {
                // unexplored node
                visited[id] == 1;
                toReturn.push_back(f);
                q.push(dest);
            }
        }
    }
    return toReturn;
}
