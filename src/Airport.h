//creating airports as our nodes for the graph

#pragma once

#include <vector>
#include <string>
#include <unordered_map>
// #include "Flight.h" //class yet to be made
using namespace std;

class Airport {
    public:
        //default constructor
        Airport();
        //constructor for each line from data
        Airport(string &line);
        //constructor given all inputs
        Airport(int airportID, string name, string city, string country, double latitude, double longitude);
        //no need for a copy constructor since there should never be 2 of the same airport
        //default destructor will work for us
        
        //getters and setters
        void setID(int airportID);
        void setName(string name);
        void setCity(string city);
        void setCountry(string country);
        void setLatitude(double latitude);
        void setLongitude(double longitude);

        int getID() const;
        string getName() const;
        string getCity() const;
        string getCountry() const;
        double getLatitude() const;
        double getLongitude() const;

        // calculate the distance between two airports by latitude and longitude in miles
        double distanceTo(Airport other);

        bool operator==(const Airport& other) const { return airportID_ == other.getID(); };

        //each airport will have a map of edges to keep track of the airports it has flights to.

        //uncomment below line once Flight class is made
        //unordered_map<int, Flight> destinations;

    private:
        //airport private variables
        int airportID_;
        string name_;
        string city_;
        string country_;
        double latitude_;
        double longitude_;

};