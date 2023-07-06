######################################
What is MISRA C
######################################

In this, I will explore the MISRA-C and/or C++ Guidelines. I will combine all
the information that are relevant to it here.
(Context: I came accross this guideline because someone on the linkedin embedded
C programming community mentioned it and I start to look it up)

**************************
Intro: What is MISRA C?
**************************

The MISRA C and MISRA C++ standards 

* are a set of coding guidelines for the C and C++ programming languages that 
  promote safety, security, and reliability in embedded system software. 

  * Coding standards for safe, secure, and reliable embedded software

* These guidelines are published by the Motor Industry Software Reliability 
  Association (MISRA), a collaboration between vehicle manufacturers, component 
  suppliers, and engineering consultancies. 

* MISRA C guidelines, which originally targeted only the automotive industry, are 
  now widely accepted and used in other industries such as aerospace and defense, 
  industrial automation, and medical devices.

***************************************************
Why Is MISRA C Important for Embedded Systems?
***************************************************

The C programming language is one of the most popular languages for embedded 
systems because of its intrinsic capabilities, such as performance, 
portability across hardware, and direct control on memory. However, certain 
C language constructs can lead to programming errors, undefined behavior, or 
implementation-defined behavior. The language also enables the 
unwary developer to write dangerous, insecure code that can cause serious 
problems at all stages of a development project and into deployment. For 
applications where safety and/or security are a major priority, these 
shortcomings of the language are a major concern.

The MISRA C guidelines define a “safe-subset” of the C language to protect against 
language aspects that can compromise the safety and security of embedded systems.

For example, 

* C99 allows the use of initializer lists with expressions that can 
  be evaluated only at run-time. However, the order in which the elements of the 
  list are evaluated is not defined.

  .. warning::
     Any code that is sensitive to evaluation order is, thus, compiler dependent 
     and compiler-dependent code should always be considered unsafe.

Take the following Rules violation:


**MISRA C:2012 Rule 13.1 - Expressions occurring in an initializer list cannot 
modify the variables used in those expressions.**

Take this code and its following output

.. tabs:: 
   
   .. tab:: MISRA-CRule13.1Example.c
      
      .. literalinclude:: ../_resources/CodingStylesandGuidelines/MISRA-C_Rule13.1_Example.c
         :language: c
         :emphasize-lines: 13
   
On lines 13, an element of the list modifies the value of a variable that is 
used in another element. The ambiguity in the evaluation order can cause 
unexpected values. For instance, an interpretation of the expression can be that
arr2[] can be initialized with  {1,1}  or  {1,2}, depending on the order in which 
x++ is evaluated. However running that code with 
`Online GDB Compile <https://www.onlinegdb.com/online_c_compiler>`_ the output
I see is ::

  Testing Compiler evaluation order and MISRA
  before inc: x:0, y:1 v:0 
  After inc: x:1, y:1 v:0 

  arr: |1||-1|
  arr2:|0||2|
  arr3:|0||0|


**Rule 13.2 - The value of an expression and its persistent side effects shall 
be the same under all permitted evaluation orders**

The C language standard provides a very wide latitude to compliers with respect 
to evaluation order in expressions. Any code that is sensitive to evaluation 
order is, thus, compiler dependent and compiler-dependent code should always be 
considered unsafe.

**Example 1**

For example, the use of the increment and decrement operators may be troublesome:

  ``val = n++ + arr[n];``

* which element of **arr** is accessed?
* Did the programmer expect the value of **n** used to index the array to be 
  that before the increment or after?

Although it might look as if the increment is performed before the array index, 
that assumes left-right expression evaluation, which is not a valid assumption. 
So, the code is not clear and should be re-written using any of the following 
options:

.. tabs:: 
   
   .. tab:: Option 1
      
      .. code-block:: c
         
         val = n + arr[n+1];
         n++;

   .. tab:: Option 2
      
      .. code-block:: c
         
         val = n++;
         val += arr[n];

   .. tab:: Option 3
      
      .. code-block:: c
         
         val = n;
         n++;
         val += arr[n];
 
 all perform the same operation, and, in fact, an optimizing compiler would most likely generate exactly the same code.


**Example 2:**

A similar problem may occur with multiple function calls used within an 
expression. A function call might have a side-effect that impacts another. 
For example:

  ``val = fun1() + fun2();``


In this case, if either function can affect the result from the other, the code 
is ambiguous. To write safe code, any possible ambiguity must be removed:

  ``val = fun1();``
  ``val += fun2();``

It is now clear that ``fun1()`` is executed first.


**Rule 17.2 - Functions shall not call themselves, either directly or indirectly**

From time to time, an elegant way to express an algorithm is through the use of
recursion. However, unless the recursion is very tightly controlled, there is a 
danger of stack overflow, which can, in turn, result in very hard to locate 
bugs. In safety critical code, recursion should be avoided


**Rule 19.2 - The union keyword should not be used**

Although C is a typed language, typing is not very strictly enforced, and 
developers may be tempted to override typing to “simplify” their code. Adhering 
to the constraints of data types is essential to create safe code, as any 
attempts to get around data types can produce undefined results. The union 
keyword can be used for a number of purposes, which generally result in unclear 
code, but can also be a means to circumvent typing.

One example would be using a union to “take apart” an unsigned integer, thus:

.. code-block:: c
   
   union e
   {
      unsigned int ui;      // 2 - 4 byte depends on compiler
      unsigned char a[4];   // 4 bytes
   }f;
   
In this case, each byte of ``ui`` can be accessed as an element of a. However, 
we cannot be sure whether ``a[0]`` is the least of most significant byte, as 
this is an implementation issue. (Essentially associated with the endianity of 
the processor.)

The alternative might be to use shifting and masking, thus:

.. code-block:: c
   
   unsigned char getbyte(unsigned int input, unsigned int index)
   {
     input >>= (index * 8);
     return input & 0xff;
   }

It may be argued that these rules (and most, if not all, of MISRA C) are just 
common sense and any good programmer would take such an approach. This may be 
true, but a set of clear guidelines leave less to chance.



*****************************
References
*****************************

1. https://www.mathworks.com/discovery/misra-c.html
2. https://www.embedded.com/misra-c-write-safer-clearer-c-code/