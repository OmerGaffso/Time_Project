 #include "time.hpp"

int main()
{
    Time t1{ 10, 59, 0 };
    Time t2{ t1 };
    Time t3 = t1;
    Time t4{};
    Time t5{ Time{11,22,33} };
    t1.hours(24);
    t1.minutes(24);
    t1.seconds(24);


    t1.show_time();
    t2.hours(50);
    t2.show_time();
    t3.show_time();
    t4 = t1;
    t4.show_time();
    t5.show_time();

}