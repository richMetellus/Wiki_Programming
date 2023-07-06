/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

https://www.onlinegdb.com/online_c++_compiler

*******************************************************************************/
//[CodeSectionStart]

#include <iostream>

using namespace std;

const int k_size = 3;
double sum(int* a, int k_size);
void doubleArr(int* a, int k_size);

void printArray (int* arrayptr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << *(arrayptr + i)<< " | ";
    }
}

int main() {
  int a[k_size] = {1, 2, 3};
  cout << "array content before doubling each element:" << endl;
  // a copy of pointer a is passed to the function.
  printArray(a, k_size);
  cout << "\nsum: "<< sum(a, k_size) << endl; // 6
  cout << "*a:" << *a << endl;     // 1
  
  doubleArr(a, k_size);
  cout << "\narray content after doubling each element:" << endl;
  printArray(a, k_size);
  cout << endl<< "sum: "<< sum(a, k_size) << endl; // 12
  printArray(a, k_size);

}

void doubleArr(int* a, int k_size) {
  // a is another pointer to the original array
  // the pointer is passed by value which means parameter a is a copy of the pointer.
  // operation on the parameter (a) will cause value on the original array to change.
  // parameter a is private to this function
  for (int i = 0; i < k_size; ++i) {
    a[i] = *(a + i) * 2; 
    // the above  statement is equivalent to // a[i] = a[i] *2;
  }
  
  //TODO: Question to answer:
  // is this local pointer "a" is destroyed when the function exit?
  // can that same memory address represented by a, be re-used?
}
double sum(int* a, int k_size) {
  // a is another pointer to the original array
  // a is private to this function
  int sum = 0;
  for (int i = 0; i < k_size; ++i) {
    sum += *a;
    a++;
  }
  return sum;
}

//[CodeSectionEnd]

/* Console Output
[ConsoleOutputSectionStart]
array content before doubling each element:
1 | 2 | 3 | 
sum: 6
*a:1

array content after doubling each element:
2 | 4 | 6 | 
sum: 12
2 | 4 | 6 | 

...Program finished with exit code 0
Press ENTER to exit console.
[ConsoleOutputSectionEnd]

*/