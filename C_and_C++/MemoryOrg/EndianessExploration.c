// based on lesson learned from
// https://www.section.io/engineering-education/what-is-little-endian-and-big-endian/#:~:text=For%20example%2C%20all%20x86_64%20processors,for%20the%20difference%20in%20endianness.
#include <stdio.h>
#include <stdint.h>

int main()
{
    printf("Exploring how things are stored in memory\n");
    printf("==========================================\n\n");
    //0x9abcdef0 to binary: 10011010101111001101111011110000
    //  * 2's complement in decimal: -1698898192
    //  * decimal: unsigned: (9ABCDEF0)₁₆ = (9 × 16⁷) + (10 × 16⁶) + (11 × 16⁵) + 
    //             (12 × 16⁴) + (13 × 16³) + (14 × 16²) + (15 × 16¹) + (0 × 16⁰) = (2596069104)₁₀
    
    printf("8-byte integer storage\nint a[] = {0x12345678, 0x9abcdef0}; \n");
    int a[] = {0x12345678, 0x9abcdef0}; // 4-byte (32 bit word) each to create
                                        // an 8-byte value of 0x123456789abcdef0
    printf("Memory Address of a[0]: %#.8x(hex), %u(dec) content: %d \n", &a[0], &a[0], a[0]);
    printf("Memory Address of a[1]: %X(hex), %u(dec) content: %d \n", &a[1], &a[1], a[1]);
    // no bound check in c
    printf("No Out of bound memory check \n");
    printf("Memory Address of a[2]: %X(hex), %u(dec); content: %d \n", &a[2], &a[2], a[2]);


    printf("\nint16_t arr2[] = {0x1234, 0x9abcd};  \n");
    int16_t arr2[] = {0x1234, 0x9abcd}; 
    printf("Memory Address of arr2[0]: %#.8x(hex), %u(dec), content:%d \n", &arr2[0], &arr2[0], arr2[0]);
    printf("Memory Address of arr2[1]: %X(hex), %u(dec). content: %d \n", &arr2[1], &arr2[1], arr2[1]);
    // no bound check in c
    printf("No Out of bound memory check \n");
    printf("Memory Address of arr2[2]: %X(hex), %u(dec). Content: %d\n", &arr2[2], &arr2[2], arr2[2]);


    // Exploring char memory storage in little endian
    printf("\nExploring character memory storage: \nchar s[] = {0x12, 0x34,\
    0x56, 0x78, 0x9a, 0xbc, 0xde, 0xf0};\n");
    char s[] = {0x12, 0x34, 0x56, 0x78, 0x9a, 0xbc, 0xde, 0xf0}; // 1 byte = 8 bits
    printf("Memory Address of s[0]: %#.8X(hex), %u(dec) content: %c \n", &s[0], &s[0], s[0]);
    printf("Memory Address of s[1]: %#.8X(hex), %u(dec) content: %c \n", &s[1], &s[1], s[1]);
    printf("Memory Address of s[2]: %#.8X(hex), %u(dec) content: %c \n", &s[2], &s[2], s[2]);
    printf("Memory Address of s[7]: %#.8X(hex), %u(dec) content: %c \n", &s[7], &s[7], s[7]);
    printf("No Out of bound memory check \n");
    printf("Memory Address of s[8]: %#.8X(hex), %u(dec) content: %d \n", &s[8], &s[8], s[8]);
    printf("Memory Address of s[9]: %#.8X(hex), %u(dec) content: %d \n", &s[9], &s[9], s[9]);

    return 0;
}

/*
Example of Output ignoring Warning

Exploring how things are stored in memory
==========================================

8-byte integer storage
int a[] = {0x12345678, 0x9abcdef0}; 
Memory Address of a[0]: 0x36598a38(hex), 911837752(dec) content: 305419896 
Memory Address of a[1]: 36598A3C(hex), 911837756(dec) content: -1698898192 
No Out of bound memory check 
Memory Address of a[2]: 36598A40(hex), 911837760(dec); content: 0 

int16_t arr2[] = {0x1234, 0x9abcd};  
Memory Address of arr2[0]: 0x36598a34(hex), 911837748(dec), content:4660 
Memory Address of arr2[1]: 36598A36(hex), 911837750(dec). content: -21555 
No Out of bound memory check 
Memory Address of arr2[2]: 36598A38(hex), 911837752(dec). Content: 22136

Exploring character memory storage: 
char s[] = {0x12, 0x34,    0x56, 0x78, 0x9a, 0xbc, 0xde, 0xf0};
Memory Address of s[0]: 0X36598A40(hex), 911837760(dec) content:  
Memory Address of s[1]: 0X36598A41(hex), 911837761(dec) content: 4 
Memory Address of s[2]: 0X36598A42(hex), 911837762(dec) content: V 
Memory Address of s[7]: 0X36598A47(hex), 911837767(dec) content: � 
No Out of bound memory check 
Memory Address of s[8]: 0X36598A48(hex), 911837768(dec) content: 0 
Memory Address of s[9]: 0X36598A49(hex), 911837769(dec) content: -127 


...Program finished with exit code 0
Press ENTER to exit console.

*/