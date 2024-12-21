#ifndef CATCH_CONFIG_MAIN
#define CATCH_CONFIG_MAIN
#endif
#include "catch.hpp"
#include "../src/flightgraph.h"
#include "../src/Flight.h"
#include "../src/Airport.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stack>



using namespace std;

bool compareVects(const vector<int>& v1, const vector<Flight>& v2) {
    REQUIRE (v1.size() - 1 == v2.size());
    for (unsigned i = 0; i<v2.size(); i++) {
        if (!(v1.at(i) == v2.at(i).getStartID()) && v1.at(i + 1) == v2.at(i).getDestinationID()) {
            return false;
        }
    }
    return true;
}

TEST_CASE("getAirportSmall", "[Data]") {
    Graph test = Graph("tests/testairports.txt","tests/testflights.txt");
    Airport expected = Airport(1,"A","A","A",47.808543,-111.235683);
    Airport actual = test.getAirport(1);
    REQUIRE(expected.getName() == actual.getName());
    REQUIRE(expected.getCity() == actual.getCity());
    REQUIRE(expected.getCountry() == actual.getCountry());
    REQUIRE(expected.getLatitude() == actual.getLatitude());
    REQUIRE(expected.getLongitude() == actual.getLongitude());
}

TEST_CASE("getAirport", "[Data]") {
    Graph test = Graph("data/airports.txt","data/routes.txt");
    Airport expected = Airport(3749,"Barysiai Airport","Barysiai","Lithuania",56.07059860229492,23.5580997467041);
    Airport actual = test.getAirport(3749);
    REQUIRE(expected.getName() == actual.getName());
    REQUIRE(expected.getCity() == actual.getCity());
    REQUIRE(expected.getCountry() == actual.getCountry());
    REQUIRE(expected.getLatitude() == actual.getLatitude());
    REQUIRE(expected.getLongitude() == actual.getLongitude());
}

TEST_CASE("BFS1", "[BFS]") {
    Graph test = Graph("data/airports.txt","data/routes.txt");
    vector<int> expected = vector<int>({2811, 2833});
    vector<Flight> actual = test.BFS(2811, 2833);
    REQUIRE(compareVects(expected, actual)==true);
}

TEST_CASE("BFS2", "[BFS]") {
    Graph test = Graph("tests/testairports.txt","tests/testflights.txt");
    vector<int> expected = vector<int>({1, 3, 5});
    vector<Flight> actual = test.BFS(1, 5);
    REQUIRE(compareVects(expected, actual)==true);
    expected = vector<int>({1, 3, 5});
    actual = test.BFS(1, 5);
    REQUIRE(compareVects(expected, actual)==true);
}

TEST_CASE("Dijkstra1", "[D1]") {
    Graph test = Graph("tests/testairports.txt","tests/testflights.txt");
    vector<int> expected = vector<int>({1, 4});
    vector<Flight> actual = test.Dijkstra(1, 4);
    REQUIRE(compareVects(expected, actual)==true);
    expected = vector<int>({1, 4, 2, 5});
    actual = test.Dijkstra(1, 5);
    REQUIRE(compareVects(expected, actual)==true);
}