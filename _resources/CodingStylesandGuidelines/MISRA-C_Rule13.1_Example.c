// MISRA C:2012 Rule 13.1 states that expressions occurring in an initializer 
// list cannot modify the variables used in those expressions.

#include <stdio.h>
int x=0;
int y=1;
volatile int v;
void printArray (int* arrayptr, int size);

void func()   {
     int arr[2] = {x+y, x-y};
     printf("before inc: x:%i, y:%i v:%i \n", x, y, v);
     int arr2[2] = {x++, x+y}; // -> Ambiguous line
     printf("After inc: x:%i, y:%i v:%i \n", x, y, v);
     int arr3[2] = {v, v};
     printf("\narr: ");
     printArray(arr,2);
     printf("\narr2:");
     printArray(arr2,2);
     printf("\narr3:");
     printArray(arr3,2);
}

int main()
{
    printf("Testing Compiler evaluation order and MISRA\n");
    func();
    return 0;
}

void printArray (int* arrayptr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("|%i|",arrayptr[i]);
    }
}

/*---------------Online GDB output -----------------------------
Testing Compiler evaluation order and MISRA
before inc: x:0, y:1 v:0 
After inc: x:1, y:1 v:0 

arr: |1||-1|
arr2:|0||2|
arr3:|0||0|

...Program finished with exit code 0
Press ENTER to exit console.
*/