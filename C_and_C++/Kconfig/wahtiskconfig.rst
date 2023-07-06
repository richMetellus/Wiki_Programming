########################
Kconfig
########################


Kconfig 

* is an alternative to the CMake config system.
* It manages a unified configuration separately from the main source code that 
  can be used with the build system and source code.

    * It is the best-in-class configuration management tool that exists for 
      embedded C code, period.

* It allows dependencies to be defined between different config options. 

The Kconfig Language

* Allows you to create configuration files that describes a series of menu entries.

    * this will from a configuration database that is a collection of configuration
      options organized in a tree structure.

* using the configuration options, one can include the dependencies to include as
  part of the build.


Kconfig parser:

* in Zephyr, there is a python script Kconfiglib.py under ``zephyr/scripts/Kconfig`` folder
    
    * This script is not zephyr-specific and can be used with the Linux kernel

**************
References
**************

* 