#include <iostream>

using namespace std;

int main()
{
    
    // [Array-Initializing-Section]
    /* 
       Ways of Initializing Array in C/C++
       ==========================================================================
    */
    //-------------------------------------------------------------------------------------------
    int numbersArray[] = {1, 2, 3};
    cout<<"numbersArray Address: " << numbersArray << endl << "Size of Arr: " << sizeof(numbersArray)<< " bytes" <<endl;
    printf ("size of int: %ld bytes \n", sizeof(int));
    
    //-------------------------------------------------------------------------------------------
    
    //-------------------------------------------------------------------------------------------
    // This will compile in C but throws a compile error in C++ ``sorry, unimplemented: 
    // non-trivial designated initializers not supported``
    // This defines a 10-element array called a (based on the highest index into the array), 
    // and initializes the last element to the value of x + 1 (1234), and the 
    // first three elements to 1, 2, and 3,respectively.
    
    // int x = 1233;
    // int a[] = { [9] = x + 1, [3] = 3, [2] = 2, [1] = 1 };
    //-------------------------------------------------------------------------------------------

    //-------------------------------------------------------------------------------------------
    // Array declaration by specifying size and initializing
    // elements
    int arrWithSpecifiedSize[6] = { 10, 20, 30, 40 };
    // Compiler creates an array of size 6, initializes first
    // 4 elements as specified by user and rest two elements as
    // 0. above is same as  "int arr[] = {10, 20, 30, 40, 0, 0}"
    
    int numbersArrayAllElementInitializetoZero[3] = {};  // same as arr[] = {0, 0, 0}
    //-------------------------------------------------------------------------------------------

    //-------------------------------------------------------------------------------------------
    int arrayWithOperation[5];
    arrayWithOperation[0] = 5;
    arrayWithOperation[2] = -10;
    arrayWithOperation[3 / 2] = 2; // this is same as arrayWithOperation[1] = 2
    arrayWithOperation[3] = arrayWithOperation[0];
    //-------------------------------------------------------------------------------------------
    
    //-------------------------------------------------------------------------------------------
    // With recent C/C++ versions, we can also
    // declare an array of user specified size
    int n = 10;
    int variableLengthArray[n];
    //-------------------------------------------------------------------------------------------

    //-------------------------------------------------------------------------------------------
    // This C++ program compiles fine
    // as index out of bound
    // is not checked in C.
    
    int arr[2];
    
    // cout << arr[3] << " ";
    // cout << arr[-2] << " ";
    //-------------------------------------------------------------------------------------------

    //-------------------------------------------------------------------------------------------
    // Array declaration by initializing it 
    // with more elements than specified size.
    
    // In C, it is not a compiler error to initialise an array with more elements 
    // than the specified size. For example, the below program compiles fine and shows just a Warning.
    
    // The program won’t compile in C++.
    // it will show ``main.cpp:58:73: error: too many initializers for ‘int [2]’``
    
    // int arrayWithMoreElementThanSpecifiedSize[2] = { 10, 20, 30, 40, 50 };
    //-------------------------------------------------------------------------------------------

    //-------------------------------------------------------------------------------------------
    // This array is initialized to the characters 'M', 'o', 'n', 'd', 'a', 'y',and '\0',respectively.
    char today[] = "Monday";
    //-------------------------------------------------------------------------------------------
    // [Array-Initializing-Section-End]
    
    // [Array-and-Pointers-Section]
    // ==========================================================================
    int numbers[] = {1, 2, 3};
    cout << "address of numbers array         : " << numbers << endl;
    cout << "value of &numbers                : " << &numbers << endl;
    cout << "value of &numbers[0]             : " << &numbers[0] << endl;
    int* p_numbers = numbers;
    cout << "address of pointer-to-array      : " << p_numbers << endl <<endl;     // points to the first element of the array
    
    cout << "address of pointer-to-array + 1  : " << p_numbers + 1 << endl;  // points to the second element of the array
    cout << "address of pointer-to-array + 2  : " << p_numbers + 2 << endl;  // points to the third element of the array
   
    // NOTE:
    //  numbers[0] == *(p_numbers)
    //  numbers[1] == *(p_numbers + 1)
    //  numbers[2] == *(p_numbers + 2)
    
    cout << "value of &numbers + 1            : " << &numbers + 1 << endl;
    cout << "value of numbers + 1             : " << numbers + 1 << endl;
    /*
        Example of output

        address of numbers array         : 0x7ffe5fc787bc
        value of &numbers                : 0x7ffe5fc787bc
        value of &numbers[0]             : 0x7ffe5fc787bc
        address of pointer-to-array      : 0x7ffe5fc787bc

        address of pointer-to-array + 1  : 0x7ffe5fc787c0
        address of pointer-to-array + 2  : 0x7ffe5fc787c4
        value of &numbers + 1            : 0x7ffe5fc787c8
        value of numbers + 1             : 0x7ffe5fc787c0
    */
    // [Array-and-Pointers-Section-End]

    return 0;
    
}


/*
Arrays and Function
=================================================
*/

// making variable length array 
int makeVals (int n) 
{
    int valArray[n];
}