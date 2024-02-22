#include "Flight.h"

void Flight::init(int flightNum, std::string duration, double price, bool availability)
{
    _flightNum = flightNum;
    _duration = duration;
    _price = price;
    _availability = availability;
}
