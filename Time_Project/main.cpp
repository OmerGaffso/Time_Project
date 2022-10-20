#include "time.hpp"

void test_time()
{
    Time t1{ 0, 0, 1 };
    Time t2(0, 0, 2);
    Time t3(0, 0, 3);
    Time t4{ 0, 0, 1 };

    std::cout << "\nTEST COMPERISON OPERANDS:\n";

    for (int i = 0; i < 3; i++)
    {
        if (i == 1)
        {
            t1 = Time{ 0, 1, 0 };
            t2 = t1 + 60; //test time + int ECPECTED: t2 = Time{0, 2, 0};
            t3 = 60 + t2; //test int + time ECPECTED: t3 = Time{0, 3, 0}; 
            t4 = Time{ 0, 1, 0 };
        }
        if (i == 2)
        {
            t1 = Time{ 1, 0, 0 };
            t2 = t1 + t1; // test time + time ECPECTED: t2 = Time{2, 0, 0};
            t3 = t2; // test time = time 
            t3 += t1; // test time += time ECPECTED: t3 = Time{3, 0, 0};
            t4 = Time{ 1, 0, 0 };
        }

        std::cout << t1 << " t1\n";
        std::cout << t2 << " t2\n";
        std::cout << t3 << " t3\n";
        std::cout << t4 << " t4\n";

        if ((t1 > t2))
        {
            std::cout << "TEST [ " << t1 << " >  " << t2 << " ]: FAIL\n";
        }
        if ((t1 > t4))
        {
            std::cout << "TEST [ " << t1 << " >  " << t1 << " ]: FAIL\n";
        }
        if ((t2 > t1))
        {
            std::cout << "TEST [ " << t2 << " >  " << t1 << " ]: PASS\n";
        }

        if ((t2 < t1))
        {
            std::cout << "TEST [ " << t2 << " <  " << t1 << " ]: FAIL\n";
        }
        if ((t1 < t4))
        {
            std::cout << "TEST [ " << t1 << " <  " << t1 << " ]: FAIL\n";
        }
        if ((t1 < t2))
        {
            std::cout << "TEST [ " << t1 << " <  " << t2 << " ]: PASS\n";
        }

        if ((t1 == t2))
        {
            std::cout << "TEST [ " << t1 << " == " << t2 << " ]: FAIL\n";
        }
        if ((t1 == t4))
        {
            std::cout << "TEST [ " << t1 << " == " << t4 << " ]: PASS\n";
        }

        if ((t1 != t4))
        {
            std::cout << "TEST [ " << t1 << " != " << t4 << " ]: FAIL\n";
        }
        if ((t1 != t2))
        {
            std::cout << "TEST [ " << t1 << " != " << t2 << " ]: PASS\n";
        }

        if ((t2 <= t1))
        {
            std::cout << "TEST [ " << t2 << " <= " << t1 << " ]: FAIL\n";
        }
        if ((t1 <= t4))
        {
            std::cout << "TEST [ " << t1 << " <= " << t1 << " ]: PASS\n";
        }
        if ((t1 <= t2))
        {
            std::cout << "TEST [ " << t1 << " <= " << t2 << " ]: PASS\n";
        }

        if ((t1 >= t2))
        {
            std::cout << "TEST [ " << t1 << " >= " << t2 << " ]: FAIL\n";
        }
        if ((t1 >= t4))
        {
            std::cout << "TEST [ " << t1 << " >= " << t1 << " ]: PASS\n";
        }
        if ((t2 >= t1))
        {
            std::cout << "TEST [ " << t2 << " >= " << t1 << " ]: PASS\n\n";
        }
    }
}
int main()
{
    // test function for Time methods
    test_time();

    // checks for exiting
    //Time terr1{ -1,0,0 };
    //Time terr2{ 0,-1,0 };
    //Time terr3{ 0,0,-1 };
    

    Time t1{ 10, 59, 0 };
    Time t2{ t1 };
    Time t3 = t1;
    Time t4{};
    Time t5{ Time{11,22,33} };
    Time zero{};
    t1.hours(1);
    t1.minutes(2);
    t1.seconds(3);

    // CTOR check
    std::cout << t1 << std::endl;
    t2.hours(50);
    
    // copy, += and assignment check
    std::cout << t2 << std::endl;
    t2 += t1;
    std::cout << t2 << std::endl;
    std::cout << t3 << std::endl;

    // assignment and copy check
    t4 = t1;
    std::cout << t4 << std::endl;
    std::cout << t5 << std::endl; 

    // Time + Time check
    Time t6 = t1 + t5;
    std::cout << t6 << std::endl;

    // Time + int & int + Time check
    Time t7 = zero + 25660;
    Time t8 = 70984 + zero;
    std::cout << t7 << std::endl << t8 << std::endl;

    // check if the second/minutes overflow work
    Time tche1{ 0,0,67 };
    Time tche2{ 0,60,67 };
    Time tche3{ 0,120,3893 };
    std::cout << tche1 << std::endl << tche2 << std::endl << tche3 << std::endl;

}
