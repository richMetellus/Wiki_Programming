#include "random_num_generator.h"
#include <stdlib.h>

int getRandomNumber(unsigned int const seed)
{
    srand(seed);
    return rand();
}

int getMaxRandomNumber()
{
    return RAND_MAX;
}