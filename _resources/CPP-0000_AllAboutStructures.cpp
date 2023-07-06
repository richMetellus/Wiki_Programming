#include <string>
#include <iostream>
using namespace std;

struct date
{

    int month;
    int day;
    int year;
};

struct time {
    int hour; 
    int minutes; 
    int seconds;
};

struct myTime {
    int hour; 
    int minutes; 
    int seconds;
};

struct person
{
    string name;
    int age;
};

struct {
  string brand;
  string model;
  int year;
} myCar1;

struct {
  string brand;
  string model;
  int year;
} myCar2, myCar3; // We can add variables by separating them with a comma here

int main()
{
    person john = {"john doe", 25};
    struct date today, tomorrow;
    today       = {10, 8, 2022};
    
    // Another way to intialize it by assigning each variable.
    tomorrow.day = today.day + 1; 
    tomorrow.month = today.month; 
    tomorrow.year = today.year;
    
    struct date purchaseDate = {5, 10, 2020};
    // ..
    
    /* Illegal. See the position of myCar1 in the definition above
    struct myCar1 toyotaCam  = {"Toyota", "Camry", 2018};
    myCar1 toyotaCorrola  = {"Toyota", "Corrolla", 2018};
    */
    
    /* above will produce the error
        main.cpp: In function ‘int main()’:
    main.cpp:40:19: error: variable ‘main()::myCar1 toyotaCam’ has initializer but incomplete type
       40 |     struct myCar1 toyotaCam  = {"Toyota", "Camry", 2018};
          |                   ^~~~~~~~~
    main.cpp:41:12: error: variable ‘main()::myCar1 toyotaCorrola’ has initializer but incomplete type
       41 |     myCar1 toyotaCorrola  = {"Toyota", "Corrolla", 2018};
          |            ^~~~~~~~~~~~~
    */
    
    // Legal
    myCar1.brand = "Mercedes";
    myCar1.model = "4matic";
    myCar1.year  = 2011;
    
    // Put data into the second structure
    myCar2.brand = "Ford";
    myCar2.model = "Mustang";
    myCar2.year = 1969;
    
    myCar1.year  = 2011;
    
    // Put data into the second structure
    myCar3.brand = "Chevy";

    // Print the structure members
    cout << myCar1.brand << " " << myCar1.model << " " << myCar1.year << "\n";
    cout << myCar2.brand << " " << myCar2.model << " " << myCar2.year << "\n";
    cout << myCar3.brand << " " << myCar3.model << " " << myCar3.year << "\n";

    
    // intialize a member through variable
    int myHourVariable = 22;
    struct time currentTime1 = {myHourVariable, 33, 10}; // legal
    
    // initialize the members in any order in the general format .member = value
    // don't need to initialize all members
    
    // time currentTime2 = {.hour = 12, .minutes = 10}; // illegal. Compiler throw an error without struct in front of time
    struct time currentTime2 = {.hour = 12, .minutes = 10}; // legal
    myTime currentTime3 = { .hour =12, .minutes = 10};  // legal. be carefull with reserved keyword

    return 0;
}

/* 
    Mercedes 4matic 2011
    Ford Mustang 1969
    Chevy  0
*/


