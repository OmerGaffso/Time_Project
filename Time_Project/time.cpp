#include <iomanip> 
#include <ostream>

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

// this + int
Time Time::operator+(int right)
{
    std::cout << "Time + int\n";
    if (right < 0) {
        std::cout << "Error: Cannot add negative number to time.\n";
        exit(EXIT_FAILURE);
    }

    return Time{  this->hours()
                , this->minutes()
                , this->seconds() + right
    };
}

// int + Time obj
Time operator+(int left, Time const& right)
{
    if (left < 0) {
        std::cout << "Error: Cannot add negative number to time.\n";
        exit(EXIT_FAILURE);
    }
    std::cout << "int + Time\n";
    return Time{  right.hours()
                , right.minutes()
                , right.seconds() + left
    };
}

// this + Time obj
Time Time::operator+(const Time& right) 
{
    std::cout << "Time + Time\n";
    return Time{ this->hours() + right.hours()
               , this->minutes() + right.minutes()
               , this->seconds() + right.seconds()
    };
}

// this += timeObj;
Time Time::operator+=(const Time & right)
{
    int secondsOverflow{}, minutesOverflow{};

    mTime[SECONDS_INDEX] += right.seconds();
    secondsOverflow = mTime[SECONDS_INDEX] / UPPER_LIMIT;
    mTime[SECONDS_INDEX] %= UPPER_LIMIT;

    mTime[MINUTES_INDEX] += right.minutes() + secondsOverflow;
    minutesOverflow = mTime[MINUTES_INDEX] / UPPER_LIMIT;
    mTime[MINUTES_INDEX] %= UPPER_LIMIT;

    mTime[HOURS_INDEX] += right.hours() + minutesOverflow;
    
    return *this;
}

// this == Time obj ?
bool Time::operator==(const Time& o) const 
{
    return this->hours() == o.hours()
        && this->minutes() == o.minutes()
        && this->seconds() == o.seconds();
}

// this != Time ?
bool Time::operator!=(const Time& o) const
{
    return !(*this == o);
}

// this < Time ?
bool Time::operator<(const Time& o) const
{
    if (*this == o)
        return false;
    if (this->hours() > o.hours())
        return false;
    if (this->minutes() > o.minutes())
        return false;
    if (this->seconds() > o.seconds())
        return false;
    return true;
}

// this > Time ?
bool Time::operator>(const Time& o) const
{
    return (*this != o && !(*this < o));
}


// this <= Time ?
bool Time::operator<=(const Time& o) const
{
    return *this < o || *this == o;
}

// this >= Time ?
bool Time::operator>=(const Time& o) const
{
    return *this > o || *this == o;
}



// assign CTOR:
Time &Time::operator=(Time const& o)          
{
    std::cout << "= Operator\n";
    if (this != &o)             // if they are the same, do nothing.
    {
        delete[] mTime;
        mTime = new int[TIME_ARRAY_ELEMENTS] {o.hours(), o.minutes(), o.seconds()};
    }
    return *this;
}

// DTOR:
Time::~Time()
{
    std::cout << "DTOR\n";
    delete[] mTime;
    mTime = nullptr;
}

// ostream << Point
std::ostream& operator<<(std::ostream& out, Time const& time)
{
    out << std::setfill('0');

    return out << std::setw(2) << time.hours()
        << ":" << std::setw(2) << time.minutes() 
        << ":" << std::setw(2) << time.seconds() ;
}
