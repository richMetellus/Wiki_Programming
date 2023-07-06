
.. _referenceVariableWithAFunctionStart:

When :ref:`reference variables <Reference Variables>` are used as formal parameters, 
this is known as term:`Pass By Reference` (Not to be confused with :term:`call by 
reference`)

.. note::
   Note: In C, we use pointers to achieve call by reference. In C++, we can 
   either use pointers or references for pass by reference.

So to make the distinction, I reserved:
 
 * :term:`call by reference` - Pointers as Function Parameters (Parameters not 
   Argument)
 
 * :term:`pass by reference` - Reference variable as function parameters (C++ only)

**Reference variable example with a function**

.. tabs::

   .. tab:: C++ Only

      .. code-block:: c++
         
         int main() {
          int x = 2;
          pow2(x); // 4
          x;       // 2
        }
          
        int pow2(int& x) {
          // x is an alias to the x in main
          return x * x;
        }

.. note::
   Note any change to ``x`` in ``pow2()`` will actually change the original value, 
   **to avoid this behavior**

   * use ``const``
 
       * e.g. ``int pow2(const int &x)``  // pass by const reference
       * ``void Func3(const int& x);``
       * This would be used to avoid the overhead of making a copy 
         (especially of a large item), but still prevent the data from being 
         changed
 
       *  General format:
       
           * ``const typeName& variableName``
       
               * This establishes variableName as a reference to a location 
                 that cannot be changed  through the use of variableName.
               
               .. seealso::
                  You still can modify the variable if you cast it. Read on ...
         
       * Since the compiler will guarantee that the parameter value cannot change, it IS legal to 
         pass in any :term:`rvalue <Rvalue>` in this case:
       
         .. code-block:: c++
            
            int num = 5;
            Func3(num);		  // legal
            Func3(10);		    // legal
            Func3(num + 50);	// legal
       


**More Constant Reference Parameter examples:**

* When reference variables are used as formal parameters, this is known as **Pass By Reference**
  
  .. code-block:: c++
    
     void Func2(int& x, double& y)
     {
       x = 12;		// these WILL affect the original arguments
       y = 20.5;
     }

  * When a function expects strict reference types in the parameter list, an L-value (i.e. a variable, or storage location) must be passed in
    
    .. code-block:: c++
    
       int num;
       double avg;
       Func2(num, avg);		// legal
       Func2(4, 10.6);		// NOT legal
       Func2(num + 6, avg - 10.6);	// NOT legal

.. note:: 
    
    This also works the same for return types. 
    
    * A return by value means a copy will be made. 
    * A return by reference type sends back a reference to the original.

    .. code-block:: c++

      int Task1(int x, double y);	// uses return by value
      int& Task2(int x, double y);  // uses return by reference

.. collapse:: More Legal and illegal const reference argument examples
   
   .. literalinclude:: ../_resources/CPP-0000_referenceVariablesAndFunction.cpp
      :language: c++


To modify a reference that is qualified by the const qualifier, you must cast 
away its constness with the ``const_cast`` operator. For example:

.. tabs::
   
   .. tab:: C++ Only
      
      .. code-block:: c++
         
         #include <iostream>
         using namespace std;
         
         void f(const int& x) {
           int& y = const_cast<int&>(x);
           ++y;
         }
         
         int main() {
           int a = 5;
           f(a);
           cout << a << endl;
         }
   
**Reference arguments should be used to**

* allow the modification of data inside a function
* speed the program by passing a reference instead of an entire data object  

.. _referenceVariableWithAFunctionEnd:

.. _functionPointersStart:

**Functor: Function Pointer or Pointer to Function**

In C, like normal data pointers (int *, char *, etc), we can have pointers to functions.
A function name, without a following set of parentheses, produces a pointer to that function.

When working with pointers to functions, the C compiler needs to know 

#. not only that the pointer variable points to a function, 
#. but also the type of value returned by that function 
#. as well as the number and types of its arguments.

**Syntax**

* declaring
  
  .. code-block:: c++
     :caption: declaring a function pointer

     returnType (*functionPointerName)(dataTypeofArgument1, ... , datatypeofArgumentN);

  * Examples:

    #. To declare a variable ``fnPtr`` to be of type `pointer to function that returns an int 
       and that takes no arguments`, the declaration is

       .. code-block:: c++
          
          int (*fnPtr) (void);
       
      * The parentheses around ``*fnPtr`` are required because otherwise the C compiler treats 
        the preceding statement as the declaration of a function called fnPtr that returns 
        a pointer to an int (because the function call operator ``()`` in (void) has higher 
        precedence than the pointer indirection operator ``*``).
    
    2. To declare a function pointer variable ``myFuncPtr`` that return nothing but take an int as
       an argument

      .. code-block:: c++
         
         void (*myFuncPtr)(int);

* Initializing

  * To set your function pointer pointing to a specific function:

    #. Simply assign the name of the function to it
       
       .. code-block:: c++
          
          void myFunc(int a);
          myFuncPtr = myFunc;
    
    2. or by prefixing the name of the function with an ampersand ``&``
       
       .. code-block:: c++
          
          void myFunc(int a);
          myFuncPtr = &myFunc;

* Invoking: calling the function pointed to

  * To call the function that is indirectly reference through a pointer variable

    #. apply the function call operation ``()`` to the function pointer

      * general form: ``functionPointerName(arg1, arg2);``

      .. code-block:: c++
         
         int lookup(void);
         int (*fnPtr) (void);
         fnPtr = lookup;
         int entry = fnPtr();
    
    2. or optionally using the dereference operator ``*`` to the function pointer variable

      * form: ``(*functionPointerName)(arg1, arg2)``;

**Benefits of Function Pointers**

* Function pointers provide a way of passing around instructions for how to do something
* You can write flexible functions and libraries that allow the programmer to choose behavior by passing function pointers as arguments
* This flexibility can also be achieved by using classes with virtual functions

**Application of Function Pointers**

#. One common application for pointers to functions is in passing them as arguments to other functions.
  
  * The standard C library uses this, for example, in the function ``qsort``, which performs a 
    “quicksort” on an array of data elements.

2. Another common application for function pointers is to create what is known as `dispatch tables`.
  
  * You can't store functions themselves inside the elements of an array. However, it is valid to 
    store function pointers inside an array.

      - For example, you might create a table for processing different commands that will be 
        entered by a user. Each entry in the table could contain both the command name and a 
        pointer to a function to call to process that particular command. 

.. note::
   
   In c++11, lambda functions are sort of a replacement of functor or function pointer.

.. _functionPointersEnd:

.. _DynamicArraysStart:

Dynamic arrays

c++ Dynamic arrays can be created with 

* general form :
  
  .. code-block:: c++
     
     new data-type[ArraySize], 

* a pointer can be assigned to the location of the first element of the dynamic array

.. tabs::

  .. tab:: C++ 

     .. code-block:: c++

        // dynamic array
        int* p_array = new int[10];
        
        // p_array points to the first element of the array
        // *p_array is the value of the first element using pointer dereferencing
        // p_array[0] is also the value of the first element using array notation
        
        delete [] p_array;


For dynamic array in c, checkout this `article by Appaji <https://www.scaler.com/topics/c/dynamic-array-in-c/>`_

.. _DynamicArraysEnd:

.. _DynamicStructureStart:

C++ Dynamic structures can be created with 

* General form:
  
  .. code-block:: c++
     
     new structName;

* when a pointer pointer to this block of memory we can access the properties with the 
  arrow membership operator ``->``

.. tabs::

   .. tab:: C++ Only

      .. code-block:: c++
         
         struct person {
           
           string name;
           int age;
      
         };
         
         person* p_person = new person;
         p_person->name = "john smith";
         p_person->age = 25;
        
.. _DynamicStructureEnd:
