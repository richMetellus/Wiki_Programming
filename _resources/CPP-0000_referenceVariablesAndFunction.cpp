// https://www.cs.fsu.edu/~myers/c++/examples/func/constref.cpp

#include <iostream>
using namespace std;

void Func(int &x, const int &y); // x CAN be changed.  y canNOT

int main()
{
    int int1 = 5, int2 = 8;
    cout << "int1 = " << int1 << "\tint2 = " << int2 << '\n';

    // legal call
    Func(int1, int2);
    cout << "int1 = " << int1 << "\tint2 = " << int2 << '\n';

    // legal call
    Func(int1, 20);
    cout << "int1 = " << int1 << "\tint2 = " << int2 << '\n';

    /*
    // ILLEGAL call
    Func(20, int2);
    cout << "int1 = " << int1 << "\tint2 = " << int2 << '\n';
    */
    /* 
        illegal message compilation error

        main.cpp: In function ‘int main()’:
        main.cpp:23:10: error: cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’
           23 |     Func(20, int2);
              |          ^~
        main.cpp:6:16: note:   initializing argument 1 of ‘void Func(int&, const int&)’
            6 | void Func(int &x, const int &y); // x CAN be changed.  y canNOT
              |           ~~~~~^
    */

    return 0;
}

void Func(int &x, const int &y)
// x CAN be changed.  y canNOT
{
    x = x * 2;
    // y = y * 2;		// this is illegal

    cout << "x = " << x << '\n';
    cout << "y = " << y << '\n';
}

/*
    Example Output

    int1 = 5        int2 = 8
    x = 10
    y = 8
    int1 = 10       int2 = 8
    x = 20
    y = 20
    int1 = 20       int2 = 8
 
*/
