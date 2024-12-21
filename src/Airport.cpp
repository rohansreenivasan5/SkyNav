#include "Airport.h"
#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
// #include "Flight.h" //class yet to be made

using namespace std;

Airport::Airport()
: airportID_(0), name_(""), city_(""), country_(""), latitude_(0.0), longitude_(0.0) { }

Airport::Airport(int airportID, string name, string city, string country, double latitude, double longitude)
: airportID_(airportID), name_(name), city_(city), country_(country), latitude_(latitude), longitude_(longitude) { }

Airport::Airport(string &line) {
    //working with a csv. Count the commas and add strings to a vector.
    int count = 0;
    int apostCount = 0;
    //going to iterate through the line, counting the number of commas seen and depending on count, we will add the string
    //to the appropriate variable.
    int prevIndex = 0;
    for (size_t i = 0; i < line.size() && count < 9; i++) {
        int endIndex = int(i);
        if (line[i] == ',' && apostCount % 2 == 0) {
            count++; //increment the comma count
            if (count == 1) {
                //if this is the first comma we've seen so far, then we found the Airport ID.
                //for substring, length will be endIndex - prevIndex + 1

                airportID_ = stoi(line.substr(prevIndex, endIndex - prevIndex + 1));
                prevIndex = endIndex + 2;  //bring prevIndex past the comma (+1) and past the " (+1);
            }
            else if (count == 2) {
                //if this is the second comma we've seen so far, we found the name
                //for substring, length will be endIndex - prevIndex, no need to add 1 this time since we have a " to disregard
                name_ = line.substr(prevIndex, endIndex - prevIndex - 1);
                prevIndex = endIndex + 2;  //bring prevIndex past the comma (+1) and past the " (+1);
            }
            else if (count == 3) {
                //if this is the third comma we've seen so far, we found the city
                //for substring, length will be endIndex - prevIndex, no need to add 1 this time since we have a " to disregard
                city_ = line.substr(prevIndex, endIndex - prevIndex - 1);
                prevIndex = endIndex + 2;  //bring prevIndex past the comma (+1) and past the " (+1);
            }
            else if (count == 4) {
                //if this is the fourth comma we've seen so far, we found the country
                //for substring, length will be endIndex - prevIndex, no need to add 1 this time since we have a " to disregard
                country_ = line.substr(prevIndex, endIndex - prevIndex - 1);
                prevIndex = endIndex + 2;  //bring prevIndex past the comma (+1) and past the " (+1);
            }
            else if (count == 5) {
                //if this is the 5th comma we've seen so far, we found the IATA. We don't need this
                //do nothing
            }
            else if (count == 6) {
                //if this is the 6th comma we've seen so far, we found the ICAO. We don't need this,
                //but we need to update prevIndex for the next comma which is for latitude.
                prevIndex = endIndex + 1; //bring prevIndex past the comma (+1)
            }
            else if (count == 7) {
                //if this is the 7th comma we've seen so far, we found the latitude
                //for substring, length will be endIndex - prevIndex + 1
                latitude_ = stod(line.substr(prevIndex, endIndex - prevIndex + 1));
                prevIndex = endIndex + 1;
            }
            else if (count == 8) {
                //if this is the 8th comma we've seen so far, we found the longitude
                //for substring, length will be endIndex - prevIndex + 1
                longitude_ = stod(line.substr(prevIndex, endIndex - prevIndex + 1));
                prevIndex = endIndex + 2;
            }
        } else if (line[i] == '"') {
            apostCount++;
        }
    }
    //if for some reason we have incomplete data, just use the default constructor
    if (count < 9) {
        Airport();
    }
}

//getters and setters

int Airport::getID() const { return airportID_; }
string Airport::getName() const { return name_; }
string Airport::getCity() const { return city_; }
string Airport::getCountry() const { return country_; }
double Airport::getLatitude() const { return latitude_; }
double Airport::getLongitude() const { return longitude_; }

void Airport::setID(int airportID) { airportID_ = airportID; }
void Airport::setName(string name) { name_ = name; }
void Airport::setCity(string city) { city_ = city; }
void Airport::setCountry(string country) { country_ = country; }
void Airport::setLatitude(double latitude) { latitude_ = latitude; }
void Airport::setLongitude(double longitude) { longitude_ = longitude; }


// calculates the distance between two latitude/longitude coordinates in miles
// algorithm from https://www.geeksforgeeks.org/program-distance-two-points-earth/
double Airport::distanceTo(Airport other) {
    double conversionToRadians = (M_PI) / 180;
    double lat1Rad = latitude_ * conversionToRadians;
    double long1Rad = longitude_ * conversionToRadians;
    double lat2Rad = other.getLatitude() * conversionToRadians;
    double long2Rad = other.getLongitude() * conversionToRadians;

    double distance = pow(sin((lat2Rad - lat1Rad) / 2), 2) +
                          cos(lat1Rad) * cos(lat2Rad) *
                          pow(sin((long2Rad - long1Rad) / 2), 2);
    distance = 2 * 6371 * asin(sqrt(distance));
    return distance;
}