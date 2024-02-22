#include <iostream>
#include <cassert> // Include the assert header
#include "Flight.h"
#include "Log.h"

using namespace std;

// outputs abstraction object properties to the console window
void show(Flight item)
{
    cout << item.getFlightNum() << " "
         << "'" << item.getDuration() << "' "
         << item.getPrice() << " "
         << item.getAvailability() << " "
         << endl;
}

// solution entry function
int main()
{
    Log log;

    log.init();

    // adds several different abstraction objects to the log
    log.add_item(1, "Riga", 499.99, true);
    log.add_item(2, "Viena", 549.99, true);
    // Test if count increases after adding items
    assert(log.get_count() == 2);

    Flight qry;
    // provides querying values (some can be default (e.g., "", 0) to denote unset criteria)
    qry.init(2, "", 0.0, true);
    show(log.find_item(qry));

    // tests with different query values
    qry.init(0, "Riga", 0.0, true);
    show(log.find_item(qry));

    // tests for nonmatching object
    qry.init(0, "Viena", 0.0, true);
    show(log.find_item(qry));

    // Test if count remains the same after querying
    assert(log.get_count() == 2);

    // Test if finding non-existing item returns a default Flight object
    qry.init(3, "", 0.0, true);
    assert(log.find_item(qry).getFlightNum() == 0);

    cout << "All tests passed!" << endl;



    return 0;
}