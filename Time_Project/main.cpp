 #include <iostream>

 #include "time.hpp"

int main()
{
    Time t1{ 10, 20, 30 };
    Time t2{ t1 };

    t1.show_time();
    t2.set_hours(50);
    t2.show_time();
}