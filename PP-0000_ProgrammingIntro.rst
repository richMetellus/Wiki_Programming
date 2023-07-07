.. _ProgrammingIntro:

########################################################################
What is Programming and How is A programming Language Is Created
########################################################################


************************************************
What is Programming and Programming Languages
************************************************

:term:`programming languages`

* are essentially a set of instructions that a computer understands.

* Programming languages are created with the help of existing ones, such as C++. 
  You will need to pass through different stages, such as designing syntax 
  structures, creating and setting up a compiler or interpreter, arranging a 
  standard library for the language, and putting together supporting build 
  systems and editors.

************************************************************
History and Evolution of Computer Programming Languages
************************************************************

A good essay on the history and evolution of computer programming Languages
can be accessed on the 

* `cs.brown.edu site <https://cs.brown.edu/~adf/programming_languages.html>`_
* or `my personal copy on sharepoint <www.example.com>`_

The book *Computer Science Illuminated* has an interesting chapter on the
history of computer and programming languages.

* See chapter 1.2 `my personal copy of Compsci Illimunated on sharepoint
  <https://ndusbpos-my.sharepoint.com/:b:/g/personal/richelin_metellus_ndus_edu/EUuysuT-SGxHmAGhINr7KfIBSnrHpXHOeaswDnbXei9cBQ?e=nZg0Z4>`_


******************************************
How is A Programming Language Created
******************************************

Programming Language creation: it takes years of research, 
development, and fine-tuning to create a programming language
that is capable of executing complex operations.

Typical steps of creation:

1. Identify the purpose of the language, its target audience, and the tasks
   it should perform
    
2. Start by **defining a set of rules** that can be used to build algorithm

    * Fundamental principles of computer science, specially algorithm, 
        will influence the set of instuctions to be created (load, store, add)

    * language syntax is developped from set of rules.

        * this will govern the structure of the language.

            * structure determine how code is organized with the language
              (c header file, implementation file)

    * For python, see `Python Language Reference <https://docs.python.org/3/reference/>`_


#. After developing syntax and structure --> Language implementation

    * Implementation involve writing a compiler or interpreter for the language.

        * a :term:`compiler` is a program that translates the high-level code 
          into machine code, while an interpreter executes the code line by line.
        
        * an :term:`interpreter` executes the code line by line.

        .. note::
            Programming languages are created with the help of existing ones, such as C++.
            For example, The Python interpreter is called "CPython" and it's written 
            in the C programming language.

            So programmers create tools for other programmers.
            
            New programming languages are developed to further abstract complex
            details and make the life of other users easier.

            * Thanks to C or other higher level programming, one no longer have to 
              write code in assembly.

.. _standardLibrary:

    * Implementation might also include arranging a standard library for the language

        * The language library is often standardized 
            
            * Ex] ISO/IEC 14882:2011 

                * specifies requirements for implementations of the C++ programming language.
                * clauses 20-33 and annex D standardize implementation of C++ Standard Library

                    * GNU Project implement it and called it libstdc++

                        * see the `GNU C++ Standard Library (libstdc++) <https://gcc.gnu.org/onlinedocs/libstdc++/faq.html#faq.what>`_

        * Other programming language standard library:

            * see `Python Standard Library <https://docs.python.org/3/library/>`
            * see the `GNU C Libary (glibc) <https://www.gnu.org/software/libc/libc.html>`_

                .. seealso::
                    see this `stackoverflow question <https://stackoverflow.com/questions/11372872/what-is-the-role-of-libcglibc-in-our-linux-app>`_
                    on the role of libc(glibc) in a linux app and
                    what the difference between libc and glibc.

                    this stackoverlow made a very nice distinction and you can
                    also type ``man libc`` on a linux shell to get right info
                    and distinction.

                    .. note::
                        
                        * glibc (GNU C Libary)
                            
                            * implement both the C standard library (e.g, 
                              "standard C functions") POSIX functions (getpid())
                              as a wrapper for system calls
                            
                            * glibc isn't a single .so (dynamic library) file -- there are a bunch,
                              but libc and libm (implements math function) are 
                              the most commonly-used two. 
                              All of the static and dynamic libraries are stored in /lib.

                        * libc is a generic term used to refer to all C standard 
                          libraries -- there are several. 
                            
                            * glibc is the most commonly used one; 

                                * glibc implement both the C standard library (e.g, 
                                  "standard C functions") POSIX functions (getpid())
                                  as a wrapper for system calls

                            * others include eglibc, uclibc, and  dietlibc.



#. Once the implementation is complete, the language is tested, refined, and 
   improved based on feedback from developers.

********************
Summary
********************

* Programming Lanaguage evolves from 


**********************
References
**********************

* `Blog- How are Computer Programming Language Created? <https://python.plainenglish.io/how-to-create-a-programming-language-9f3c89a30706>`_
.. _[ISO/IEC14882:2011] `C++ Programming Standard <https://www.iso.org/standard/50372.htm>`_