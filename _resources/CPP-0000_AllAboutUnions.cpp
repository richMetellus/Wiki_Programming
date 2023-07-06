#include <iostream>

using namespace std;

union mixed
{
    char c;
    float f;
    int i;
};

int main(void)
{
    union mixed x;
    
    x.c = 'K';
    printf ("x.c Character = %c\n", x.c);
    
    // To store a floating-point value in x,the notation x.f
    x.f = 786.3869;
    printf ("x.f value = %f\n", x.f);
    printf ("x.f as x.i  value = %d\n", x.i);
    cout <<"x.f as x.i  value  =" << x.i << endl;
    printf ("x.f as x.c  value = %c\n", x.c);
    
    union mixed y = { .f = 123.456 };
    printf ("y.f value = %f\n", y.f);

    return 0;
}

/* 
Example output: https://www.onlinegdb.com/online_c++_compiler

x.c Character = K
x.f value = 786.386902
x.f as x.i  value = 1145346243
x.f as x.i  value  =1145346243
x.f as x.c  value = �
y.f value = 123.456001

*/