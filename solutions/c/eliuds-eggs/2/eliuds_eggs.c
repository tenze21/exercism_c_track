#include "eliuds_eggs.h"
unsigned int egg_count(unsigned int decimal)
{
    /*using kernighan's algorithm to count the 1 bits(set bits) in binary representation of bits*/
    int eggs = 0;
    /*
        clear out the rightmost set bit one by one until decimal becomes 0.
    */
    while (decimal)
    {
        eggs++;
        /*
            example: 0111(7) & 0110(6)= 0110(6), 0110(6) & 0101(5)= 0100(4), 0100(4) & 0011(3) = 0000
        */
        decimal &= decimal - 1;
    }
    return eggs;
}
