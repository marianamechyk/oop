#ifndef LOG_H
#define LOG_H

#include "Flight.h" // Include Flight.h for the Flight class definition
#include <string>

class Log {
public:
    // Initializes the log
    void init() { _count = 0; }

    // Returns the current number of abstraction objects
    size_t get_count() { return _count; }

    // Returns stored abstraction object by its index or default object if index is invalid
    Flight get_item(size_t i) { return (i < _count) ? _items[i] : Flight{}; }

    // From passed property values, creates and adds new abstraction object in an array _items
    // (replace parameters to match your property types and identifiers)
    void add_item(int flightNum, std::string duration, double price, bool availability);

    // Looks for a matching abstraction object and returns the first found or default object
    Flight find_item(Flight query);

private:
    // The maximum number of abstraction objects that can be stored
    static const size_t MAX_SIZE{ 10 };

    // An array for storing abstraction objects
    Flight _items[MAX_SIZE]; // Use MAX_SIZE directly here

    // The number of currently stored abstraction objects in the array _items
    size_t _count;
};

#endif
