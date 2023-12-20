// Q3.cpp:
// This simple program shows you how to measure how long
// a certain part of your program ran.

#include <iostream>
using namespace std;

#include "timer.h"

int main()
{
    TICK(); // <-- Note the use of TICK() here
    cout << "Hello" << endl;
    TOCK(); // <-- and the use of TOCK() here

    cout << endl;
    // See how DURATION() is used below.
    cout << "To display the message above the computer took "
         << DURATION() << " seconds" << endl;
    cout << endl;
}