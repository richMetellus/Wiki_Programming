/*
This is my implementation of reverse a list of items.
I was asked this question while interviewing at MTS.
*/


#include <iostream>

using namespace std;

void printArray (int* arrayptr, int size);
void reverseList (int* arrayptr, int size);
int main()
{
    int array[] = {10, 7, 3, 12};
    int* arrptr = array; // point to first index of array (& address of first index)
    int arraySize = sizeof(array)/sizeof(int);
    printArray(arrptr, arraySize);
    reverseList(arrptr, arraySize);
    printf("\narray after reverse \n");
    printArray(arrptr, arraySize);
    
    printf("\n-----------------------------------------------------------------\n");
    int oddArray[] = {10, 7, 3, 12, 15};
    int* oddArrptr = oddArray; // point to first index of array (& address of first index)
    int oddArraySize = sizeof(oddArray)/sizeof(int);
    printArray(oddArrptr, oddArraySize);
    reverseList(oddArrptr, oddArraySize);
    printf("\narray after reverse \n");
    printArray(oddArrptr, oddArraySize);
    return 0;
}
void printArray (int* arrayptr, int size)
{
    // cout<< "size of array: " << sizeof(arrayptr)<< endl;
    // cout << "size of int: " << sizeof(int) << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arrayptr[i] << " | ";
    }
    
    // another way to print an array using the pointer.
    // arrayptr = arrayName which points to arrayName[0] address
    // arrayptr + 1 = address of arrayName[1]
    // use the dereference operator *pointerName to get the content
    
    // cout <<endl;
    // for (int i = 0; i < size; i++)
    // {
    //     cout << *(arrayptr + i)<< " | ";
    // }
    // cout <<endl;

}
void reverseList (int* arrayptr, int size)
{
                                                        // say an array {10, 7, 3, 12}
                                                        // indices        0  1  2   3
    int j = size -1;                                    // j = 3
    int temp;
    int i = 0;
    for (; i <size; i++)
    {
        temp = arrayptr[j];                             // temp = 12
                                                        
                                                        // .^----------\   
                                                        //  0          3    
                                                        //[10]       [12]              

        arrayptr[j] = arrayptr[i];                     //[10]       [10]  
        arrayptr[i] = temp;                            //[12]       [10]  
        // odd array length
        if (i == j)
        {
            printf("\nodd length done swapping \n");
            break;
        }
        // even array length
        else if (i == j -1)
        {   
            printf("\neven length done swapping \n");
            break;
        }
        
        j--;
    }
}