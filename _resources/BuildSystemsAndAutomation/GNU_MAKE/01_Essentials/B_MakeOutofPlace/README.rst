#########################
Makefile - Part 2
#########################

In this particlar Makefile

.. include:: ./Makefile 


The default target is ``all`` so if you call *make* on the command line without
option, this target will be the one that is called.

    .. code-block:: text 
    
        all: $(BUILD_DIR)/executable
    	    @echo "Finished!"

* the ``$(BUILD_DIR)/executable`` Pre-requisites or dependencies.

    * ``$(BUILD_DIR)`` is the a variable expansion.
    * in order for the recipe command ``@echo ...`` to be executed the dependencies
      have to be created or up-to-date.
    
* so this code block is saying some form file inside the ``build/`` with the name
  ``executable`` have to exist

    * that ``build`` directory is created by make due to this line
      ``$(shell mkdir -p $(BUILD_DIR))

* But *make* doesn't know how to make the executable dependency, so you have to create a 
  recipe for it.
    
    .. code-block:: c 
        $(BUILD_DIR)/executable: $(OBJ)
	        $(CC) $(CFLAGS) $^ -o $@

    * the make "rule" illustrate above, have a macro expansion as the dependency. ``OBJ``. So
      What is this ``OBJ``

        * ``OBJ`` is list of space-separated strings. the strings are file name object file that
          need to exist.

    
            * So we're saying this list has to exist in order to create this executable.

              * the explanation of the creation of this pre-requisite is explained below
                :ref:`recursive object file creation <recursiveObjectFileCreation>`

        * the recipe

            * the ``$^`` evaluates to *for all the pre-requisites*

            * so this is saying so the pre-requisites are going to be input files, 
              then we're going to create an output (-o option) file with the the name
              that match the target which in this case is ``(BUILD_DIR)/executable``


.. _recursiveObjectFileCreation:

So how do we create these object files:

* we provide another make "rule" that have this recipe 
    
    .. code-block:: c 

        $(BUILD_DIR)/%.o : %.c $(HEADER)
	        $(CC) $(CFLAGS) -I./ -c $< -o $@

* let's break this target rule down:

    * this made use of target pattern, and is responsible for compiling C 
      source files into object files.
      
      * This is some kind of recursive rules for all object files

      * so we say in that directory ``build``/, we use the ``%`` to represent the
        basename of any file/

          * ``%.o`` matches any object file name
      
    * The dependencies are 

        * `%.c`, which means that the corresponding C source file must exist. 
        * Additionally, `$(HEADER)` represents the header files that the C source 
          file depends on.

        * so if you change any of the file listed in the ``HEADER`` variable, this 
          will force all the c file to recompile and form the object file
    
    * The recipe
        
        * the recipe use make predefine variable $(CC) which will expand to default values
          ``cc`` which correspond to gcc.
            
            .. code-block:: c 

               rmetellus@UbuntuZephyrVM:~/Workspace/Repos/InternalRepos/GNU_Make_Tutorials(main)$ cc --version
               cc (Ubuntu 11.3.0-1ubuntu1~22.04.1) 11.3.0
               Copyright (C) 2021 Free Software Foundation, Inc.
               This is free software; see the source for copying conditions.  There is NO
               warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
               
        * the pre-defined varialbe CFLAGS will expand to default options set by the compiler
          for either the version of the language or some other compilation optimization.
        
        * the we set the include path `-I` followed by the path to be include without any space in
          between the -I and the path directory.
        * we provide the option ``-c`` to compile
        * the ``$<`` evaluates  the first pre-requisite as the input, which in 
          case the input will be the c-source file that was match with this 
          ``%.c`` pattern
        * the ``-o`` is the compiler output option
        * the ``$@`` evaluates the target that match the pattern ``(BUILD_DIR)/%.o`` 
          (build/nameOfTheFile.o)

          * this will recurse for every .c and .o combination.

    * After this stage, all the object files that are listed in the Makefile 
      through this variable ``OBJ := $(BUILD_DIR)/main.o $(BUILD_DIR)/random_num_generator.o``
      will be created, the pre-requisite ``$(OBJ)`` for the target ``$(BUILD_DIR)/executable`` 
      in ``$(BUILD_DIR)/executable: $(OBJ)`` will be met.





*******************
References
*******************


* https://www.youtube.com/watch?v=FkqQpBqkSns
* chatGPT response
* Stackoverflow querry