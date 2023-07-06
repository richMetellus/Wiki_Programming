#ifndef CONSTRUCTOREXAMPLES_H
#define CONSTRUCTOREXAMPLES_H

#include <string>
namespace tutorial
{
    class ConstructorExamples
    {

        
    public: // Data members
        static int numberofClasses;

       
    public:  // methods
        ConstructorExamples();
        // destructor
         ~ConstructorExamples();
    }; // <--- always end the class  with a ; after the curly brace

    /**
     * Adapted from Intro to Java 10th ed by Liang Daniel
     * Chapter 9, Listing 9.3
     *
     */
    class TV
    {
        // no specified access modifiers so they will be private by default.
        // All private
        // The default class members’ access class is private.
        // The default struct or union members’ access class is public
        int channel = 1;     // Default channel is 1
        int volumeLevel = 1; // Default volume level is 1
        bool on = false;     // TV is off

    public: // methods

        TV();
        void turnOn();
        void turnOff();
        void setChannel(int newChannel);
        void setVolume(int newVolumeLevel);
        void channelUp();
        void channelDown();
        void volumeUp();
        void volumeDown();
    }; // <--- always end the class  with a ; after the curly brace just like a struct


    // ==========================================================================================
    //          Another Example
    // ==========================================================================================

    // [StudentClassSectionStart]
    class Student
    {
        std::string name;            // name has the default value "" with a size 0 as the standard library will call the empty string constructor
        int age;                // unlike Java where age has the default value 0, C++ it is undefined value (garbage value).
        bool isScienceMajor; // The default value of boolean data type in Java is false, 
                             // whereas in C++, it has no default value and contains garbage value (only in case of global variables, 
                             // it will have default value as false.) https://www.geeksforgeeks.org/comparison-boolean-data-type-c-java/
        char gender;            // There is no default value, it will print garbage data

        // no constructor. C++ compiler will make a default one at run-time.

    public:
        void printStudentInfo();
    };
    // [StudentClassSectionEnd]

}

#endif