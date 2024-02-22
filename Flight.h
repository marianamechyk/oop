#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>

class Flight {
public:
    // Constructor, if needed
   //Flight(int flightNum, std::string duration, double price, bool availability);

    // Method to initialize Flight object
    void init(int flightNum, std::string duration, double price, bool availability);

    // Getter methods, if needed
    int getFlightNum() const { return _flightNum; }
    std::string getDuration() const { return _duration; }
    double getPrice() const { return _price; }
    bool getAvailability() const { return _availability; }

private:
    int _flightNum;
    std::string _duration;
    double _price;
    bool _availability;
};

#endif
