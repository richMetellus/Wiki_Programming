.. include:: /global.rst

###########################################
C and C++ Refresher
###########################################

.. contents::
   :depth: 4
   :local:

******************************
Mechanics of a C/C++ program
******************************

Usually you'll a c module consist of 2 files:

1. A header file (.h)
2. An implementation file (.c, .cpp)


A *translation unit* 

* consists of an implementation file and all the headers that it includes 
  directly or indirectly

A program consists of one or more translation units

Steps to write a program:

1. **Write source code**

  1.1 Unix extensions: 

    * For C++ source files:  ``.cc, .cxx``
    
    * For C sources files: ``.C, .c``

  1.2 GNU C++ extensions: 

    * For C source files: ``.C, .c``
    * For C++ source files: ``.cc, .cxx, .cpp, .c++``

2. **Compile the source code** - translate the code to machine code, the file containing the 
   translation is the *object code* of the program
3. **Link the object code with additional code** - combination of the source code with 
   *startup code* and *libraries object code* to produce a *runtime version*, the final product 
   is a file called the *executable code* which contains a set of machine language instructions

4. **Execute the program**


******************************
C/C++ Project Structure
******************************

* https://medium.com/swlh/c-project-structure-for-cmake-67d60135f6f5 

.. code-block:: bash
   
   ssyscs@NewYoctoBuildVM:~/Workspace/Projects$ mkdir -p C_andCppProgrammingProjectTemplate/{bin,lib,src,build,data,doc,examples,test,include/{project,3rdparty}}

   ssyscs@NewYoctoBuildVM:~/Workspace/Projects$ tree C_andCppProgrammingProjectTemplate/

   C_andCppProgrammingProjectTemplate/
   ├── bin
   ├── build
   ├── data
   ├── doc
   ├── examples
   ├── include
   │   ├── 3rdparty
   │   └── project
   ├── lib
   ├── src
   └── test

**Simple project structure**

The main idea about project structure is that you have at least 2 folders ``include`` and ``src``. 

Folders purpose is:

* include - PUBLIC header files (.h files).
* src - PRIVATE source files (.h and .m files).
* test - tests files if you write tests (indefinitely you should).
* lib - third party or your own libraries you depend on.


Headers files in include should be under folder named after your library 
domain. 

* Reason behind this is that when you expose public header files you expose 
  only include directory and when you #include files from library you do 
  this ``#inlcude <HMM/Algorithm.h>`` instead of 
  ``#include "Algorithm.h"`` if it was in root of include.

.. list-table:: Different Ways to Structure C++ Project:
   
   * - Project Template
     - Concrete Example
     - More Concrete Example

   * - Project Template
       
       .. code-block:: bash 
          
          {library_name}
          ├── include
          │   └── {library_domain}
          ├── src
          ├── test
          └── libs
          
     - **Concrete Example**
       
       .. code-block:: bash
         
          HMM
           ├── include
           │   └── HMM
           │       └── Algorithm.h
           ├── src
           │   ├── Algorithm.cpp
           │   ├── FancyMath.h
           │   └── FancyMath.cpp
           └── test
               ├── AlgorithmTests.cpp
               └── FancyMathTests.cpp
       
       concrete example we have ``HMM`` library which exposed only ``Algorithm.h`` 
       header file. ``FancyMath`` files are private and not exposed. 
       Library domain is HMM, so when you want to include public header 
       for example Algorithm.h you do it this way: ``#include <HMM/Algorithm.h>``
       instead of #include "Algorithm.h" .

     - More Concrete Example
       
       .. code-block:: bash
          
          Foo
          ├── include
          │   └── Foo
          │       ├── Foo.h
          │       └── ...
          ├── src
          │   ├── Foo.cpp
          │   └── ...
          ├── test
          │   └── ...
          └── libs
              ├── A
              │   ├── include
              │   │   └── A
              │   │       ├── A.h
              │   │       └── ...
              │   ├── src
              │   │   ├── A.cpp
              │   │   └── ...
              │   └── test
              │       └── ...
              └── B
                  ├── include
                  │   └── B
                  │       ├── B.h
                  │       └── ...
                  ├── src
                  │   ├── B.cpp
                  │   └── ...
                  └── test
                      └── ...

How I think I should Structure my project
===============================================

The way you structure your project will depends on its complexity and and what
tools (IDE, build system) you use.

so the typical thing I see for the project structure is:

Project Structure Template
---------------------------------------


.. list-table:: Project Structure Template
   :header-rows:1
   
   * - Library Project Template
     - Multi-apps Project template

   
   * - For library, I would use something similar to this

       .. code-block:: bash
          :caption: structure for c/c++ library
         
          Foo ---> LibraryName
          |
          └── CMakeList.txt
          ├── include                          # Public header (good for API)
          │   └── Foo                          # ---> same name as Library
          │       ├── Foo.h
          │       └── ...
          ├── src
          │   ├── Foo.cpp
          │   └── ...
          ├── Project
          │   ├── cmake
          │   |   └── ToolChains
          |   |       ├── Toolchain-aarch64-xilinx-linux.cmake
          │   └── vs
          |       ├── Foo.sln
          ├── test
          │   └── ...
          └── libs or tools
              ├── A
              │   ├── include
              │   │   └── A
              │   │       ├── A.h
              │   │       └── ...
              │   ├── src
              │   │   ├── A.cpp
              │   │   └── ...
              |   └── test
              └── B
                  ├── include
                  │   └── B
                  │       ├── B.h
                  │       └── ...
                  ├── src
                  │   ├── B.cpp
                  │   └── ...
                  └── test
                      └── ...

     - For Multi-app software, I would use something similar to this

       .. code-block:: bash
          :caption: structure for c/c++ project
         
          FooProject-embedded                 # ---> ProjectName
          |
          └── CMakeList.txt
          ├── include                          # Public header (good for API)
          │   └── Foo                          # ---> same name as Library
          │       ├── Foo.h
          │       └── ...
          ├── src                              # --> similar to p-dist in Dorado
          │   ├── App or Apps
          │   |   ├── UI
          │   |   └── MainControllerApp
          │   |   └── FlashloadApp
          │   └── BSP
          │   |   ├── bsp.c
          │   |   └── bsp.h
          │   |   
          │   ├── Common                      # -> all source files that are can be shared among say BSP and Communication
          │   └── Communication (J1939 stack) # if a lib, then Communication would be wrapper, API to the library J1939 lib
          ├── Project
          │   ├── cmake
          │   |   └── ToolChains
          |   |       ├── Toolchain-aarch64-xilinx-linux.cmake
          │   └── vs
          │       ├── sub-componentVSProject  # <-- different
          |           ├── subcomponentVsProject.sln
          ├── test
          │   └── ...
          └── libs or tools     # library that the software project will depend on
              ├── A
              │   ├── include
              │   │   └── A
              │   │       ├── A.h
              │   │       └── ...
              │   ├── src
              │   │   ├── A.cpp
              │   │   └── ...
              |   └── test
              └── B
                  ├── include
                  │   └── B
                  │       ├── B.h
                  │       └── ...
                  ├── src
                  │   ├── B.cpp
                  │   └── ...
                  └── test
                      └── ...   

When doing large scale c or c++ project that might have different sub-components,
you might have an SoC that have FPGA and Linux App, in my professional experience
I like when the project folder structure is organize by its architecture.
if you have a subsystem then this can be a folder under src of its own.

Folders purpose is:

* include - PUBLIC header files (.h files).
* src - PRIVATE source files (.h and .c files anything part of the library.).

  * src/common can include:

    * source files that are share among multiple sub-systems (BSP, Middleware)
      it is a sort of bridge or utils that will allow software re-use and keep
      DRY principle.
  
  * src/app -- if the application is one app specific. In that case it would said 
    a specific app that do specific things for one product (like a RIOC)
  * src/apps -- if you have multiple apps that might be product variant specific

  * if src is like dorado p-dist and is following software architecture then you can
    
    * src/<linux-controller>

      * BSP <linux-bsp>

    * src/<fpga-controller>

      * sub-component

        * motor control.c
    
    .. note:: 
       the architecture will dictate the folder structure. if you can keep the folder
       hierarchy under src somewhat close to the block diagram of the architecture
       the merrier.

* test - tests files if you write tests (indefinitely you should).
* tools or lib - third party or your own libraries you depend on. 

  * you might have google test framework folder with the source files in there

* Project - if you are supporting different way to build the software library

  * cmake project can go there

    * this might include different folder which themselves include  ``.cmake``
      files.
     
  * visual studio project solutions (vs) can go there.

    * this might include multiple visual studio project
    * for visual studio project, it might be wise not having any source files in
      that project.

        * with Visual studio you can add file to a project solution.
          see the way I structure the Alten code solution. 

* You may also have a folder ``scripts`` that have engineering scripts, test script
  engineering script.



Re-usable stuff that many apps can use will be framework.

* Each app needs to do some common set of tasks in its life.

  * things like power-down, communication, manage data, diagnostics.

  * Group all these under one entity called Middleware or Framework.


*********************************************************
Variables and Data Types
*********************************************************

Legend:

- ``[]`` : means optional
- ``<>`` : means required

Variable Declaration
=======================

variables or variableName 

* are just memory allocated at compile time. 
* A name to reference a memory address in a computer program.

:term:`Declaration`` of a variable or function 

* simply declares that the variable or function exists somewhere in the 
  program, but the memory is not allocated for them.

  * it helps the compiler (what type it is)
  * in case of function, it tells the parameters and their types, and the return
    value.

:term:`Definition`

* when we define a variable or function, in addition to everything that a 
  declaration does, **it also allocates memory for that variable or function**. 
  
  * Therefore, we can think of definition as a superset of the declaration 
    (or declaration as a subset of definition).


Variable declaration Format:

- ``[type-qualifier(s)] [type-modifier] <data-type> <variable-name> = <initial-value>;``
- ex:
  
  .. code-block:: c++
     :linenos:
     :caption: different ways of declaring/defining a variable and assign it a value.

     extern int number;                     // just a declaration and not define (no mem allocation)
     extern void bubble_sort(int, int[]);    // just a declaration
     int foo(int arg1, char arg2);          // just a declaration. the extern keyword is implicitly assumed by compiler 
     int staticVarDemoFunc()
     {
        static int count = 0;
        count++;
        return count

     }
     int main()
     {
         const unsigned char foo = 'A';
         const unsigned char anotherChar = 65;    // ASCII code of A

         int my_number;                           // just a variable declaration and definition, no assignment
         my_number = 7;                          // variable assignment

         // understand static var

         printf("%d", staticVarDemoFunc());
         printf("%d", staticVarDemoFunc());
         
     }
             

Type qualifiers
----------------

Type qualifiers

- are used to provide specific instructions to the compiler on how the variable should be managed. 
- These include:

    - ``const`` (C89) constant. Present in C++
    - ``volatile`` (C89). Present in C++
    
      * volatile, indicates that an object may be changed by something external to the program 
        at any time and so must be re-read from memory every time it is accessed.
      
      * The volatile keyword is intended to prevent the compiler from applying any optimizations 
        on objects that can change in ways that cannot be determined by the compiler. 
      
      * In C, and consequently C++, the ``volatile`` keyword was intended to:

        * allow access to memory-mapped I/O devices
        * allow uses of sig_atomic_t variables in signal handlers.
      
      * declaration form:

        .. code-block:: c++
           
           // both declaration valid
           volatile int a;
           int volatile b;
      
      * Like other datatypes, we can use volatile pointers, structures, unions etc. 
        The volatile structures and unions can be volatile itself, and their member variables can 
        also be of type volatile.

    - ``restrict`` (C99), C Only, not really supported in in C++ (* asterisk on that)

      * In C, A restrict-qualified pointer (or reference) is basically a promise to the compiler 
        that for the scope of the pointer, the target of the pointer will only be accessed through 
        that pointer (and pointers copied from it).
      
      * C++ compilers also support this definition for optimization purposes, but it is not a 
        part of the official language specification.
      
      * `Links <https://www.tutorialspoint.com/What-does-the-restrict-keyword-mean-in-Cplusplus#:~:text=restrict%20is%20a%20keyword%20in,and%20pointers%20copied%20from%20it).>`_

    - ``_Atomic`` (C11), c-only.
    - ``extern``(c and c++) [2]_

      * used when a particular file need to access a variable from another file.
      * **may be applied to a global variable, function, or template declaration.**

        * I have never seen it used on local variable

      * When we write ``extern <data-type> <some_variable_name>;``
        
        * no memory is allocated. 
        * Only property of variable is announced.
      
      * Extern variable says to compiler:
        
        "go outside my scope and you will find the definition of the variable 
         that I declared."
      
      * tells the compiler that a variable is defined in another source module 
        (outside of the current scope). The linker then finds this actual 
        declaration and sets up the extern variable to point to the correct 
        location.

        * Compiler believes that whatever that extern variable said is true 
          and produce no error. 
        * Linker throws an error when it finds no such variable exists.

          * When an extern variable is initialized, then memory for this is 
            allocated and it will be considered defined.

      * As an exception, when an extern variable is declared with initialization, 
        it is taken as the definition of the variable as well.

        in C this will compile:

        .. code-block:: c
           
           extern int var = 0;
           int main(void)
           {
            var = 10;
            return 0;
           }
          
        where as this will not compile:

        .. code-block:: c
           
           extern int var;
           int main(void)
           {
            var = 10;
            return 0;
           }
        
        * because var is declared but not defined anywhere (compiler hasn't allocated any
          memory for var) and the program is trying to change the value to 10 
          of a variable that doesn't exist at all.
           

      * useful when creating library
    
    - ``static``
      
      * When static keyword is used, variable or data members or functions can 
        not be modified again. 
        
          * It is allocated for the lifetime of program

    
      * Static variable

        * Syntax: ``static <data-type> <variable-name> = <variable-value>``
        * Static variables have a property of preserving their value even 
          after they are out of their scope!

          * remains in memory while the program is running

        * Static variables are initialized only once. 
          
          * Compiler persist the variable till the end of the program. 
          * The static variables are alive till the execution of the program.


        * Static variable can be defined inside or outside the function. 
            
            * They are local to the block.


        * Default value:

          * Static variables (like global variables) are initialized as 0 if 
            not initialized explicitly
        
        * use when:
          
          * We should use a static variable whenever we want to reuse the 
            modified value of the variable inside a function in the next function call.
          
          * (C++ only) When we want all the objects to maintain a single copy of 
            the class variable.

      * Static function

        .. note:: Static function in C.

           Remember **in C**, 

           * **functions are global by default.** 
           
             * The ``static`` keyword before a function name make it static. 
               
               * Access to static functions is restricted to the file where they 
                 are declared. 
             
             Used:
             
             * when we want to restrict access to functions, we make them static. 
             
             * Another reason for making functions static can be reuse of the same 
               function name in other files.

            .. warning:: do not confuse static function in C with static function in 
               C++ OOP

               In C++ OOP,  Static function:

               * is a member function that is used to access only static data 
                 members. 
                 
                 * It cannot access non-static data members not even call 
                   non-static member functions

               * It helps to call functions that using class without using objects.  

               * A static member function cannot be declared with the keywords 
                 virtual, const, volatile, or const volatile.
               
               * remains in memory during the lifetime of the program

               * use when:
                 
                 * (C++ only) When we want all the objects to maintain a single copy of 
                   the class variable/function.

                   * it will not get memory each time when the instance is created.


Type Modifiers
---------------

Type modifiers

- are used to increase the size of these types or change the properties of the variables. 
- These include:

    #. ``short``, 
    #. ``long``, 
    #. ``unsigned``, 
    #. or ``signed``. 


Data types
--------------

.. drawio-image:: ../_images/CPP-0000_CppRefresherDiagrams.drawio


| Data is stored in memory as a series of bits where 8 bits equal 1 byte.
| Data types are means to identify the type of data and associated operations of handling it. 
| There are three types of data types:

1. Pre-defined DataTypes
2. Derived Data Types
3. User-defined DataTypes


Primitive Built-in data types
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Primitive Built-in data types: 

* Integer types

    #. ``char``: Character,
    #. ``int``: Integer

* Floating point types:
    3. ``float``: Floating point number
    #. ``double`` Double floating point,

* Boolean:

    5. ``bool``

* Valueless
    
    6. ``void``

* Wide character

    7. ``wchar_t``



Derived Types
^^^^^^^^^^^^^^^^^^^^^


* Derived types:

    * :ref:`Functions`
    * :ref:`Arrays`
    * :ref:`Pointers`
    * :ref:`Structures`
    * :ref:`Unions`



User-define Data Type
^^^^^^^^^^^^^^^^^^^^^^

User-define Data Type:

* ``typedef``

* Enumerated types:

    #. ``enum``


Data-type Ranges
^^^^^^^^^^^^^^^^^

* Based on what data-modifiers we use, the range and storage length of the data might vary.
* The size of variables might be different from those shown in the table below, depending on 
  the compiler and the computer you are using.

    - We can also use the ``sizeof()`` operator to get size of various data types.

* Each position represents a value and a magnitude. 
  Sign numbers are represented with the two's complement form.

    .. drawio-image:: ../_images/CPP-0000_CppRefresherDiagrams.drawio
       :page-index: 1
       :format: svg


    .. csv-table:: Datatype Ranges
       :file: /Programming/_resources/CPP-0000_DataTypeRanges.csv
       :header-rows: 1
       :widths: 30, 30, 50, 50, 30


.. code-block:: c++
   :caption: sizeof(<datatype>)

   #include <iostream>
   using namespace std;
   
   int main() {
      cout << "Size of char : " << sizeof(char) << endl;
      cout << "Size of int : " << sizeof(int) << endl;
      cout << "Size of short int : " << sizeof(short int) << endl;
      cout << "Size of long int : " << sizeof(long int) << endl;
      cout << "Size of float : " << sizeof(float) << endl;
      cout << "Size of double : " << sizeof(double) << endl;
      cout << "Size of wchar_t : " << sizeof(wchar_t) << endl;
   
      return 0;
   }
   


.. code-block:: bash
   :caption: sizeof(<datatype>) example output

   Size of char : 1
   Size of int : 4
   Size of short int : 2
   Size of long int : 4
   Size of float : 4
   Size of double : 8
   Size of wchar_t : 4

..
    talk about overflow here  



Global and local variables
============================

.. code-block:: c++
   :caption: global and local variable declaration


   #include <iostream>
   using namespace std;
   
   int global = 10;
   
   int main() {
     int local = 5;
     return 0;
   }

.. important:: 

    When you want to declare an array of say, a million integers, declaring it as local might 
    not work depending on various factors, like memory issues for one.

    But as a general rule, you will see most everyone declares large arrays that the program will 
    need as global, thus creating the array in heap memory. **I would suggest doing this.**

.. note::
    
    Declaring variables using the new operator or using STL structures like vectors allocates the 
    memory to heap in this case, meaning it can be declared locally as well.



***********
Operators
***********

    .. drawio-image:: ../_images/CPP-0000_CppRefresherDiagrams.drawio
       :page-index: 2
       :format: svg


Data is assigned and manipulated using a variety of operators. 
There are multiple types of operators which include:

#. Logical operators
#. Bitwise operators
#. Arithmetic operators
#. Relational operators



Logical Operators
==================

Logical operators

* Logical operators perform on a conditional basis. Meaning only if the expression before and after the operators are logically true
* They consist of

    - AND ``&&``, OR ``||``, and NOT ``!``. 
        
        - Know that logical AND, OR conditions are expressed in pairs and are usually used in 
          conditional blocks, such as if-else statements or while statements 


Bitwise Operators
==================

Bitwise operator

* Bitwise operators are logic operators that operate on an individual bit basis instead of a full expression, but these two types of operators are not the same.
* The bitwise operators include
    
    - left shift ``<<`` and right shift ``>>``, 
    - Bitwise OR ``|``, 
    - Bitwise AND ``&``, 
    - Bitwise XOR ``^``, 
    - and a one's complement or a bitwise invert ``~``

Arithmetic Operators
=====================

Arithmetic operators

- Arithmetic operators perform your typical math operations, such as

    - add ``+``, 
    - subtract ``-``, 
    - multiply ``*``,  
    - divide ``/``, 
    - increment ``++``, 
    - decrement ``--``, 
    - and modulus ``%``
    
- The modulus operator is the remainder operator 
- and increment and decrement can be done before or after the data access. 


Relational Operators
======================

Relational operators

- Relational operators are similar to logical operators used for Boolean expressions in conditional blocks. 

    - This check for things like 

        - less than ``<``, less than or equal to ``<=``, 
        - greater than ``>``, greater than or equal to ``>=``,
        - exactly equal to ``==``, and not equal to ``!=``

**************************************
Data Type Conversion/ Type Casting
**************************************


*************
Functions
*************

Functions 

* are small blocks of code used to organize a software idea that takes in a list of parameters 
  and can return a piece of data. These use the same types that were discussed before. 
* functions require both a declaration and a definition. 

The general format for declaring a function definition is as follows:

.. code-block:: c++

   returnType functionName ( type1 param1, type2 param2, ... ) 
   {
        variableDeclarations
        programStatement 
        programStatement 
        
        ...

        return expression; 
   }
   

**Steps to build a function**

#. Provide a function prototype
#. Provide a function definition
#. Call the function

**Function Declaration/Prototype**

* the declaration or function prototype specifies the function type, a unique name, and 
  the parameter list. 

**Function definition**

* The function definition mimics a copy of the function declaration, but it also includes the 
  contents or definition of the function body

.. code-block:: c++
   
   // function prototype
   double cube(double x);
   
   int main() {
     // function call
     double q = cube(2.2);
   }
   
   // function definition
   double cube(double x) {
     return x * x * x;
   }

Passing Argument to Function by Value
=======================================

When a function is called with basic types for arguments the function creates 
a new variable and initializes it with the same value, i.e. the function 
works with a copy with basic types

.. code-block:: c++
   
   int main() {
     double x = 1.3;
     cube(x);
     // ..
   }
   
   double cube(double x) {
     // x is passed by value (a copy of x is passed)
     // x is private to this function
     return x * x * x;
   }
   
Call or Pass By Reference
==================================

Pointer as Function Parameter - Call by reference
------------------------------------------------------

However we can pass instead the address of the basic type which means that the 
function should be rewritten to use pointers.


.. code-block:: c++

   int main() {
     double x = 1.3;
     cube(&x);
     // ..
   }
   
   double cube(double* x) {
     // x is passed by value
     // x is private to this function
     return (*x) * (*x) * (*x);
   }

When we call the function by passing the address of the variable, this technique
is known as *call by reference* in C (beginnersbook.com)

* Pointers as function parameters: allow the function to be called by reference
* This is useful for complex structures if we want to save time/space by passing 
  a reference to the structure instead of passing the entire structure 

.. code-block:: c++

   struct person {
     string name;
     int age;
   };
   
   int main() {
     person john = { "john doe", 25 };
     greet(&john); // call by reference
     // ..
   }
   
   double cube(person* someone) {
     // someone is private to this function
     // someone is a pointer to the original person
     someone->age;       // 25
   } 


Passing an Array to a function using a Pointer to an Array
---------------------------------------------------------------------

When a function is called with an array what's sent actually is the name of 
the array which is the address of the first element/a pointer-to-int (``int *``), 
this is different from basic types because the array is not copied, instead the 
function works with the original array

.. code-block:: c++

   const int k_size = 3;
   
   int main() {
     int a[k_size] = {1, 2, 3}
     sum(a, k_size);         // 6
     cout << *a << endl;     // 1
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

Reference Variable as Function Parameters - Pass by Reference (C++ only)
----------------------------------------------------------------------------

.. include:: ./C_CPP_commonInclude.rst
   :start-after: referenceVariableWithAFunctionStart:
   :end-before:  referenceVariableWithAFunctionEnd



Comparing: Value vs. Reference
=================================

.. list-table:: Passing by value vs Passing by Reference
   :header-rows: 1
   :class: my-class
   :name: my-name

   * - Pass By Value
     - Pass By Reference

   * - * The local parameters are copies of the original arguments passed in
       * Changes made in the function to these variables do not affect originals

     - * The local parameters are references to the storage locations of the 
         original arguments passed in.
       
       * Changes to these variables in the function will affect the originals
       * No copy is made, so overhead of copying (time, storage) is saved.
         Thus, Pass-by-references is more efficient than pass-by-value.

Comparing: Pass-by-reference vs. Pass-by pointer (C++)
========================================================

https://www.ibm.com/docs/en/zos/2.4.0?topic=calls-pass-by-reference-c-only

.. list-table:: Passing by reference vs Passing by pointer
   :header-rows: 1
   :class: my-class
   :name: my-name

   * - Pass By Reference
     - Pass By Pointer


   * - Pointers can be NULL or reassigned
     - References cannot be NULL or reassigned
    
Inline functions
=================

When a program is executed and a function is about to be invoked the following steps occur with 
the program

- store the memory address of the next instruction
- copy function arguments to the stack
- jump to the memory address the function is located
- execute the function code
- jump back to the instruction stored

A little enhancement to speed up the program is to make the function *inline*, that is the program 
replaces the function call with the function code avoiding the jumps

When to use it:

- the function is small and called very often

    - ``inline double cube(double x) { return x * x * x; }``

..
    Cochan Programming in C; Appendix A, section 7.3 

Function Pointers
===================

.. include:: ./C_CPP_commonInclude.rst
   :start-after: functionPointersStart:
   :end-before:  functionPointersEnd

********
Arrays
********

Arrays 

* can be defined to contain any basic data type or any derived data type

  * Arrays of functions are not permitted (although arrays of function pointers are).

* It is a group of variables of **similar data types** referred to by a single element.
*  is a collection of similar data items stored at contiguous memory locations and elements 
   can be accessed randomly using indices of an array
* Array declaration and initialization form:

  * ``data-type arrayName[arraySize]  = { arrayElement0, arrayElement1, ... };``

* Array index starts with 0 and goes till the size of the array minus 1.

    .. drawio-image:: ../_images/CPP-0000_CppRefresherDiagrams.drawio
       :page-index: 6

* array variable name is interpreted as the address of the first element of the array.

Different ways of initializing an array
=========================================

Array initialization 

.. collapse:: A Compilation of how to declare and initialize an array in C and or C++
   :open:
   
   .. literalinclude:: ../_resources/CPP-0000_AllAboutArrays.cpp
      :language: c++
      :linenos:
      :start-after: [Array-Initializing-Section]
      :end-before: [Array-Initializing-Section-End]
   
   .. code-block:: c++
      :caption: code-block output: https://www.onlinegdb.com/online_c++_compile 

      numbersArray Address: 0x7ffcbee7e8e4
      Size of Arr: 12 bytes
      size of int: 4 bytes 
      size of int: 4 bytes 
      size of int: 4 bytes 
      2 32764 
      2 32764 
      2 32764 
      
      ...Program finished with exit code 0
      Press ENTER to exit console.  

Arrays and Pointer
=====================

C/C++ handles arrays internally using pointers which may seem equivalent, an ordinary array variable 
name is interpreted as the address of the first element of the array.

.. code-block:: c++
   
   int numbers[] = {1, 2, 3};
   numbers;      // address 0x0065fd40
   numbers[0];   // 1, the value allocated in memory
   // NOTE: numbers ~ &numbers[0]
   
   // since a pointer is a reference to an address we can also do
   int* p_numbers = numbers;
   *p_numbers;   // 1, the value in memory accessed through pointer dereferencing


Adding one to a pointer variable increases its value by the number of bytes of the type to 
which it points.

   .. literalinclude:: ../_resources/CPP-0000_AllAboutArrays.cpp
      :language: c++
      :linenos:
      :start-after: [Array-and-Pointers-Section]
      :end-before: [Array-and-Pointers-Section-End]
   

The value ``&numbers`` is the address of a 3-int block of memory, so even though 
``&numbers[0] == numbers == &numbers`` numerically the value of ``&numbers + 1 != numbers + 1`` 
because ``&numbers + 1`` points to the next 3-int block of memory however ``numbers + 1`` 
points to the second element of the initial 3-int block of memory

* ``numbers`` is type pointer-to-int or ``int*``
* ``&numbers`` is type pointer-to-array-of-3-int or ``(*int)[3]``
   
   
Array of Pointers
--------------------

.. code-block:: c++
   
   int a = 1, b = 2;
   int* p[2] = {&a, &b};

Since ``p`` is a pointer to the first element which is ``&a`` and ``&a`` is another pointer 
then we can reference ``p`` with a pointer to pointer 

* .. code-block:: c++ 
     
     int** q = p;


Arrays and Functions
=======================


How to Pass an Array to a Function in C/C++
----------------------------------------------

C/C++ does not allow to pass an entire array as an argument to a function. 
However, You can pass a pointer to an array by specifying the array's name without an index.

If you want to pass a single-dimension array as an argument in a function, you would have to declare
function formal parameter in one of following three ways and all three declaration methods produce 
similar results because each tells the compiler that an integer pointer is going to be received.

.. tabs::
   
   .. tab:: Way-1
      
      Formal Parameters as pointer as follow

      .. code-block:: c++
         
          void myFunction(int *param) {
            
            // program_statements;
            // program_statements;
            // program_statements;
          }

   .. tab:: Way-2
      
      Formal parameters as a sized array as follows

      .. code-block:: c++
         
          void myFunction(int param[10]) {
            
            // program_statements;
            // program_statements;
            // program_statements;
          }


   .. tab:: Way-3
      
      Formal parameters as an unsized array as follows 

      .. code-block:: c++
         
          void myFunction(int param[]) {
            
            // program_statements;
            // program_statements;
            // program_statements;
          }


How to return a local array from a Function in C/C++
------------------------------------------------------

C/C++ programming does not allow to return an entire array as an argument to a function. However, 
you can return a pointer to an array by specifying the array's name without an index.

3 ways of returning an array from a function:

1. Using **Static Array**
#. Using **Dynamically Allocated Array**
#. Using **Struct**

To return a single-dimension array from a function, define the function in the form

.. tabs::

   .. tab:: Way-1: Static Array

      To return a single-dimension array from a function, define the function in the form
      
      * .. code-block:: c++
           
           data-type* myFunction() 
           {
              // declare and/or initialize the the array
              static data-type arrayName[size];
      
              return arrayName;  
              
           }

      * C or C++ does not advocate to return the address of a local variable to outside of the function, 
        so you would have to define the local variable as ``static`` variable.


   
   .. tab:: Way-2: Dynamically Allocated Array

      Dynamically allocated memory (allocated using ``new`` or ``malloc()``) remains there until we 
      delete it using the ``delete`` or ``free()``.
      
      * .. code-block:: c++
           
           data-type* myFunction() 
           {
              // declare and/or initialize the the array
              data-type* arrayName = new data-type[size];
      
              return arrayName;  
              
           }


   .. tab:: Way-3: Using Struct

      We can wrap the array in a structure/class and return an instance of the struct/class. 
      The reason for this work is, that the array of members of structures is deeply copied
      
      * .. code-block:: c++
           
           // declare a new structure type
           struct userDefinedTypeStruct {

            data-type arrayName[size]; 
           }

           struct userDefinedTypeStruct myFunction() 
           {
              // declare a new structure of type userDefinedTypeStruct
              struct userDefinedTypeStruct structName;
      
              return structName;  
              
           }          

Dynamic Arrays
=================

.. include:: ./C_CPP_commonInclude.rst
   :start-after: DynamicArraysStart:
   :end-before:  DynamicArraysEnd


***************
Vectors (C++)
***************   

************
Pointers
************

Pointers are variables that store addresses of values rather than the values themselves.

There are 3 operators used with respect to pointer variables

#. To declare a pointer we use the pointer  ``*`` operator in the form:

  * ``<data-type> * pointerVariableName``
  * The datatype followed by 0 or more space , then pointer Declaration Operator ``*``
    followed by 0 or more space then pointerVariableName.

  * Ex] ``int* ptrToInt`` or ``int * ptrToInt``

2. The address-of operator ``&``

  * This is used to assign the address of a previously **declared** variable to 
    the pointer variable

    * ``pointerName = &<previously-declared-variableName>;``
    * Ex]
      
      .. code-block:: c++
         
         int quantity = 5;
         int* ptr_quantity;           // Pointer Declaration Operator
         ptr_quantity = &quantity     // Address-of Operator

    .. drawio-image:: ../_images/CPP-0000_CppRefresherDiagrams.drawio
       :page-index: 4

3. The pointer dereference Operator ``*``, 
  
  * which is used after a pointer declaration, is used to dereference a point in memory. 
  * form: ``*ptrVariableName``

    * this gives you the contents of the address in memory (the contents of the variable) pointed 
      by the pointer.

Pointers:

* can point to any type
* hold memory addresses
* Pointers are used to pass data by reference

Pointer Operation Visualization
=================================


    .. drawio-image:: ../_images/CPP-0000_CppRefresherDiagrams.drawio
       :page-index: 5


``int* ptr_quantity``

* declaring/defining a pointer of type int.
* this will indicate to the compiler that pointer will point to a memory location
  capable of holding a value of sizeof(int).

``*ptr_quantity = a_value;``

*  we are writing to the memory location pointed by ptr_quantity

``a_variable = *ptr_quantity;`` 

* we are reading the memory location pointer by ptr_quantity, take the value hold in
  that memory location a assign it to ``a_variable``

.. card:: Meaning of "referencing" and "dereferencing" 
   
    *ref*: https://stackoverflow.com/questions/14224831/meaning-of-referencing-and-dereferencing-in-c

    **Referencing** means taking the address of an existing variable (using &) to 
    set a pointer variable. In order to be valid, a pointer has to be set to 
    the address of a variable of the same type as the pointer, without the 
    asterisk:

    .. code-block:: c 
       
        int  c1;
        int* p1;
        c1 = 5;
        p1 = &c1;
        //p1 references c1
    
    **Dereferencing** a pointer means using the * operator (asterisk character) 
    to retrieve the value from the memory address that is pointed by the 
    pointer.
        .. note:: NOTE: The value stored at the address of the pointer must be 
            a value OF THE SAME TYPE as the type of variable the pointer 
            "points" to, but there is no guarantee this is the case unless 
            the pointer was set correctly. The type of variable the pointer 
            points to is the type less the outermost asterisk.
        
    .. code-block:: c 

        int n1;
        n1 = *p1; 

    
    **Invalid dereferencing** may or may not cause crashes:

    * Dereferencing an uninitialized pointer can cause a crash
    * Dereferencing with an invalid type cast will have the potential to cause a crash.
    * Dereferencing a pointer to a variable that was dynamically allocated and 
      was subsequently de-allocated can cause a crash
    * Dereferencing a pointer to a variable that has since gone out of scope 
      can also cause a crash.
    
    **Invalid referencing** is more likely to cause compiler errors than crashes, 
    but it's not a good idea to rely on the compiler for this.
    
    References:

    * http://www.codingunit.com/cplusplus-tutorial-pointers-reference-and-dereference-operators

        .. compound:: 
            :class: light-gray-bg 

            & is the reference operator and can be read as “address of”.
            * is the dereference operator and can be read as “value pointed by”.
    
    * http://www.cplusplus.com/doc/tutorial/pointers/

        .. compound:: 
            :class: light-gray-bg 

            & is the reference operator    
            * is the dereference operator
    
    * http://en.wikipedia.org/wiki/Dereference_operator 

        .. compound:: 
            :class: light-gray-bg 

            The dereference operator * is also called the indirection operator.


Pointer to Function
======================

.. include:: ./C_CPP_commonInclude.rst
   :start-after: functionPointersStart:
   :end-before:  functionPointersEnd


*********************
Reference Variables
*********************

A reference variable is a nickname that acts as an alias for some previously declared variable.

.. code-block:: c++
   
   int p;
   int& q = p;

   int n = 5;          // this declares a variable, n 
   // The following three declarations are equivalent:
   int& r = n;        // this declares r as a reference to n 
   int &r = n;
   int & r = n; 

In this context ``&`` is not the address operator, instead it serves as part of the type identifier, 
like ``int*`` is a pointer-to-int ``int&`` is a reference-to-int

* a reference must be initialized to a defined variable when declared
* a reference is like a const pointer e.g. ``int& r_n = n;`` is like ``int* const r_n = &n;``

The regular variable and the reference are in the same scope, so it seems silly. 
("Why do I need to call it r when I can call it x ?")

* references variables are most useful when the 2 variables are in `different scopes` 
  (this means functions!)

.. code-block:: c++
   
   int n = 5;
   int* p_n = &n;
   int& r_n = n;
   
   // the following expressions can be used interchangeably
   // - *p_n, r_n, n  to get the value
   // - p_n, &r_n, &n to get the address

Reference Variable as Function Parameters - Pass by Reference
===============================================================

.. include:: ./C_CPP_commonInclude.rst
   :start-after: referenceVariableWithAFunctionStart:
   :end-before:  referenceVariableWithAFunctionEnd

************
Structures
************

:term:`Structures`

* another tool for grouping several related variables of **same or different type** together.
  
  * Each variable in the structure is known as a **member** of the structure.

Create a Structure
===================

To create a struct

* use the keyword ``struct`` in the form:
  
  .. code-block:: c++
     
     struct {             // Structure declaration
       int myNum;         // Member (int variable)
       char myString[size];   // Member (string variable  c-style)
     } myStructureNameType;       // Structure variable

  .. code-block:: c++
     
     struct {             // Structure declaration
       int myNum;         // Member (int variable)
       char myString[size];   // Member (string variable  c-style)
     } myStructureNameType1, myStructureNameType2, ..., myStructureNameTypeN ; // Multiple Structure variable

  .. code-block:: c++
     
     struct myStructureNameType {             // Structure declaration
       int myNum;         // Member (int variable)
       char myString[size];   // Member (string variable c-style)
     };    

* Examples of struct declaration and initialization:

  * Initializing structures is similar to initializing arrays
  
  .. code-block:: c++
     
     struct date {
     
        int month; 
        int day; 
        int year;
     };
     

     struct person {
       string name;
       int age;
     };

     int main() {

       person john = { "john doe", 25 };
       struct date today, tomorrow;
       // ..
     }

  * By giving a name to the structure, you can treat it as a data type. The definition of ``date`` 
    in a sense defines a new type. ``today`` and ``tomorrow`` are declared to be of type struct ``date``

    * To create a **named structure**, put the name of the structure **right after** the ``struct`` keyword:

.. collapse:: Compilation of different ways of declaring and initializing structure

   .. literalinclude:: ../_resources/CPP-0000_AllAboutStructures.cpp
      :language: c++
      :linenos:


Difference between C Structure and C++ Structures
===================================================

* https://www.geeksforgeeks.org/difference-c-structures-c-structures/ 

* Also write a section  about the difference between c++ structure and class
* https://medium.com/nerd-for-tech/difference-between-c-structures-and-c-structures-examples-included-90ec56499981 

Dynamic Structures
=====================

.. include:: ./C_CPP_commonInclude.rst
   :start-after: DynamicStructureStart:
   :end-before:  DynamicStructureEnd

************
Unions
************

Union 

* is a type structure similar to struct used in more advanced programming applications, that can 
  contain different type of data types

* declaring

  * general format: similar to struct

    .. code-block:: c++

       union unionName {

          memberDeclaration 
          memberDeclaration 
          ...

        } variableList;

    * ex]

      .. code-block:: c++

         union mixed {

            char c;
            float f; 
            int i; 

         };

         int main(void)
         {
            union mixed x;
            
         }

  * Each member of the union shares overlapping storage space, and the compiler takes care 
    of ensuring that enough space is reserved to contain the largest member of the union.

  * ``union`` differs to ``struct`` in the way memory is allocated.

    * Declaring a variable to be of ``type union mixed``, as in ``union mixed x``;
      does NOT define ``x`` to contain three distinct members called ``c``, ``f``,and ``i``; rather, 
     **it defines x to contain a single member that is called either c, f, or i.**

      * In this way, the variable x can be used to store either a char or a float or an int, 
        but not all three (or not even two of the three)

  .. warning::

     Because the float, char,and int members of x all exist in the same place in memory, 
     only one value can be stored in x at a time. Furthermore, 
     it is the programmer responsibility to ensure that the value retrieved from a union is 
     consistent with the way it was last stored in the union.

* Initializing

  .. collapse:: Compilation of different ways of declaring and initializing Union
     :open:

     .. literalinclude:: ../_resources/CPP-0000_AllAboutUnions.cpp
        :language: c++
        :linenos:

*************
Enumeration 
*************


Enums: 

* Enums are user-defined types that consist of named integral constants.
* used to assign constants to a set of names to make the program easier to read, 
  maintain and understand.
* Declaring

  * An Enumeration is declared by using the keyword ``enum``, followed imediately by the enumerated 
    type name, followed by the variable list

  * ex]

    .. code-block:: c++
       
       enum month { january, february, march, april, may, june, july, august, september, 
                    october, november, december };
       enum month thisMonth; 
       
       // defines an (unnamed) enumerated data type with values east, west, south, or north, and 
       // declares a variable orientation to be of that type
       enum { east, west, south, north } orientation;


* initializing

  * Variables declared to be of this data type (enum month in this case) can only be assigned 
    the values in the variable list

  .. code-block:: c++
     
     enum month thisMonth; 
     // ...
     thisMonth = february;

* The compiler actually treats enumeration identifiers as integer constants. 
  Beginning with the first name in the list, the compiler assigns sequential integer values 
  to these names, starting with 0

  * You can skip the sequence as follow

    .. code-block:: c++
       
       enum direction { up, down, left = 10, right };
  
    * in this example, 
      
      * ``up = 0``, compiler increment so ``down = 1``
      * ``left = 10`` because it is explicitly assigned this value; 
      * and ``right = 11`` because it appears immediately after left in the list.

* Enumeration identifiers can share the same value

  .. code-block:: c++
     
     enum switch { no=0, off=0, yes=1, on=1 };

****************************
The ``typedef`` Statement
****************************

The ``typedef`` keyword

* provides a capability that enables you to assign an alternate name to a data type

To define a new type name with typedef, follow these steps: 

1. Write the statement as if a variable of the desired type were being declared. 
2. Where the name of the declared variable would normally appear, substitute the new type name.
3. In front of everything, place the keyword ``typedef.``

Examples of typedef use-case:

.. tabs::
   
   .. tab:: C/C++

      .. literalinclude:: ../_resources/CPP-0000_TypdefExamples.cpp
         :language: c++
         :linenos:

*********************************************
Conditional Statements: if-else, switch
*********************************************

A conditional statement is a statement that specifies whether some associated statement(s)/block
should be executed or not.

C/C++ supports two basic kinds of conditionals:

*  ``if`` statements and 
* ``switch`` statements


*****************************************************
Loops and The ``break`` and ``continue`` Statement
*****************************************************

A more advanced control statement is called the loop

- A loop allows a block of code to be repeated based on a condition. These vary on pre or post loop checks. 
- These loops are

    - ``for`` loop,
    - ``while`` loop,
    - and a ``do`` ``while`` loop. 


The ``for`` Statement
==========================


    .. drawio-image:: ../_images/CPP-0000_CppRefresherDiagrams.drawio
       :page-index: 3

The general format for declaring the for statement is as follows:

* .. code-block:: c++

     for ( variable-initialize_expression_1; condition_expression_2; variable-update_expression_3 ) 
         programStatement;

* example
  
  .. code-block:: c++
     :caption: c++, c for loop

     for (int i = 0; i < 5; ++i)
     {
        // statement(s)
        if ( array[i] < 0) {
            break;                      // --> exit loop immediately
        }
        if ( array[i] == 0) {
            continue;                   // --> move to next iteration (i + 1), checks condition
        }
            
     }

The ``while`` Statement
==========================


The ``do`` Statement
==========================

The general format for declaring the do statement is as follows:

* .. code-block:: c++
     
     do
     {
          // Loop body code
          programStatement
  
     } while ( condition_expression );
  


.. The Basic Integer Type ``int``
.. ===================================

.. An unassigned integer will be initialized with the value 0.

.. .. code-block:: bash
..    :caption: unassigned int

..     #include <iostream>

..     using namespace std;

..     int main()
..     {
..         int unassignedInt;
..         cout<<"unassignedInt:" <<unassignedInt ;

..         return 0;
..     }

.. .. code-block:: bash
..    :caption: code output

..    unassignedInt:0
   
..    ...Program finished with exit code 0
   


.. The Floating Number Type ``float``
.. ===================================


************************************
Dynamic/Runtime Memory Allocation
************************************

Dynamic data structures are data structures that grow and shrink as you need 
them to by allocating and deallocating memory from a place called the heap. 
They are extremely important in C because they allow the programmer to exactly 
control memory consumption.

Pointers are sort of an alias for memory accessed which could be accessed by named variables 
(memory allocated in compile time), however in C++ only,

* we can allocate memory in runtime with the operator ``new``, 
* runtime allocated memory can be freed with the operator ``delete``

In C, you'd have to use  **Dynamic Memory Allocation Functions** from ``#include <stdlib.h>``
Given ``n`` and ``size`` represent ``integers of type size_t``, and ``pointer`` represents 
``a void pointer``

#. ``void *calloc(n, size)``

  * Allocates contiguous space for n items of data, where each item is size bytes in length. 
    The allocated space is initially set to all zeroes. 
  * **On success**, a pointer to the allocated space is returned; 
  * **on failure**, the null pointer is returned

2. ``void *malloc(size)``

  * Allocates contiguous space of size bytes, returning a pointer to the beginning of the allocated 
    block if successful, and the null pointer otherwise.

3. ``void *realloc(pointer, size)``

  * Changes the size of a previously allocated block to size bytes, returning a pointer to the 
    new block (which might have moved), or a null pointer if an error occurs.

In C, runtime allocated memory can be freed using the dynamic memory allocation function ``free``

#. ``void free(size)``

  * Returns a block of memory pointed to by pointer that was previously allocated 
    by a ``calloc``, ``malloc``, or ``realloc`` call


**Advantages of runtime allocated memory:**

* Memory is allocated only when needed

**Drawbacks of runtime allocated memory:**

* **Memory allocated by** ``new`` **must be freed using** the operator ``delete`` **otherwise** we have 
  **a memory leak** 
  
  - which is memory allocated but unused, if it grows too large it can halt the execution of the program

* An attempt of freeing a block of memory previously freed results in an undefined behavior 
  i.e. don't use delete twice on the same block of memory in succession

  .. code-block:: c++
     
     // p_int address = 0x0065fd40
     int* p_int = new int;
     delete p_int;
     
     int oranges = 5;
     int* p_oranges = &oranges;
     // INVALID since delete works only with memory allocated with new
     delete p_oranges;
     

Additional notes regarding runtime allocated memory

* Ordinary variable have their values stored in a memory region called the `stack`, 
* memory allocated with ``new`` have their values stored in a memory region called 
  the `heap`

Dynamic Arrays
=================

.. include:: ./C_CPP_commonInclude.rst
   :start-after: DynamicArraysStart:
   :end-before:  DynamicArraysEnd

Dynamic Structures
=====================

.. include:: ./C_CPP_commonInclude.rst
   :start-after: DynamicStructureStart:
   :end-before:  DynamicStructureEnd

**************************
Input/Output Operations
**************************

**************************
Other Topics
**************************

Other topics to look at

* Error Handling in C vs Exception Handling in C++
* 

****************************************
Difference between C and C++
****************************************


*********************
References/Sources
*********************

* https://www.tutorialspoint.com/cplusplus/cpp_data_types.htm

    - This link talks about c++ data types

.. [2] `Understanding "extern" keyword in C - GeeksforGeeks`_