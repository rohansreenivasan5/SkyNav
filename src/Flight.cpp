#include "Flight.h"
#include <iostream>

using namespace std;

Flight::Flight(string &line) {
    //working with a csv. Count the commas and add strings to a vector.
    int count = 0;
    //going to iterate through the line, counting the number of commas seen and depending on count, we will add the string
    //to the appropriate variable.
    int prevIndex = 0;
    for (size_t i = 0; i < line.size() && count < 9; i++) {
        int endIndex = int(i);
        if (line[i] == ',') {
            count++; //increment the comma count
            if (count == 1) {
                //if this is the first comma we've seen so far, then we found the airline.
                //for substring, length will be endIndex - prevIndex + 1
                airline_ = line.substr(prevIndex, endIndex - prevIndex + 1);
                prevIndex = endIndex + 1;  //bring prevIndex past the comma (+1);
            }
            else if (count == 2) {
                //if this is the second comma we've seen so far, we found the airline id12wfe
                if (line.substr(prevIndex, endIndex - prevIndex + 1) == "\\N") {
                    airline_id_ = 0;
                } else {
                    airline_id_ = stoi(line.substr(prevIndex, endIndex - prevIndex + 1));
                }
                prevIndex = endIndex + 1;  //bring prevIndex past the comma (+1);
            }
            else if (count == 4) {
                //if this is the fourth comma we've seen so far, we found the airport ID
                if (line.substr(prevIndex, endIndex - prevIndex + 1) == "-1") {
                    start_id_ = -1;
                } else {
                    start_id_ = stoi(line.substr(prevIndex, endIndex - prevIndex + 1));
                }
                prevIndex = endIndex + 1;  //bring prevIndex past the comma (+1);
            }
            else if (count == 6) {
                //if this is the sixth comma we've seen so far, we found the airport ID
                if (line.substr(prevIndex, endIndex - prevIndex + 1) == "-1") {
                    start_id_ = -1;
                    destination_id_ = 0;
                } else {
                    destination_id_ = stoi(line.substr(prevIndex, endIndex - prevIndex + 1));
                }
                prevIndex = endIndex + 1;  //bring prevIndex past the comma (+1);
            }
            else if (count == 8) {
                //if this is the 8th comma we've seen so far, we found the stops
                //for substring, length will be endIndex - prevIndex + 1
                stops_ = stoi(line.substr(prevIndex, endIndex - prevIndex + 1));
                prevIndex = endIndex + 1;
            } else {
                // this means the comma is the third (airport code), fifth (airport code), 
                // seventh (codeshare boolean), or ninth (equiptment)
                // do nothing
                prevIndex = endIndex + 1;
            }
        }
    }
    distance_ = 0;
    //if for some reason we have incomplete data, just use the default constructor
    if (count < 10) {
        Flight();
    }
}

Flight::Flight(int startID, int destinationID, string airline, int airline_id, int stops, double distance) 
: start_id_(startID), destination_id_(destinationID), airline_(airline), airline_id_(airline_id), stops_(stops), distance_(distance){}

void Flight::setStart(int startID, double distance) {
    start_id_ = startID;
    distance_ = distance;
}

void Flight::setDestination(int destinationID, double distance) {
    destination_id_ = destinationID;
    distance_ = distance;
}

bool Flight::operator<(const Flight& other) const {
    return distance_ < other.distance_;
}

bool Flight::operator>(const Flight& other) const {
    return distance_ > other.distance_;
}

bool Flight::operator==(const Flight& other) const {
    return start_id_ == other.start_id_ 
    && destination_id_ == other.destination_id_
    && stops_ == other.stops_;
}

std::ostream& operator<< (std::ostream& stream, const Flight& flight) {
    stream<<"{"<<flight.start_id_<<","<<flight.destination_id_<<"}";
    return stream;
}