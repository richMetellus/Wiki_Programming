public class ConstructorExamples {

    public static int numberofClasses;

    public ConstructorExamples() { // explicitly defined default constructor
    }
}

/**
 * Adapted from Intro to Java 10th ed by Liang Daniel
 * Chapter 9, Listing 9.3
 * 
 */
class TV {
    int channel = 1; // Default channel is 1
    int volumeLevel = 1; // Default volume level is 1
    boolean on = false; // TV is off

    public TV() { // explicitly defined default constructor
    }

    public void turnOn() {
        on = true;
    }

    public void turnOff() {
        on = false;
    }

    public void setChannel(int newChannel) {
        if (on && newChannel >= 1 && newChannel <= 120)
            channel = newChannel;
    }

    public void setVolume(int newVolumeLevel) {
        if (on && newVolumeLevel >= 1 && newVolumeLevel <= 7)
            volumeLevel = newVolumeLevel;
    }

    public void channelUp() {
        if (on && channel < 120)
            channel++;
    }

    public void channelDown() {
        if (on && channel > 1)
            channel--;
    }

    public void volumeUp() {
        if (on && volumeLevel < 7)
            volumeLevel++;
    }

    public void volumeDown() {
        if (on && volumeLevel > 1)
            volumeLevel--;
    }
}

// [StudentClassSectionStart]
class Student { 
    String name; // name has the default value null 
    int age; // age has the default value 0 
    boolean isScienceMajor; // isScienceMajor has default value false 
    char gender; // gender has default value '\u0000'

    // no constructor. Java compiler will make a default one at run-time.
}
// [StudentClassSectionEnd]