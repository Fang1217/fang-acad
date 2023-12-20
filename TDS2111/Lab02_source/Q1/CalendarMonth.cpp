#ifndef CALENDAR_MONTH_CPP
#define CALENDAR_MONTH_CPP

#include <iostream>
#include <string>
using namespace std;

class CalendarMonth
{
    public:
        CalendarMonth(int year, int month);
        ~CalendarMonth();

        void display(int firstDayOfMonth);
        void putEntry(string text, int day);

        string getEntry(int day);
        int getMonth();
        int getYear();
        int getNumberOfDays();

    private:
        int month;
        int year;
        int numOfDays;
        string* entries;
};

CalendarMonth::CalendarMonth(int year, int month) : year(year), month(month)
{
    // TODO: Write your code here
    // Begin Question 1(a)
    // (i) Set the year and month
    // this->year = year;
    // this->month = month;
    // use constructor initializer list
    numOfDays = 0;
    // End Question 1(a)

	// TODO: Write your code here
	// Begin Question 1(b)

    // (i) Determine the number of days in the given month year
    // 1, 3, 5, 7, 8, 10, 12
    bool oddMonth = ((month > 7) ? (month % 2 == 0) : (month % 2 == 1));
    numOfDays = oddMonth ? 31 : 30;

    // (ii) Check for leap year if month is February
    bool leapYear = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
    if (month == 2) numOfDays = leapYear ? 29 : 28;

    // End Question 1(b)

	// TODO: Write your code here
    // Begin Question 1(c)
    // (i) Allocate memory for entries
    // (ii) Initialize each entry with empty string ""
    entries = new string[numOfDays];
    for (int i = 0; i < numOfDays; i++) {
        entries[i] = "";
    }
    // End Question 1(c)
}

CalendarMonth::~CalendarMonth()
{
    // TODO: Write your code here
	// Begin Question 1(d)
    // (i) Delete memory allocated for entries
    // (ii) Make sure entries points to null
    delete [] entries; // Delete the array that 'entries' pointer is pointed to.
    entries = NULL;

    // End Question 1(d)
}

void CalendarMonth::display(int firstDayOfMonth)
{
    static string dayName[] =
    {
        "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"  // all 3 chars
    };

    static string monthName[] =
    {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    // check firstDay for error.
    if ( ( firstDayOfMonth < 0 ) || ( firstDayOfMonth > 6 ) )
    {
        cout << "First Day invalid!" << endl;
        return;
    }

    // TODO: Write your code here
	// Begin Question 3(a)
    // (i) Display month and year
    cout << monthName[getMonth() - 1] << " " << year << endl; 

    // End Question 3(a)

    cout << "--------------------------------------------------------" << endl;

    // TODO: Write your code here
	// Begin Question 3(b)
    // (i) Display Sunday to Saturday.
    // Hint: Use a tab character to separate the names.
    for (string i : dayName) 
        cout << i << "\t";
    endl(cout);

    // End Question 3(b)

    cout << "--------------------------------------------------------" << endl;

    int currentDay = 1;     // the current day to display
    int currentEntry = 0;   // the current entry to display

	// TODO: Write your code here
	// Begin Question 3(c)
    // (i) Display the first week
    // Hint: Display a tab character for days before the firstDayOfMonth
    //       Display the day number for days starting from firstDayOfMonth
    for (int i = 0; i < firstDayOfMonth; i++)
        cout << "\t";

    for (int i = firstDayOfMonth; i < 7; i++)
    {
        // if there is an entry on the current day
        if (entries[currentDay - 1] != "") {
            cout << currentDay << "[" << ++currentEntry << "]\t";
        }
        else {
            cout << currentDay << "\t";
        }
        currentDay++;
    }
    endl(cout);


    // End Question 3(c)

    // TODO: Write your code here
	// Begin Question 3(d)
    // (i) Display the remaining weeks.
    while ( currentDay <= numOfDays )
    {
        // for each week
        for (int i = 0; i < 7; i++)
        {
            if (currentDay <= numOfDays)
            {
                // if there is an entry on the current day
                if (entries[currentDay - 1] != "") {
                    cout << currentDay << "[" << ++currentEntry << "]\t";
                }
                else {
                    cout << currentDay << "\t";
                }
                currentDay++;
            }
        }
        endl(cout);
    }

    // End Question 3(d)

    cout << "--------------------------------------------------------" << endl;

    // TODO: Write your code here
	// Begin Question 3(e)
    // (i) Display a list of entries
    currentEntry = 0;
    for (int i = 0; i < numOfDays; i++)
    {
        if (entries[i] != "") {
            cout << "[" << (currentEntry + 1) << "] " << entries[i] << endl;
            currentEntry++; 
        }
    }
    endl(cout);
    // End Question 3(e)
}

void CalendarMonth::putEntry(string text, int day)
{
    // TODO: Write your code here
    // Begin Question 2(a)
    // (i) Make sure the given day is valid
    // (ii) Assign the appropriate entry with text
    if (day <= getNumberOfDays()) {
        entries[day - 1] = text;
    }
    // End Question 2(a)
}

string CalendarMonth::getEntry(int day)
{
    // TODO: Write your code here
    // Begin Question 2(b)
    // (i) Make sure the given day is valid.
    // (ii) Return the entry at the given day.
    if (day <= getNumberOfDays()) {
        return entries[day - 1];
    }
    else 
        return "";

    // End Question 2(b)
}

int CalendarMonth::getMonth()
{
    return month;
}

int CalendarMonth::getYear()
{
    return year;
}

int CalendarMonth::getNumberOfDays()
{
    return numOfDays;
}
#endif
