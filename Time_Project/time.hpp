#pragma once
#include <iostream>
#include <iomanip> //setfill setw
#include "helper.hpp"

#define TIME_ARRAY_ELEMENTS 3
#define HOURS_INDEX 0
#define MINUTES_INDEX 1
#define SECONDS_INDEX 2
#define MIN_TIME_INPUT 0
#define MAX_SECONDS_MINUTES 59

class Time {
private:
    int* mTime;

public:
    // CTOR & DTOR
    Time(int h, int m, int s)
        : mTime{ new int[TIME_ARRAY_ELEMENTS] {h,  m, s} }
    {
        myAssert(h < MIN_TIME_INPUT, "Error: Hours must be grater than or equal to 0.");
        myAssert(m < MIN_TIME_INPUT&& m > MAX_SECONDS_MINUTES, "Error: Minutes must be in range 0-59.");
        myAssert(s < MIN_TIME_INPUT&& s > MAX_SECONDS_MINUTES, "Error: Seconds must be in range 0-59.");
    }

    Time(const Time& o)
        : mTime{ new int[TIME_ARRAY_ELEMENTS] {o.hours(), o.minutes(), o.seconds()} }
    { }

    ~Time()
    {
        delete[] mTime;
        mTime = nullptr;
    }

    // getters & setters:
    int hours() const { return mTime[HOURS_INDEX]; }
    void set_hours(int hours) { mTime[HOURS_INDEX] = hours; }

    int minutes() const { return mTime[MINUTES_INDEX]; }
    void set_minutes(int minutes) { mTime[MINUTES_INDEX] = minutes; }

    int seconds() const { return mTime[SECONDS_INDEX]; }
    void set_seconds(int minutes) { mTime[SECONDS_INDEX] = minutes; }

    // functions:
    void show_time()
    {
        std::cout << std::setfill('0');

        std::cout << std::setw(2) << mTime[HOURS_INDEX] << ":"
            << mTime[MINUTES_INDEX] << ":"
            << mTime[SECONDS_INDEX] << "\n";
    }
};


