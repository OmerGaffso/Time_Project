#include <iomanip> 

#include "time.hpp"

// CTOR:
Time::Time(int h, int m, int s)
{
    std::cout << "Regular CTOR\n";
    if (h < LOWER_LIMIT || m < LOWER_LIMIT || s < LOWER_LIMIT) {
        std::cout << "Error: Time must be positive integer.\n";
        exit(EXIT_FAILURE);
    }
    m += s / UPPER_LIMIT;   // Add 1 minute for every 60 seconds.
    s = s % 60;             // Seconds in range of 0-59.
    h += m / UPPER_LIMIT;   // Add 1 hour for every 60 minutes.
    m = m % 60;             // Minutes in range of 0-59.
    
    mTime = new int[TIME_ARRAY_ELEMENTS] {h, m, s};
}

// Copy CTOR:
Time::Time(const Time& o)
    : mTime{ new int[TIME_ARRAY_ELEMENTS] {o.hours(), o.minutes(), o.seconds()} }
{
    std::cout << "Copy CTOR\n";
}

//// move CTOR:
//Time::Time(Time&& o)
//    : mTime{ o.mTime }
//{
//    std::cout << "Move CTOR\n";
//    o.mTime = nullptr;
//}

// assign CTOR:
Time &Time::operator=(Time const& o)          
{
    std::cout << "= Operator\n";
    delete[] mTime;


    mTime = new int[TIME_ARRAY_ELEMENTS] {o.hours(), o.minutes(), o.seconds()};
    return *this;
}

// DTOR:
Time::~Time()
{
    std::cout << "DTOR\n";
    delete[] mTime;
    mTime = nullptr;
}

// functions:
void Time::show_time()
{
    std::cout << std::setfill('0');

    std::cout << std::setw(2) << mTime[HOURS_INDEX]
        << ":" << std::setw(2) << mTime[MINUTES_INDEX]
        << ":" << std::setw(2) << mTime[SECONDS_INDEX]
        << std::endl;
}
