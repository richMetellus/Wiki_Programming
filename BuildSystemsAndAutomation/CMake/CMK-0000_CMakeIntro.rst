.. _CMakeOverview:

##################################
CMake | A comprehensive Guide
##################################


**********
Intro
**********

What is CMake?


CMake 

* is a general meta-build system.
* is an open-source build system generator and build management tool that 
  allows developers to specify build configurations for a wide variety of 
  platforms and build environments.

    .. drawio-image:: ./_images/src/cmake.drawio 

* CMake is **NOT** a build system itself; it generates another system's build files.

    * Originally designed as a generator for various dialect of ``Makefile``
      CMake runs on most platforms, and can generate project files 
      in many formats, including ninja (use ``-GNinja``).

* CMake uses a CMakeLists.txt file, which describes the build process, to 
   generate platform-specific build scripts, such as Makefiles or Visual 
   Studio project files

    * This approach allows developers to write build scripts once and generate 
      multiple build systems, making it easier to manage and maintain complex 
      software projects.
    
    * The project configuration parameters (key-value pairs) such as the locations 
      of compilers, tools, and dependencies can be viewed or edited by the user 
      by running cmake-gui
      or ccmake tools. 


* CMake can be used to build project in many different programming languages now,
  not just c++. This include Python, Java, Fortran, C# (added in 3.8), Swift 
  and many more.
    
    * You can see the supported languages by going to the `CMake documentation
      -> cmake-commands -> project section <https://cmake.org/cmake/help/latest/command/project.html>`_

CMake Lessons:

* :ref:`Lesson 1: Hello World | No Headers <CMakeLesson1>`

*************
References
*************