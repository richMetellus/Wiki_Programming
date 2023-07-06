#include "CPP-0000_1_ConstructorExamples.h"
#include <iostream>

namespace tutorial
{
    ConstructorExamples::ConstructorExamples()
    {
    }

    // default destructor
    ConstructorExamples::~ConstructorExamples()
    {
    }

    /**
     * Adapted from Intro to Java 10th ed by Liang Daniel
     * Chapter 9, Listing 9.3
     *
     */
    TV::TV() // explicitly defined default constructor
    {
    }

    void TV::turnOn()
    {
        on = true;
    }

    void TV::turnOff()
    {
        on = false;
    }

    void TV::setChannel(int newChannel)
    {
        if (on && newChannel >= 1 && newChannel <= 120)
            channel = newChannel;
    }

    void TV::setVolume(int newVolumeLevel)
    {
        if (on && newVolumeLevel >= 1 && newVolumeLevel <= 7)
            volumeLevel = newVolumeLevel;
    }

    void TV::channelUp()
    {
        if (on && channel < 120)
            channel++;
    }

    void TV::channelDown()
    {
        if (on && channel > 1)
            channel--;
    }

    void TV::volumeUp()
    {
        if (on && volumeLevel < 7)
            volumeLevel++;
    }

    void TV::volumeDown()
    {
        if (on && volumeLevel > 1)
            volumeLevel--;
    }

    // No definition for Student only declaration.

    void Student::printStudentInfo()
    {   
        std::cout<< "Student name:" << name <<std::endl;
        std::cout<< "Student age:" << age <<std::endl;
        std::cout<< "is the student in a science major?:" << isScienceMajor <<std::endl;
        std::cout<< "Student gender:" << gender <<std::endl;

    }

}