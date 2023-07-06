#define FOOBAR "42ca"
#define BARTAB 128
#define PASTE(a, b) a ## b // this replace ## with the arguments thus concat a and b so -> ab
                            // https://stackoverflow.com/questions/45375238/c-preprocessor-macro-expansion
#include <stdio.h>
#define BIT(n)  (1UL << (n))   // set bit at position n to 1. this is 1*2^n
#include <stdint.h> 


int main()
{
    printf("Hello World\n");
    printf("%lu bytes\n", sizeof(PASTE(FOO, BAR)));
    printf("%lu bytes\n", sizeof(PASTE(BAR, TAB)));
    printf("size of literal 1 using lu; %lu bytes\n", sizeof(1UL));

    uint32_t my_number = BIT(3);
    
    printf("my_number: %d \n", my_number);

    return 0;
}

/*
--------- Output -----------------

Hello World
5 bytes
4 bytes
size of literal 1 using lUL; 8 bytes
my_number: 8 

...Program finished with exit code 0
Press ENTER to exit console.

*/
