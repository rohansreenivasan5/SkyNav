#pragma once

#include "Airport.h"
#include <string>
using namespace std;

class Flight {
    public:
        // default constructor
        Flight() { start_id_ = 0; destination_id_ = 0;};
        //constructor for each line from data
        Flight(string &line);
        //constructor given all inputs
        Flight(int startID, int destinationID, string airline, int airline_id, int stops, double distance);
        //no need for a copy constructor since there should never be 2 of the same airport
        //default destructor will work for us

        // getters and setters
        int getStartID() const { return start_id_; };
        int getDestinationID() const { return destination_id_; };
        string getAirline() const { return airline_; };
        int getAirlineID() const { return airline_id_; };
        int getStops() const { return stops_; };
        double getDistance() const { return distance_; };

        void setStart(int startID) { start_id_ = startID; };
        void setStart(int startID, double distance);
        void setDestination(int destinationID) { destination_id_ = destinationID; };
        void setDestination(int destinationID, double distance);
        void setAirline(string airline) { airline_ = airline; };
        void setAirlineID(int airline_id) { airline_id_ = airline_id; };
        void setStops(int stops) { stops_ = stops; };
        void setDistance(double distance) { distance_ = distance; };

        // compares two flights by flight disance
        bool operator<(const Flight& other) const;
        bool operator>(const Flight& other) const;

        bool operator==(const Flight& other) const;

        friend std::ostream& operator<< (std::ostream& stream, const Flight& flight);

    private:
        int start_id_;
        int destination_id_;
        // 2-letter (IATA) or 3-letter (ICAO) code of the airline.
        string airline_;
        // Unique OpenFlights identifier for airline
        int airline_id_;
        // Number of stops on this flight ("0" for direct)
        int stops_;
        // Distance between airports, acts as the edge wieghts
        double distance_;
};