.. include::  ../global.rst
   :start-after: [ProgrammingLinksSectionStart]
   :end-before:  [ProgrammingLinksSectionEnd]


######################################################
Object Oriented Programming Concepts Compilation
######################################################

.. contents::
   :depth: 4
   :local:

:term:`Object-oriented programming` (OOP) is a programming paradigm based on the concept of "objects", 
which can contain data and code: data in the form of fields, and code, in the form of procedures.

It is based on objects which is an instance of a class rather than based on functions and logic
like in Functional paradigm/Programming.

* Object-oriented programming aims to implement real-world entities like inheritance, 
  hiding, polymorphism, etc in programming

C is procedural programming and does not have the concept of OOP, so C++ provides OOP for the language.

  ..
    mindmap diagram here if possible

**********************
Packaging Code
**********************

Common ways of packaging code are 

* properties (R. aka variables, fields), methods, classes 
* and namespaces.
  
  * The concept of namespaces are really packages in Java with keyword ``package`` unlike C# and C++ 
    who have the keyword ``namespace``.


************************
Terminology
************************

Class
========

:term:`Class`

* is the building block of OOP. It is a blueprint/ a representation that describe  an object.
* It is a **user-defined data type**, which holds its own data members and member functions, 
  which can be accessed and used by creating an instance of that class (aka object).

* A class provides a set of behaviors in the form of member functions (also known as :term:`methods`), 
  with implementations that belong to all its instances.
* A class also serves as a blueprint for its instances, effectively determining the way that 
  state information for each instance is represented in the form of :term:`attributes` (also known as 
  :term:`fields`, :term:`instance variables`, or :term:`data members`).

* So basically we try to simulate real life stuff in code.

A class has 3 portions

    .. drawio-image:: ./_images/CPP-0000_CppRefresherDiagrams.drawio
       :page-index: 8

#. The class name
#. its recommended instance variables (i.e fields)
#. its recommended methods

* The Class name first letter is usually Capitalized.

..
  use ``pygmentize -L`` to see the list of highlighting available on a machine that have python
  package ``Pygments`` installed.

.. collapse:: A project that made use of OOP concepts

   .. tabs::
      
      .. tab:: Java
         
         .. tabs::
            
            .. tab:: Contact Class
               
               .. literalinclude:: ./_resources/compSciIILabProjs/Lab1Files_AddressBook/code/Lab01/src/Contact.java
                  :language: java
                  :linenos:
   
            .. tab:: Business Class
   
               .. literalinclude:: ./_resources/compSciIILabProjs/Lab1Files_AddressBook/code/Lab01/src/Business.java
                  :language: java
                  :linenos:
               
            .. tab:: Friend Class
   
               .. literalinclude:: ./_resources/compSciIILabProjs/Lab1Files_AddressBook/code/Lab01/src/Friend.java
                  :language: java
                  :linenos:
               
           
   
      
      .. tab:: C#
   
      .. tab:: C++
      
      .. tab:: Python3
   
     
     

Access Modifiers
------------------

The class's attributes (data members), and the method associated with it, 
( or even the class itself depending in the programming language such as Java and C#, not C++ though) 
will have :term:`access modifiers <Access Modifiers>` associate with them. 

The :term:`access modifiers <Access Modifiers>` give them some sort of protection and facilitate the
encapsulation of components.

* They are used to restrict access to the variables and methods of the class


The :term:`access modifiers <Access Modifiers>` are usually :

**Most Common ones in all programming language**

#. ``public``

  * this provide visibility from the class to denote that the class, the data fields and methods can
    be accessed from any other classes.

#. ``protected``

  * this modifier is used to enable the members of the class to be accessed by the subclasses in 
    any package/namespace or classes in the same package/namespace.

#. ``private``
  
  * this modifier make methods and date fields accessible only from withing its own class.
  * use this modifier to prevent direct modifications of data fields. This is known as `data field
    encapsulation`.

      * to make the field accessible outside the class, provide a :term:`getter` also known as :term:`accessor`
        method to return its value.
        
        **getter Method Signature Convention**

        .. tabs:: 

           .. code-tab:: java
   
              public returnType getPropertyName();
              
              // if returnType is boolean
              public boolean isPropertyName();


           .. code-tab:: c#
   
              public returnType getPropertyName();
              
              // if returnType is boolean
              public boolean isPropertyName();
            

           .. code-tab:: c++

              // .h/.hpp file
              public:
                returnType getPropertyName();
          
                // if returnType is boolean
                boolean isPropertyName();
            

           .. code-tab:: python
   
              def getPropertyName(self)
              
              # if returnType is boolean
              def isPropertyName(self)
      
      * to provide means to update the private attribute, provide a :term:`setter` also known as :term:`mutator`
        method to set a new value.

        **Setter methods signature in certain programming language**

        .. tabs:: 

           .. code-tab:: java
   
              public void setPropertyName(dataType propertyValue);

           .. code-tab:: c#
   
              public void setPropertyName(dataType propertyValue);        

           .. code-tab:: c++

              // .hpp/.h file
              public:
                void setPropertyName(dataType propertyValue);
            

           .. code-tab:: python
   
              def setPropertyName(self, propertyValue)
                       

Not so common

4. ``default`` (Java)
5. ``internal`` (C#)


In **C++**, 

* only the first 3 access modifiers are available in that language. (only The most common one).
* there is no notion of an entire class having an access specifier the way that there is in Java or C#. 
  If a piece of code has visibility of a class, it can reference the name of that class and manipulate it. 
  That said, there are a few restrictions on this. Just because you can reference a class doesn't 
  mean you can instantiate it, for example, since the constructor might be marked private. 
  Similarly, if the class is a nested class declared in another class's private or protected section, 
  then the class won't be accessible outside from that class and its friends.

  * according to this `stackoverflow question <https://stackoverflow.com/questions/4855422/c-classes-public-private-and-protected>`_

In **Python**,

* The keywords such ``public, protected, private`` do not exist. Instead python uses the following:

  #. **No underscore** in front of the name = ``public``
  #. a **singe underscore** in front of the name ``_`` = ``protected``
  #. a **double underscore** in front of the component (method, field) ``__`` = ``private``

.. warning:: 

   Do not confused :term:`access modifiers <Access Modifiers>` with other `regular`, `non-access` modifiers such  as

   #. ``final``
   #. ``synchronized``
   #. ``abstract``
   #. ``native``
   #. ``strictfp``
   #. ``transient``
   #. ``volatile`` 
   
Constructors
----------------

a :term:`constructor <Constructor>` is a **special method** that is used to initialize objects.
The :term:`constructor <Constructor>` is  called when an object of a class is created.

In **java, c#, c++**

* The constructor(s) **Must** be the same as the Class name.
* a constructor cannot be abstract, final, static, or Synchronized.
* Access modifiers can be used in constructor declaration
* Constructors do not have a return type, not even ``void``
* A constructor can be overloaded but can not be overridden.

   * There is no concept of Virtual Constructor in C++ or Java. That's why the
     factory design pattern is a good pattern to use to create new objects that
     are different ways of initializing the object.

* You can have 3 types of constructors

  * no-parameter (no-arg) constructor
  * default constructor

    * The compiler will create **a no-arg constructor with an empty body** during run-time if a constructor is 
      not explicitly defined in the class. If we define our own constructor, the compiler does not create a
      default constructor

  * Parameterized Constructor



In **python**,

* all constructor are done through the python built-in ``__init__(self)`` function definition

**Constructors Examples**

.. collapse:: constructor examples In many programming languages Java, C#, C++ and Python
   :open:

   .. tabs:: 

      .. tab:: java
           
           .. note::
              
              You can put the two classes into one file in Java, but only one class in the file can be a public class. 
              Furthermore, the public class must have the same name as the file name. (intro to Java by Liang, pg 325)

           * Explicitly defined default constructor
   
           .. literalinclude:: ./_resources/ConstructorExamples.java
              :language: java
              :lines: 1-20, 59
              :linenos:
              :emphasize-lines: 19
   
           * Implicit default constructor will be created by compiler at run-time
   
           .. literalinclude:: ./_resources/ConstructorExamples.java
              :language: java
              :start-after: [StudentClassSectionStart]
              :end-before: [StudentClassSectionEnd]
              :linenos:
              :emphasize-lines: 7
   
   
           Constructor From the Full code about the contact book shown earlier, up above.
   
           * a parameterized constructor
   
           .. literalinclude:: ./_resources/compSciIILabProjs/Lab1Files_AddressBook/code/Lab01/src/Contact.java
              :language: java
              :lines: 6-24, 104
              :linenos:
              :emphasize-lines: 13-19
           
      .. tab:: c#

      .. tab:: c++
          
          .. note::
             
             You can put the many classes into one file in C++ header file, the naming of the file does
             not matter. the filename doesn't have to be the same name as the class name in Java.
            
          * Explicitly defined default constructor

           .. tabs::
              
              .. tab:: ConstructorExamples.h

                 .. literalinclude:: ./_resources/CPP/CPP_ConstructorExamples/CPP-0000_1_ConstructorExamples.h
                    :language: c++
                    :lines: 1-19, 71-
                    :linenos:
                    :emphasize-lines: 5, 15-16
              
              .. tab:: ConstructorExamples.cpp

                 .. literalinclude:: ./_resources/CPP/CPP_ConstructorExamples/CPP-0000_1_ConstructorExamples.cpp
                    :language: c++
                    :lines: 1-13, 80-
                    :linenos:
                    :emphasize-lines: 4, 6-8
                
              
           * Implicit default constructor will be created by compiler at run-time
   
           .. literalinclude:: ./_resources/CPP/CPP_ConstructorExamples/CPP-0000_1_ConstructorExamples.h
              :language: c++
              :start-after: [StudentClassSectionStart]
              :end-before: [StudentClassSectionEnd]
              :linenos:
              :emphasize-lines: 10
   
   
           Constructor From the Full code about the contact book shown earlier, up above.
   
           * a parameterized constructor
   
           .. literalinclude:: ./_resources/compSciIILabProjs/Lab1Files_AddressBook/code/Lab01/src/Contact.java
              :language: java
              :lines: 6-24, 104
              :linenos:
              :emphasize-lines: 13-19 
   
      .. tab:: python
   


Constructor Overloading
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

**Constructor overloading**

* The concept of having more than one constructor with different parameters so that every 
  constructor can perform a different task

* Overloaded constructors have the same name (name of the class) but the different number of arguments. 
  Depending upon the number and type of arguments passed, the corresponding constructor is called.

* This concept is valid in most OOP programming language (Java, C#, C++, Python)

.. collapse:: Constructors Overloading
   :open:

   .. tabs:: 
      
      .. tab:: C++

         .. collapse:: full Program example

            .. literalinclude:: ./_resources/CPP/CPP_ConstructorExamples/ConstructorOverloadingExample.cpp
                :language: c++
                :linenos:
                :emphasize-lines: 62-116, 164-186

Constructor Chaining/Delegation
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

**Constructor chaining** refers to the ability to call a constructor inside another constructor. 
You can use a constructor chain either within the same class or even with another one. 
For the latter, the constructor should be through inheritance from the super class.

One of the main use of constructor chaining is to avoid duplicate codes while having multiple 
constructor (by means of constructor overloading) and make code more readable.

* this make the program simpler, with fewer repeated lines of code.

Imagine you have this code:

.. tabs::

   .. tab:: C++

      .. literalinclude:: ./_resources/CPP/CPP_0000_1_ConstructorChainingDupCode.cpp
         :language: c++
         :linenos:
         :emphasize-lines: 12-13, 20-21

Lines 12-13, 20-21 are duplicated code.

When you want to share initialization code among multiple constructors, there are generally two approaches.

#. Initialization Method
#. Constructor Chaining


**Initialization Method**

With the initialization method as first approach is to create a private initialization method 
that you call from each constructor:


.. tabs::

   .. tab:: C++

      .. literalinclude:: ./_resources/CPP/CPP_0000_1_ConstructorChainingInitializeFunc.cpp
         :language: c++
         :linenos:
         :emphasize-lines: 9-13, 19, 24

When you write your own common initialization function, the compiler duplicates this code in each 
constructor that calls the base constructor. This of course creates a lot overhead.
Let see the alternative `constructor delegation`.


**Constructor Delegation**

Constructor delegation is done by using this format:

* declare an overloaded constructor followed by ``:`` followed by an existing constructor we want to delegate to.

.. code-block:: 

   ConstructorName(param1, param2, ..., paramN): 
   ConstructorName() {
   }

   // or
   ConstructorName(param1, param2, ..., paramN): 
   ConstructorName(param1) {
   }

.. tabs::

   .. tab:: C++
      
      .. literalinclude:: ./_resources/CPP/CPP_0000_3_ConstructorChaining.cpp
         :language: c++
         :linenos:
         :emphasize-lines: 39-41, 47-50



Operator Overloading with Examples
----------------------------------------


Java doesn't supports operator overloading because it's just a choice made by its creators who 
wanted to keep the language more simple. Every operator has a good meaning with its 
arithmetic operation it performs.

For comparing Objects in Java, I tend to implement Comparator interface.

Copy Constructor
""""""""""""""""""""

 ..
  this can be part of compile-time polymorphism 



Object
=========

..
  how to instantiate an object in C++

Explicit initialization with constructors 
-------------------------------------------



Interface
=============
..
  how to define an interface in C++, Java, Python


Encapsulation
=================

..
  example of Encapsulation in C++, Java, Python


Abstraction
===============

..
  example of Abstraction in C++, Java, Python

abstract data types 


Inheritance
===============

..
  example  in C++, Java, Python


Polymorphism
===============

..
  example in C++, Java, Python


Function Overloading
------------------------


Dynamic Binding
==================



Message Passing
==================

************************
Design Patterns
************************


***********************************
Frequently Asked Questions (FAQ)
***********************************

Frequently asked questions by Mailman 3 administrators.



1. Confirmation emails to Users has wrong domain name (example.com!)
=====================================================================

Difference between a virtual function and a pure virtual function 
===================================================================

* https://stackoverflow.com/questions/21187965/c-code-explanation-for-method-prototype-with-const-0 

Pure virtual method 

* use the keyword virtual and ``= 0`` after the function which is not supposed to change the data of the class (``const``)
* ex: ``virtual void setManufacturer(const Manufacturer& make) = 0;`` where Manufacture is a struct
* ex: ``virtual Manufacturer getManufacture() const = 0;``

Virtual function

* only declare virtual and doesn't have =0.

**The Difference**

Unlike a non-virtual function, when a virtual function is overridden the most-derived version is 
used at all levels of the class hierarchy, rather than just the level at which 
it was created. Therefore if one method of the base class calls a virtual method, 
the version defined in the derived class will be used instead of the version defined in the base class.

This is in contrast to non-virtual functions, which can still be overridden in a derived class, 
but the "new" version will only be used by the derived class and below, but will not change 
the functionality of the base class at all.

whereas..

   .. note::
      A pure virtual function or pure virtual method is a virtual function that is required to be 
      implemented by a derived class **IF** **the Derived class** is **NOT abstract.**

      // left to be implemented by Concrete Class.

When a pure virtual method exists, the class is "abstract" and can not be instantiated on its own. 
Instead, a derived class that implements the pure-virtual method(s) must be used. A pure-virtual isn't defined in the base-class at all, so a derived class must define it, or that derived class is also abstract, and can not be instantiated. Only a class that has no abstract methods can be instantiated.

The ``virtual`` keyword provides a way to override the functionality of the base class, and a pure-virtual requires it.
* |InterfaceVsAbstractClassInC++| 