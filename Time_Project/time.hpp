#pragma once
#include <iostream>

class Time {

    static constexpr std::size_t TIME_ARRAY_ELEMENTS = 3;   // Size of time array
    static constexpr std::size_t HOURS_INDEX = 0;           // Index of hours in time array
    static constexpr std::size_t MINUTES_INDEX = 1;         // Index of minutes in time array
    static constexpr std::size_t SECONDS_INDEX = 2;         // Index of seconds in time array
    static constexpr std::size_t LOWER_LIMIT = 0;           // Min value for time input (all fields)
    static constexpr std::size_t UPPER_LIMIT = 60;          // Max value for time input (minutes and seconds)

private:
    int* mTime;

public:
    // CTOR & DTOR
    Time(int h = 0, int m = 0, int s = 0);  // default values set to 0

    Time(const Time& o);                    // Rule of 3: copy

    //Time(Time&& o);

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

    Time &operator=(Time const& o);          // rule of 3: assign

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




