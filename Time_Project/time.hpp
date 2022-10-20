#pragma once
#include <iostream>

/*
    This class represent time. 
    The time is being held in an int array, in which index 0 is the hours, index 1 is minutes and index 2 is seconds.
    Seconds and minutes is allways in range 0-59, and if there is an overflow, converted to the next field
    (seconds to minutes, minutes to hours.
    Hours can be unlimited.
*/

class Time {

    static constexpr std::size_t TIME_ARRAY_ELEMENTS = 3;   // Size of time array
    static constexpr std::size_t HOURS_INDEX = 0;           // Index of hours in time array
    static constexpr std::size_t MINUTES_INDEX = 1;         // Index of minutes in time array
    static constexpr std::size_t SECONDS_INDEX = 2;         // Index of seconds in time array
    static constexpr int UPPER_LIMIT = 60;                  // Max value for time input (minutes and seconds)
    static constexpr int LOWER_LIMIT = 0;                   // Min value for Time obj input (all fields)

private:
    int* mTime;

public:
    // CTOR & DTOR
    Time(int h = 0, int m = 0, int s = 0);  // default values set to 0

    Time(const Time& o);                    // Rule of 3: copy

    // this + int
    Time operator+(int right);

    // int + Time obj
    friend Time operator+(int left, Time const& right);

    // this + Time obj
    Time operator+(const Time& right);
    
    // this += timeObj;
    Time operator+=(const Time& right);

    // this == Time ?
    bool operator==(const Time& o) const;

    // this != Time ?
    bool operator!=(const Time& o) const;

    // this <= Time ?
    bool operator<=(const Time& o) const;

    // this >= Time ?
    bool operator>=(const Time& o) const;

    // this < Time ?
    bool operator<(const Time& o) const;

    // this > Time ?
    bool operator>(const Time& o) const;

    Time &operator=(Time const& o);         // rule of 3: assign

    ~Time();                                // rule of 3: deletes

    // getters & setters:
    int hours() const { return mTime[HOURS_INDEX]; }
    void hours(int hours) { mTime[HOURS_INDEX] = hours; }

    int minutes() const { return mTime[MINUTES_INDEX]; }
    void minutes(int minutes) { mTime[MINUTES_INDEX] = minutes; }

    int seconds() const { return mTime[SECONDS_INDEX]; }
    void seconds(int minutes) { mTime[SECONDS_INDEX] = minutes; }

    /*
        ostream << Point
        simple print when sending the Time obj to std::out.
        prints the Time in the following format:
                XX:XX:XX
    */ 
    friend std::ostream& operator<<(std::ostream& out, Time const& time); 
};




