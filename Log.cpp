#include "Log.h"
#include <string>

void Log::add_item(int flightNum, std::string duration, double price, bool availability)
{
    if (_count < Log::MAX_SIZE)
    {
        Flight new_item;
        new_item.init(flightNum, duration, price, availability);
        _items[_count] = new_item;
        _count++;
    }
}

Flight Log::find_item(Flight query)
{
    for (size_t i = 0; i < _count; i++)
    {
        // Check if the properties of the query match the properties of the current item
        if (query.getFlightNum() != 0 && query.getFlightNum() != _items[i].getFlightNum())
            continue;

        if (!query.getDuration().empty() && query.getDuration() != _items[i].getDuration())
            continue;

        if (query.getPrice() != 0 && query.getPrice() != _items[i].getPrice())
            continue;

        if (query.getAvailability() != _items[i].getAvailability())
            continue;

        // If all criteria match, return the current item
        return _items[i];
    }

    // If no matching item is found, return a default Flight object
    return Flight{};
}
