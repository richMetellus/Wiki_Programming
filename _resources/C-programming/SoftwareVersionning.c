/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

#define TOSTRING_HELPER(X) #X
#define TOSTRING(X)  TOSTRING_HELPER(X)

#define   FW_VER_MAJOR                1                   
#define   FW_VER_MINOR                0
#define   FW_BUILD_NO                 1
#define   FW_VER_REVISION             0
/* 32-bit representation of the sw version */
#define FW_APP_VERSION ((FW_VER_MAJOR << 24) +  \
                        (FW_VER_MINOR << 16) +  \
                        (FW_BUILD_NO << 8)   + \
                        (FW_VER_REVISION))

#define   FW_VERSION_MSG    TOSTRING(FW_VER_MAJOR) "." TOSTRING(FW_VER_MINOR) "." \
                            TOSTRING(FW_BUILD_NO) "."  TOSTRING(FW_VER_REVISION)

int main()
{
    printf("FW_VERSION_MSG: %s\n", FW_VERSION_MSG);
    printf("FW_APP_VERSION: %d (%#.8x)", FW_APP_VERSION, FW_APP_VERSION);

    return 0;
}

/**
 * Output
 * =========
 * 
 * FW_VERSION_MSG: 1.0.1.0
 * FW_APP_VERSION: 16777472 (0x01000100)
 * 
 * 
*/

/**
 * Testing overflow if require more than 8 bits (higher than 255) to encode part of the sw version
 * 
 * if software version is 1.0.0.260, then output is:
 * 
 * FW_VERSION_MSG: 1.0.0.260
 * FW_APP_VERSION: 16777476 (0x01000104)
 * 
 * Explanation:
 * 
 * 1) 0x01000104 = 0b0000 0001 0000 0000 0000 0001 0000 0100
 * 2) 260 in binary
 *  (260)_10 = 0b0001 0000 0100
 * 
*/