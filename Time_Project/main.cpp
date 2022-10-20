 #include "time.hpp"

// test cases for constructors
void test_ctors();

// test  cases for operators
void test_opt();

// test cases for comparisons
void test_comp();


void test_time()
{
    Time t1{ 0, 0, 1 };
    Time t2(0, 0, 2);
    Time t3(0, 0, 3);
    Time t4{ 0, 0, 1 };

    std::cout << "\nTEST COMPERISON OPERANDS:\n";

    for (int i = 0; i < 4; i++)
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
        if (i == 3)
        {

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

    test_time();
    //test_comp();

    //Time t1{ 10, 59, 0 };
    //Time t2{ t1 };
    //Time t3 = t1;
    //Time t4{};
    //Time t5{ Time{11,22,33} };
    //Time zero{};
    //t1.hours(1);
    //t1.minutes(2);
    //t1.seconds(3);


    //std::cout << t1;
    ////t1.show_time();
    //t2.hours(50);
    //
    //std::cout << t2;
    ////t2.show_time();
    //std::cout << t3;

    ////t3.show_time();
    //t4 = t1;
    ////t4.show_time();
    //std::cout << t4;
    ////t5.show_time();
    //std::cout << t5;

    //Time t6 = t1 + t5;
    ////t6.show_time();
    //std::cout << t6;

    //Time t7 = zero + 25660;
    //Time t8 = 70984 + zero;
    ////t7.show_time();
    ////t8.show_time();
    //std::cout << t7 << t8;
}

void test_ctors()
{

}

void test_opt()
{

}

void test_comp()
{
    bool a,b;
    std::cout << std::boolalpha;
    Time t1{ 0,0,1 };
    Time t2{ 0,0,2 };
    /*a = t1 == t2;
    std::cout << t1 << " == " << t2 << " ? " << a << std::endl;
    b = t1 != t2;
    std::cout << t1 << " != " << t2 << " ? " << b << std::endl;

    t1.minutes(1);
    a = t1 == t2;
    b = t1 != t2;
    std::cout << t1 << " == " << t2 << " ? " << a << '\n'
        << t1 << " != " << t2 << " ? " << b << '\n';

    t2.hours(1);
    a = t1 == t2;
    b = t1 != t2;
    std::cout << t1 << " == " << t2 << " ? " << a << '\n'
        << t1 << " != " << t2 << " ? " << b << '\n';

    t1.hours(1);
    t2.minutes(1);
    a = t1 == t2;
    b = t1 != t2;
    std::cout << t1 << " == " << t2 << " ? " << a << '\n'
        << t1 << " != " << t2 << " ? " << b << '\n';*/
    a = t1 > t2;
    b = t1 < t2;
    std::cout << t1 << " > " << t2 << " ? " << a << '\n'
        << t1 << " < " << t2 << " ? " << b << '\n';
     
        
}